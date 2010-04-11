#include "Action.h"
#include "DescriptorElements.h"
#include "ActionsMenu.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
//#include "LoadingForm.h"
#include "ErrorForm.h"
#include "soapMobiBindingProxy.h"
#include "ImageConversion.h"
#include "MobiState.h"
#include "Patient.h"
#include "PathInfo.h"
#include "f32file.h"
#include "aknutils.h"
#include "BAUTILS.H"
#include "APGCLI.H"
#include "APMSTD.H"
#include "ImageReader.h"
#include <QTextEdit>
#include <QRadioButton>
#include <QTextStream>
#include <QPalette>
#include <QPixmap>
#include <QBuffer>
#include <QDateTime>
#include <QByteArray>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>

Action::Action(DescriptorHandler * actionDescriptor_in, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	actionDescriptor = actionDescriptor_in;
	
	ID = actionDescriptor->getActionId();
	
	/* inizialize the footer references */
	footer = new ChangePatientFooter();
	
	/* start user interface adds */
	/* wizard navigation buttons */
	
	QLabel *visitsIcon = new QLabel(this);
	visitsIcon->setPixmap(QPixmap(":/icons/visitsIcon.png"));
	ButtonLabel *quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButton.png"));
	
	nextButton = new ButtonLabel(QPixmap(":/icons/forwardButton.png"), QPixmap(":/icons/forwardButton.png"), this);
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButton.png"), this);
	//backButton->setEnabled(false);
	
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(backButton, SIGNAL(released()), this, SLOT(preStep()));
	connect(nextButton, SIGNAL(released()), this, SLOT(nextStep()));
	
	/* layout managers */
	
	QHBoxLayout *headerLayout = new QHBoxLayout();
	
	mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	stepsLayout = new QStackedLayout();
	stepsLayout->setContentsMargins(0,0,0,0);
	buttonsLayout = new QHBoxLayout();
	
	//buttonsLayout->addWidget(closeButton);
	buttonsLayout->addSpacing(13);
	buttonsLayout->addWidget(backButton);
	buttonsLayout->addStretch();
	buttonsLayout->addWidget(nextButton);
	buttonsLayout->addSpacing(13);

	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(visitsIcon);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	mainLayout->addLayout(headerLayout);
	mainLayout->addLayout(stepsLayout);
	mainLayout->addLayout(buttonsLayout);
	mainLayout->addWidget(footer);
	
	/* Generate action steps */
	int stepsQty = actionDescriptor->getStepsQty();
	
	GenericStep * step;
	for(int i=0; i < stepsQty; i++){
		step = createStep(i);
		if(step != 0)
			steps.push_back(step);
		stepsLayout->addWidget(step);
	}
	
	/* set the main window layout */
	setLayout(mainLayout);
	
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
	
	/* create the loading image */
	loadingImage = new QLabel(this);
	loadingImage->setPixmap(QPixmap(":/icons/loadingBg.png"));
	loadingImage->setFixedSize(360, 640);
	loadingImage->setVisible(false);
}

/* create the stepNumber-th step */
GenericStep* Action::createStep(int stepNumber){
	if(actionDescriptor != 0){
		int elementsQty = actionDescriptor->getStepChildsQty(stepNumber);
		
		/* construct the vector of controls */
		vector<StepGenericElement*> elements;
		StepGenericElement * element;
		for(int i=0; i<elementsQty; i++){
			element = actionDescriptor->getStepChild(stepNumber , i);
			elements.push_back(element);
		}
		/* check if the step is an input step */
		/* moved inside GenericStep constructor */
		//bool isInput = false;
		//if(actionDescriptor->getStepType(stepNumber) == "in")
		//	isInput = true;
		
		/* create a new step */
		return new GenericStep(actionDescriptor->getStepType(stepNumber), actionDescriptor->getStepID(stepNumber), elements, this, actionDescriptor);
	}
	
	//TODO: handle this situation using an exception
	return 0;
}

/*
 * This method save the current state of a step. For now it only works with
 * the inputText and radio button elements, because images and recordings are
 * not yet implemented.
 */
