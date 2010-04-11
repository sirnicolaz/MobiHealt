#include "GenericStep.h"
#include "DescriptorHandler.h"
#include "CameraWidget.h"
#include "buttonlabel.h"
#include "Action.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QTextEdit>
#include <QRadioButton>
#include <QButtonGroup>

//Only for test
#include <iostream>
using namespace std;


GenericStep::GenericStep( QString isInput_in, QString ID_in, vector<StepGenericElement*> elements_in, QWidget *parent, DescriptorHandler* descriptor)
    : QWidget(parent)
{
	ui.setupUi(this);
	this->setContentsMargins(0,0,0,0);
	
	/* the dynamic type of parent is always Action* */
	action = dynamic_cast<Action*>(parent);
	
	/* if the step is not a yes/no step and is not a photo step, check if it's an input step or not*/
	if (isInput_in != "yesno" and isInput_in != "photo")
	{
		if ( isInput_in == "in" )
			inputStep=true;
		else
			inputStep=false;
	}
	/* initialize the descriptorHandler, used for save the answer (in case of yesno step) and the step id */
	this->descriptor = descriptor;
	ID = ID_in; 
	
	/* create the step GUI */
	QVBoxLayout *mainLayout = new QVBoxLayout();
	StepGenericElement *currentElement;
	//Loop through the elements
	for(int i = 0; i < elements_in.size(); i++){
	
		currentElement = elements_in.at(i);
		
		if(currentElement != 0){
			//Check the type of element
			switch( currentElement->getElementName() ){
				case TEXT:
					Text * textElement = dynamic_cast<Text*>(currentElement);
					
					//Generating area where to insert the text
					QScrollArea * scrollArea = new QScrollArea();
					scrollArea->setWidgetResizable(true);
						
					//if(textElement->getWidth() != 0)
						//scrollArea->setFixedWidth(textElement->getWidth());
					//if(textElement->getRows() != 0)
						//scrollArea->setFixedHeight(textElement->getRows());
					
					QLabel *description = new QLabel("<font size=\"36px\" color=\"black\">" + textElement->getContent() + "</font>", this);
					
					description->setFont(QFont("helvetica"));
					
					description->setWordWrap(true);
					description->setAlignment(Qt::AlignJustify);
				
					scrollArea->setWidget(description);
					mainLayout->addWidget(scrollArea);
					break;
					
				case INPUTFIELD:
					
					Input * inputElement = dynamic_cast<Input*>(currentElement);
					
					//Generating a gridlayout where to put both the label and the field
					QGridLayout * inputContainerLayout = new QGridLayout(this);
					QWidget * inputContainer = new QWidget(this);
					
					QLabel * inputLabel = new QLabel("<font size=\"18px\" color=\"#BE0A26\">" + inputElement->getLabel() + "</font>",this);
					inputLabel->setFont(QFont("helvetica"));
					QTextEdit * inputText = new QTextEdit(inputElement->getContent(), this);
					inputText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
					inputText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
					inputText->setStyleSheet("color: black; background-color: white; border: 1px solid gray; border-radius: 10px; font-size: 18px; font-family: helvetica;");
					
					inputText->setObjectName(inputElement->getId());
					inputElements.push_back(inputText);
					
					//if(inputElement->getWidth() != 0)
					//	inputText->setFixedHeight(inputElement->getWidth());
					if(inputElement->getRows() != 0)
						inputText->setFixedHeight(inputElement->getRows() * 40);
					
					switch(inputElement->getPos()){
						case UP:
							inputContainerLayout->addWidget(inputLabel,0,0);
							inputContainerLayout->addWidget(inputText,1,0);
							break;
						case DOWN:
							inputContainerLayout->addWidget(inputLabel,1,0);
							inputContainerLayout->addWidget(inputText,0,0);
							break;
						case LEFT:
							inputContainerLayout->addWidget(inputLabel,0,0);
							inputContainerLayout->addWidget(inputText,0,1);
							break;
						case RIGHT:
							inputContainerLayout->addWidget(inputLabel,0,1);
							inputContainerLayout->addWidget(inputText,0,0);
							break;
						default : break;
							
					}
					inputContainer->setLayout(inputContainerLayout);										
					inputContainerLayout->setSpacing(1);
					mainLayout->addWidget(inputContainer);
					mainLayout->addSpacing(5);
					break;
				case IMAGE:
					/* TODO: Given an Image element, this part of the code should
					 * renderize a box (as big as width and height attributes say)
					 * containing the image. The base64 encoding of the image is given
					 * by the content of the element. Probably the most part of the times
					 * this functionality won't be required. The important thing to do
					 * is to renderize a button to snap the photo.
					 */
					/* get the element object */
					//Image* imageElement = dynamic_cast<Image*>(currentElement);
					
					/* show the text for the image step */
					//QScrollArea * imageScrollArea = new QScrollArea();
					//imageScrollArea->setWidgetResizable(true);
					
					//QLabel *imageText = new QLabel(imageElement->getContent(), this);
					//imageText->setWordWrap(true);
					//imageText->setAlignment(Qt::AlignJustify);
									
					//scrollArea->setWidget(imageText);
					//mainLayout->addWidget(imageScrollArea);
					
					/* show the button to open the viewFinderWidget */
					//QHBoxLayout *viewFinderButtonLayout = new QHBoxLayout();
					//QPushButton *viewFinderButton = new QPushButton("Take Photo", this);
					//viewFinderButtonLayout->addWidget(viewFinderButton);
					//mainLayout->addLayout(viewFinderButtonLayout);
					//connect(viewFinderButton, SIGNAL(clicked()), this, SLOT(showViewFinderWidgetSlot()));
					
					break;
				case RECORDING:
					/* TODO:
					 * The stuff to do is exactly the same then the one of the image. The only 
					 * differenze is that you have to renderize a "record","play","pause" button
					 * to interact with the mobile recorder.
					 */
					break;
				case SELECT:
					Select * selectElement = dynamic_cast<Select*>(currentElement);
						QButtonGroup * radioGroup = new QButtonGroup();
						radioGroup->setExclusive(selectElement->isMutex());
						for(int j = 0; j < selectElement->getOptions().size(); j++){
							Select::Option optionElement = selectElement->getOption(j);
							QRadioButton * option = new QRadioButton(optionElement.getContent(), this);
							option->setStyleSheet("color: black; font-size: 18px; font-family: helvetica;");
							option->setChecked(optionElement.isSelected());
							
							//The object name is eventually used to retrive the object reference
							//(During the saving process).
							//So the ID in the configuration file MUST be unique.
							option->setObjectName(optionElement.getId());
							inputElements.push_back(option);
							radioGroup->addButton(option);
							mainLayout->addWidget(option);
						}
						
						
					break;
				default:
					//TODO: handle exception
					break;
			}
		}
	}
	mainLayout->addStretch();
	/* if the step is a yes/no step add the YES and NO buttons */
	if(isInput_in == "yesno")
	{
		/* Create the buttons layout and add the buttons */
		QHBoxLayout *buttonsLayout = new QHBoxLayout();
		buttonsLayout->setContentsMargins(5,0,5,0);
		ButtonLabel *yesButton = new ButtonLabel(QPixmap(":/icons/yesButton.png"), QPixmap(":/icons/yesButton.png"), this);
		buttonsLayout->addWidget(yesButton);
		buttonsLayout->addStretch();
		ButtonLabel *noButton = new ButtonLabel(QPixmap(":/icons/noButton.png"), QPixmap(":/icons/noButton.png"), this);
		buttonsLayout->addWidget(noButton);
		
		/* connect the buttons to the slots */
		connect(yesButton, SIGNAL(released()), this, SLOT(yesSlot()));
		connect(noButton, SIGNAL(released()), this, SLOT(noSlot()));
		
		mainLayout->addLayout(buttonsLayout);
	}
	
	if (isInput_in == "photo")
	{
		/* create the button to show the viewfinder */
		ButtonLabel *viewFinderButton = new ButtonLabel(QPixmap(":/icons/viewfinderButton.png"), QPixmap(":/icons/viewfinderButton.png"), this);
		//QPushButton *viewFinderButton = new QPushButton("Take Photo", this);
		mainLayout->addWidget(viewFinderButton);
		mainLayout->setAlignment(viewFinderButton, Qt::AlignHCenter);
		connect(viewFinderButton, SIGNAL(released()), this, SLOT(showViewFinderWidgetSlot()));
	}
	
	this->setLayout(mainLayout);
}

