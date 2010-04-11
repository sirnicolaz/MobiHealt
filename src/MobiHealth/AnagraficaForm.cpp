#include "AnagraficaForm.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include "PatientMenuForm.h"
#include "MobiState.h"
#include "Patient.h"
#include <QString>
#include <QPalette>
#include <QLabel>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QSize>
#include <QRect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>

AnagraficaForm::AnagraficaForm(QWidget *parent)
: QWidget(0)
{
	this->parent = static_cast<PatientMenuForm*>(parent);
	ui.setupUi(this);
	this->setContentsMargins(0,0,0,0);
	
	/* set the background image */
	setBackgroundImage();
	
	/* create the GUI objects */
	patientIcon = new QLabel(this);
	patientIcon->setPixmap(QPixmap(":/icons/patientIcon.png"));
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"));
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"));
	
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(backButton, SIGNAL(released()), this, SLOT(backButtonSlot()));
	
    nameLabel = new QLabel("NOME", this);
    nameLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    name = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->name, this);
    name->setStyleSheet("color: black; font-family : helvetica;");
    surnameLabel = new QLabel("COGNOME", this);
    surnameLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    surname = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->lastName, this);
    surname->setStyleSheet("color: black; font-family : helvetica;");
    codeLabel = new QLabel("ID PAZIENTE", this);
    codeLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    code = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->patientCode, this);
    code->setStyleSheet("color: black; font-family : helvetica;");
    addressLabel = new QLabel("INDIRIZZO", this);
    addressLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    address = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->address, this);
    address->setStyleSheet("color: black; font-family : helvetica;");
    capLabel = new QLabel("CAP", this);
    capLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    cap = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->cap, this);
    cap->setStyleSheet("color: black; font-family : helvetica;");
    cityLabel = new QLabel("COMUNE", this);
    cityLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    city = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->city, this);
    city->setStyleSheet("color: black; font-family : helvetica;");
    provinceLabel = new QLabel("PROVINCIA", this);
    provinceLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    province = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->province, this);
    province->setStyleSheet("color: black; font-family : helvetica;");
    birthDateLabel = new QLabel("DATA DI NASCITA", this);
    birthDateLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    birthDate = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->birthDate, this);
    birthDate->setStyleSheet("color: black; font-family : helvetica;");
    GPLabel = new QLabel("MEDICO DI BASE", this);
    GPLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    GP = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->GP, this);
    GP->setStyleSheet("color: black; font-family : helvetica;");
    CFLabel = new QLabel("CODICE FISCALE", this);
    CFLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    CF = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->CF, this);
    CF->setStyleSheet("color: black; font-family : helvetica;");
    professionLabel = new QLabel("PROFESSIONE", this);
    professionLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    profession = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->profession);
    profession->setStyleSheet("color: black; font-family : helvetica;");
    birthLocationLabel = new QLabel("LUOGO DI NASCITA", this);
    birthLocationLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    birthLocation = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->birthLocation, this);
    birthLocation->setStyleSheet("color: black; font-family : helvetica;");
    maritalLabel = new QLabel("STATO CONIUGALE", this);
    maritalLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
    marital = new QLabel(MobiState::getInstance()->getCurrentPatient()->anagrafica->marital, this);
    marital->setStyleSheet("color: black; font-family : helvetica;");
    
    /* inizialize the footer references */
    footer = new ChangePatientFooter();
    
    QLabel *headerText = new QLabel(this);
    headerText->setStyleSheet("font-family: arial; font-weight: bold; font-size: 18px;");
    headerText->setText("<font color=\"#622181\">Paziente</font><font color=\"#9C9E9F\"> / </font><font color=\"#0B72B5\">Anagrafica</font>");
        
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(patientIcon);
	headerLayout->addSpacing(3);
	headerLayout->addWidget(headerText);
	headerLayout->setAlignment(headerText, Qt::AlignVCenter);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *scrollLayout = new QVBoxLayout();
	scrollLayout->setContentsMargins(23, 10, 40, 0);
	
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);
	
	/* add the labels to the scrollLayout */
	scrollLayout->setSpacing(1);
	scrollLayout->addWidget(nameLabel);
	QFrame *nameLine = new QFrame(this);
	nameLine->setFixedHeight(2);
	nameLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(nameLine);
	scrollLayout->addWidget(name);
	scrollLayout->addWidget(surnameLabel);
	QFrame *surnameLine = new QFrame(this);
	surnameLine->setFixedHeight(2);
	surnameLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(surnameLine);
	scrollLayout->addWidget(surname);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(codeLabel);
	QFrame *codeLine = new QFrame(this);
	codeLine->setFixedHeight(2);
	codeLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(codeLine);
	scrollLayout->addWidget(code);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(addressLabel);
	QFrame *addressLine = new QFrame(this);
	addressLine->setFixedHeight(2);
	addressLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(addressLine);
	scrollLayout->addWidget(address);
	scrollLayout->addWidget(cityLabel);
	QFrame *cityLine = new QFrame(this);
	cityLine->setFixedHeight(2);
	cityLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(cityLine);
	scrollLayout->addWidget(city);
	scrollLayout->addWidget(provinceLabel);
	QFrame *provinceLine = new QFrame(this);
	provinceLine->setFixedHeight(2);
	provinceLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(provinceLine);
	scrollLayout->addWidget(province);
	scrollLayout->addWidget(capLabel);
	QFrame *capLine = new QFrame(this);
	capLine->setFixedHeight(2);
	capLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(capLine);
	scrollLayout->addWidget(cap);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(CFLabel);
	QFrame *cfLine = new QFrame(this);
	cfLine->setFixedHeight(2);
	cfLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(cfLine);
	scrollLayout->addWidget(CF);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(birthDateLabel);
	QFrame *birthDateLine = new QFrame(this);
	birthDateLine->setFixedHeight(2);
	birthDateLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(birthDateLine);
	scrollLayout->addWidget(birthDate);
	scrollLayout->addWidget(birthLocationLabel);
	QFrame *birthLocationLine = new QFrame(this);
	birthLocationLine->setFixedHeight(2);
	birthLocationLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(birthLocationLine);
	scrollLayout->addWidget(birthLocation);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(professionLabel);
	QFrame *professionLine = new QFrame(this);
	professionLine->setFixedHeight(2);
	professionLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(professionLine);
	scrollLayout->addWidget(profession);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(GPLabel);
	QFrame *gpLine = new QFrame(this);
	gpLine->setFixedHeight(2);
	gpLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(gpLine);
	scrollLayout->addWidget(GP);
	scrollLayout->addSpacing(20);
	scrollLayout->addWidget(maritalLabel);
	QFrame *maritalLine = new QFrame(this);
	maritalLine->setFixedHeight(2);
	maritalLine->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(maritalLine);
	scrollLayout->addWidget(marital);

	QFrame *headerLine = new QFrame(this);
	headerLine->setFixedHeight(2);
	headerLine->setStyleSheet("border-top: 2px solid #CB0133");
	QFrame *scrollLine = new QFrame(this);
	scrollLine->setFixedHeight(2);
	scrollLine->setStyleSheet("border-top: 2px solid #CB0133");
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	QWidget *scrollWidget = new QWidget(this);
	scrollWidget->setContentsMargins(0,0,0,0);
	scrollWidget->setLayout(scrollLayout);
	scrollWidget->setFixedWidth(350);
	//scrollWidget->setContentsMargins(0,0,0,0);
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setFixedHeight(400);
	scrollArea->setContentsMargins(0,10,10,10);
	
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidget(scrollWidget);
	
	mainLayout->addLayout(headerLayout);
	mainLayout->addSpacing(7);
	mainLayout->addWidget(headerLine);
	mainLayout->addWidget(scrollArea);
	mainLayout->addWidget(scrollLine);
	mainLayout->addStretch(3);
	mainLayout->addLayout(backHLayout);
	mainLayout->addStretch(1);
	mainLayout->addWidget(footer);
	
	setLayout(mainLayout);
	
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
}

void AnagraficaForm::backButtonSlot()
{
	/* active the parent widget */
	parent->activateWindow();
	/* close the anagrafica form */
	this->close();
}

void AnagraficaForm::setBackgroundImage()
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

AnagraficaForm::~AnagraficaForm()
{
	
}