void Action::saveStep(GenericStep * step_in){
	/* for each input element in the step */
	for(int i=0; step_in->getInputElement(i)!= 0; i++){
		QWidget * inputWidg = step_in->getInputElement(i);
		
		/* if it's a textbox */
		QTextEdit * inputText = dynamic_cast<QTextEdit*>(inputWidg);
		
		/* if it's a radiobutton */
		QRadioButton * radioButton = dynamic_cast<QRadioButton*>(inputWidg);
		
		/* if it's an IMAGE TODO */
		/* 
		 * TODO: images and recordings save. 
		 * 		HINT:
		 * 			Use something like
		 * 				Q<what you used to render image> * image = dynamic_cast<...*>(inputWidg);
		 * 				if(image != 0){
		 * 					string base64image = <convert the image in base 64>
		 *					actionDescriptor->setStepChildContent(step_in->getID(),image->objectName(),base64image);
		 *				}
		 *		Whortless to say that this step require that the image objectName is set to the ID of the corresponding 
		 *		element in the configuration file.
		 */
		
		
		if(inputText != 0){ // it is a text box so save the value in the xml output file
			actionDescriptor->setStepChildContent(step_in->getID(), inputText->objectName(), inputText->toPlainText());
		}
		else if(radioButton != 0){ // it's a radio button so set the selection in the xml output file
			QString isSelected = "false"; 
			if(radioButton->isChecked())
				isSelected = "true";
			actionDescriptor->setStepChildAttribute(step_in->getID(),radioButton->objectName(), QString("selected"), isSelected);
		}
		/* else if it's an image... save the image on the server? */
	}
	//actionDescriptor->saveToFS();
}

/* Next button slot */
void Action::nextStep()
{
	/* If the action accepts inputs, then save the current state of the step */
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);

	/* increment the stacked layout index */
	stepsLayout->setCurrentIndex(stepsLayout->currentIndex() + 1);
	
	/* if current step is the last step, the next step is the Finish button */
	if (this->isLastStep())
	{
		//nextButton->setEnabled(false);
		//nextButton->setText("Finish");
		connect(nextButton, SIGNAL(released()), this, SLOT(finishButtonSlot()));
		disconnect(nextButton, SIGNAL(released()), this, SLOT(nextStep()));
	}
	
	/* if current step isn't the first step, enable the "back" button */
	if (stepsLayout->currentIndex() == 1)
	{
		backButton->setEnabled(true);
	}
}

/* close button slot (not used in this version)
bool Action::close(){
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);
	return QWidget::close();
}

 back button slot */
void Action::preStep()
{
	/* If the action accepts inputs, then save the current state of the step */
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);
	
	/* decrement the stacked layout index */
	stepsLayout->setCurrentIndex(stepsLayout->currentIndex() - 1);
	
	/* if current step is the first, disable "back" button */
	if (stepsLayout->currentIndex() == 0)
	{
		backButton->setEnabled(false);
	}
	
	/* if current step isn't the last step, enable "next" button */
	if (stepsLayout->currentIndex() == stepsLayout->count() - 2)
	{
		//nextButton->setEnabled(true);
		nextButton->setText("Next");
		connect(nextButton, SIGNAL(clicked()), this, SLOT(nextStep()));
		disconnect(nextButton, SIGNAL(clicked()), this, SLOT(finishButtonStep()));
		
	}
}


/* Action destructor implementation */
Action::~Action()
{
	//TODO: deallocation!
}