/* yes button slot */
void GenericStep::yesSlot()
{
	/* save the answer to the xml file (TODO: NO! SAVE THE ANSWER IN THE ATTRIBUTE!!!!) */
	descriptor->setStepChildContent(ID, 0, "YES");
	
	/* move to the next step */
	/* if it's the last step close the wizard (and save the data in the closeEvent) */
	if (action->isLastStep())
		action->finishButtonSlot(); 
	else
		action->nextStep();
	
}

/* no button slot */
void GenericStep::noSlot()
{
	/* save the answer to the xml file (TODO: NO! SAVE THE ANSWER IN THE ATTRIBUTE!!!!) */
	descriptor->setStepChildContent(ID, 0, "NO");
	
	/* move to the next step */
	/* if it's the last step  */
	if (action->isLastStep())
		action->finishButtonSlot();
	else
		action->nextStep();
}

/* "Scatta la foto" button slot */
void GenericStep::showViewFinderWidgetSlot()
{
	/* create and show the camera widget */
	CameraWidget *cameraViewFinder = new CameraWidget(action);
	cameraViewFinder->setAttribute(Qt::WA_DeleteOnClose, true);
	cameraViewFinder->showFullScreen();
}

QString GenericStep::getID(){
	return ID;
}

bool GenericStep::isInput(){
	return inputStep;
}

QWidget * GenericStep::getInputElement(int pos){
	if(pos<inputElements.size()){
		return inputElements[pos];
	}
	
	//TODO:Handle with exception
	return 0;
}

GenericStep::~GenericStep()
{

}
