#include "PatientSearchForm.h"
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "buttonlabel.h"
#include "PatientSearchResultForm.h"
#include "LabelWidget.h"
#include "soapMobiBindingProxy.h"
#include "CreditsWidget.h"
#include "ErrorForm.h"
#include "TextBoxWidget.h"
#include "CreditsFooterWidget.h"
#include "MobiState.h"


PatientSearchForm::PatientSearchForm(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	/* set the background image */
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	creditsFooter = new CreditsFooterWidget(this);
	creditsFooter->setMinimumHeight(43);
	creditsFooter->setMaximumHeight(43);
	creditsFooter->setBackgroundImage();
	
	/* create the GUI object */
	LabelWidget *surnameLabel = new LabelWidget("Cognome", this);
	//surnameLabel->setMaximumHeight(30);
	surnameLabel->setBackgroundImage();
	surnameTextBox = new TextBoxWidget(QPixmap(":/icons/textBoxBg.png"));
	
	LabelWidget *nameLabel = new LabelWidget("Nome", this);
	nameLabel->setBackgroundImage();
	nameTextBox = new TextBoxWidget(QPixmap(":/icons/textBoxBg.png"));
	
	LabelWidget *cityLabel = new LabelWidget("Comune di Residenza", this);
	cityLabel->setBackgroundImage();
	cityTextBox = new TextBoxWidget(QPixmap(":/icons/textBoxBg.png"));
	
	LabelWidget *codeLabel = new LabelWidget("Id Paziente", this);
	codeLabel->setBackgroundImage();
	codeTextBox = new TextBoxWidget(QPixmap(":/icons/textBoxLineBg.png"));
	
	searchButton = new ButtonLabel(QPixmap(":/icons/findButton.png"), QPixmap(":/icons/findButtonPushed.png"), this);
	connect(searchButton, SIGNAL(released()), this, SLOT(searchButtonSlot()));
	creditsButton = new ButtonLabel(QPixmap(":/icons/creditsButton.png"), QPixmap(":/icons/creditsButton.png"), this);
	connect(creditsButton, SIGNAL(released()), this, SLOT(creditsButtonSlot()));
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButton.png"), this);
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	personLogo = new QLabel(this);
	personLogo->setPixmap(QPixmap(":/icons/userIcon.png"));
	
	/* layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(personLogo);
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->setSpacing(0);
	vLayout->setContentsMargins(0,0,0,0);
	vLayout->addLayout(headerLayout);
	vLayout->addStretch(5);
	
	vLayout->addWidget(surnameLabel);
	QHBoxLayout *surnameHLayout = new QHBoxLayout();
	surnameHLayout->addWidget(surnameTextBox);
	surnameTextBox->setBackgroundImage();
	vLayout->addLayout(surnameHLayout);
	
	vLayout->addWidget(nameLabel);
	QHBoxLayout *nameHLayout = new QHBoxLayout();
	nameHLayout->addWidget(nameTextBox);
	nameTextBox->setBackgroundImage();
	vLayout->addLayout(nameHLayout);
	
	vLayout->addWidget(cityLabel);
	QHBoxLayout *cityHLayout = new QHBoxLayout();
	cityHLayout->addWidget(cityTextBox);
	cityTextBox->setBackgroundImage();
	vLayout->addLayout(cityHLayout);
	
	vLayout->addWidget(codeLabel);
	QHBoxLayout *codeHLayout = new QHBoxLayout();
	codeHLayout->addWidget(codeTextBox);
	codeTextBox->setBackgroundImage();
	vLayout->addLayout(codeHLayout);
	
	vLayout->addStretch(1);
	vLayout->addWidget(searchButton);
	vLayout->setAlignment(searchButton, Qt::AlignCenter);
	vLayout->addStretch(4);
	vLayout->addWidget(creditsFooter);
	
	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(vLayout);
	mainLayout->setAlignment(Qt::AlignCenter);
	setLayout(mainLayout);
	
	/* connect the patient change signal to the close slot */
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
	
	loadingImage = new QLabel(this);
	loadingImage->setPixmap(QPixmap(":/icons/loadingBg.png"));
	loadingImage->setFixedSize(360, 640);
	loadingImage->setVisible(false);
}

/* credits button slot implementation */
void PatientSearchForm::creditsSlot()
{
	/* create and show the credits widget */
	CreditsWidget *creditsWidget = new CreditsWidget();
	creditsWidget->setAttribute(Qt::WA_DeleteOnClose, true);
	creditsWidget->showFullScreen();
}

void PatientSearchForm::searchButtonSlot()
{
	/* show the "loading form" */
	loadingImage->setVisible(true);
	this->repaint();
	
	QByteArray ba;
	
	/* get the patient info from textboxes */
	QString patientName = nameTextBox->getValue();
	QString patientSurname = surnameTextBox->getValue();
	QString patientCity = cityTextBox->getValue();
	QString patientCode = codeTextBox->getValue();
	
	/* invoke the web method to search patients */
	MobiBinding server;
	ns1__searchPatientResponse responce;
	
	int err = server.ns1__searchPatient(patientName.toLocal8Bit().data(), patientSurname.toLocal8Bit().data(), patientCity.toLocal8Bit().data(), patientCode.toLocal8Bit().data(), responce);
	if(err == SOAP_OK)
	{
		SimplePatientArray *simplePatientArray = responce.searchPatientReturn;
		ns1__SimplePatient **patientArray = simplePatientArray->__ptr;
		int arraySize = simplePatientArray->__size;
	
		/* initialize the field resultsForm creating the PatientSearchResultsForm, passing che SimplePatient array returned */
		resultsForm = new PatientSearchResultForm(patientArray, arraySize, this);
		resultsForm->setAttribute(Qt::WA_DeleteOnClose, true);
		resultsForm->showFullScreen();
	}
	else // web service error!
	{
		ErrorForm *error = new ErrorForm(err);
		error->setAttribute(Qt::WA_DeleteOnClose, true);
		error->showFullScreen();
	}
	/* close the "loading form" */
	loadingImage->setVisible(false);
}

void PatientSearchForm::setBackgroundImage()
{	
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location
/*
	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();

	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));*/
	p.setBrush(QPalette::Background,  pixmap1);
	setPalette(p);
}

PatientSearchForm::~PatientSearchForm()
{
	
}