/* invoked when the finish button is pressed */
void Action::finishButtonSlot()
{
	/* show the loading image */
	loadingImage->setVisible(true);
	this->repaint();
	
	/* If the last step accepts inputs, then save the current state of the step */
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);
	
	/* show the "loading form" TODO: FIX!!
	LoadingForm *loadingForm = new LoadingForm();
	loadingForm->setAttribute(Qt::WA_DeleteOnClose, true);
	loadingForm->showFullScreen();
	*/
	
	/* get the root path */
	TFileName rootPath = PathInfo::PhoneMemoryRootPath();
	
	/* get ALL the images and put them in a vector (not in this version)
	/* create the vector for the images 
	std::vector<char*> imagesVector;
	
	TFileName fileToLoad;
	fileToLoad.Copy(path);
	fileToLoad.Append(_L("1.jpg"));
	QString QfileToLoad = QString("c:/data/1.jpg");
	int i = 1;
	/* check if 1.jpg exists 
	TBool fileToLoadExists = BaflUtils::FileExists( CEikonEnv::Static()->FsSession() , fileToLoad );
	
	while(fileToLoadExists)
	{
		/* add images to vector 
		QPixmap image = QPixmap(QfileToLoad);
		QByteArray byteArray;
		QBuffer buffer(&byteArray);
		buffer.open(QIODevice::WriteOnly);
		image.save(&buffer, "JPG");
		QByteArray base64ba = byteArray.toBase64();
		char* base64image = base64ba.data();
		imagesVector.push_back(base64image);
		
		/* create next file name to load 
		i++;
		fileToLoad.Copy(path);
		fileToLoad.AppendNum(i);
		fileToLoad.Append(_L(".jpg"));
		QfileToLoad = QString("c:/data/" + QString::number(i) + ".jpg");
		
		/* check if the next file to load exists 
		fileToLoadExists = BaflUtils::FileExists( CEikonEnv::Static()->FsSession() , fileToLoad );
	}
	
	
	/* remove ALL the images saved in the local fs 
	TFileName fileToDelete;
	fileToDelete.Copy(path);
	fileToDelete.Append(_L("1.jpg"));
	int j = 1;
	
	/* check if 1.jpg exists
	TBool fileToRemoveExists = BaflUtils::FileExists( CEikonEnv::Static()->FsSession() , fileToDelete );
	while(fileToRemoveExists)
	{
		/* delete file 
		CEikonEnv::Static()->FsSession().Delete(fileToDelete);
		
		/* create next file name to erase 
		j++;
		fileToDelete.Copy(path);
		fileToDelete.AppendNum(j);
		fileToDelete.Append(_L(".jpg"));
		/* check if the next file to erase exists 
		fileToRemoveExists = BaflUtils::FileExists( CEikonEnv::Static()->FsSession() , fileToDelete );
	}
	*/
	
	/* get the xml file as a string (char*) */
	QDomDocument* xmlDoc = actionDescriptor->getXmlDocument();
	QString xmlDocString = xmlDoc->toString();
	
	/* prepare the method param */
	QByteArray patientIdByteArray = MobiState::getInstance()->getCurrentPatient()->patintId.toLocal8Bit();
	char *patientId = patientIdByteArray.data();
	
	QByteArray dataByteArray = xmlDocString.toLocal8Bit();
	char *data = dataByteArray.data();
	
	QByteArray actionIdByteArray = ID.toLocal8Bit();
	char *actionId = actionIdByteArray.data();
	
	/* timestamp param */
	QString QTimeStampString = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss-zzz");
	QByteArray timeStampByteArray = QTimeStampString.toLocal8Bit();
	char *timeStamp = timeStampByteArray.data();
	
	/* create the server object */
	MobiBinding server;
	
	/* send xml file */
	int err = server.ns1__saveData(patientId, actionId, data, timeStamp);
	if (err != SOAP_OK)
	{
		/* if error occurs, show the error form */
		ErrorForm *error = new ErrorForm(err);
		error->setAttribute(Qt::WA_DeleteOnClose, true);
		error->showFullScreen();
	}
	
	/* if image exist, send it to server */
	TFileName imageToSave;
	imageToSave.Copy(rootPath);
	imageToSave.Append(_L("1.jpg"));
	bool imageExists = BaflUtils::FileExists(CEikonEnv::Static()->FsSession(), imageToSave);
	if (imageExists)
	{
		/* load the image as base64 string (char*) */
		QPixmap image = QPixmap("c:/data/1.jpg");
		QByteArray byteArray;
		QBuffer buffer(&byteArray);
		buffer.open(QIODevice::WriteOnly);
		image.save(&buffer, "JPG");
		QByteArray base64ba = byteArray.toBase64();
		char* base64Image = base64ba.data();
		
		/* send image */
		int err2 = server.ns1__saveImage(patientId, actionId, base64Image, timeStamp);
		if (err2 != SOAP_OK)
		{
			/* if error occurs, show the error form */
			ErrorForm *error = new ErrorForm(err);
			error->setAttribute(Qt::WA_DeleteOnClose, true);
			error->showFullScreen();
		}
		
		/* remove the local image (c:/1.jpg) */
		CEikonEnv::Static()->FsSession().Delete(imageToSave);
	}
	
	/* server operations finisched, close loading form */
	//loadingForm->close();

	/* save the xml to the local fs (test only) */
	RFile file;
	TFileName fileToSave;
	fileToSave.Copy(rootPath);
	//fileToSave.Append(_L("save.xml"));
	
	TBool fileExists = ETrue;
	for (TInt i=1 ; i<100 ; i++) // TODO: fix i<100!!
	{
		fileToSave.Copy(rootPath);
		fileToSave.AppendNum(i);
		fileToSave.Append(_L(".xml"));
		fileExists = BaflUtils::FileExists(CEikonEnv::Static()->FsSession(),fileToSave);
		if (!fileExists)
		{
			break;
		}
	}
	TInt err2 = file.Create(CEikonEnv::Static()->FsSession(),fileToSave,EFileWrite);
	if (!err2)
	{
		QByteArray ba = xmlDocString.toLocal8Bit();
		TPtrC8 ptr(reinterpret_cast<const TUint8*>(ba.constData()),(ba.length()));
		file.Write(ptr);
		file.Close();
	}
	else
	{
		// ERROR HANDLING
	}
	
	/* close the wizard */
	this->close();
}


/* return the action descriptorHandler to the step (yesno step) */
DescriptorHandler* Action::getActionDescriptor()
{
	return actionDescriptor;
}

/* return true if the current step is the last step */
bool Action::isLastStep()
{
	return (stepsLayout->currentIndex() == stepsLayout->count() - 1);
}

void Action::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap(":/icons/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location
/*
	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();

	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));*/
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);	
}

