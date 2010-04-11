#include "MainMenuForm.h"
#include "buttonlabel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QSize>
#include <QRect>
#include <QDesktopWidget>
#include <QPixmap>
#include <QGridLayout>
#include "ChangePatientFooter.h"
#include "CreditsFooterWidget.h"
#include "PatientSearchForm.h"
#include "PatientMenuForm.h"
#include "ActionsMenu.h"
#include "AccountForm.h"
#include "NotesForm.h"
#include "ActionsMenu.h"
#include "MobiState.h"
#include "MobiHealth.h"
#include "Patient.h"
#include "SelectSearchMenu.h"


MainMenuForm::MainMenuForm(QWidget *parent)
    : QWidget(0)
{
	ui.setupUi(this);
	
	this->parent = static_cast<MobiHealth*>(parent);
	
	this->setContentsMargins(0,0,0,0);
	
	/* set the background image */
	this->setBackgroundImage();
	
	/* create the gui objects */
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	logoutButton = new ButtonLabel(QPixmap(":/icons/logoutButton.png"), QPixmap(":/icons/logoutButtonPushed.png"), this);
	patientButton = new ButtonLabel(QPixmap(":/icons/patientButton.png"), QPixmap(":/icons/patientButtonPushed.png") , this);
	examsButton = new ButtonLabel(QPixmap (":/icons/visitButton.png"), QPixmap(":/icons/visitButtonPushed.png"), this);
	notesButton = new ButtonLabel(QPixmap(":/icons/notesButton.png"), QPixmap(":/icons/notesButtonPushed.png"), this);
	accountButton = new ButtonLabel(QPixmap(":/icons/accountButton.png"), QPixmap(":/icons/accountButtonPushed.png") , this);
	
	/* connect buttons to their slots */
	connect(logoutButton, SIGNAL(released()), this, SLOT(logoutButtonSlot()));
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(patientButton, SIGNAL(released()), this, SLOT(patientButtonSlot()));
	connect(examsButton, SIGNAL(released()), this, SLOT(examsButtonSlot()));
	connect(notesButton, SIGNAL(released()), this, SLOT(notesButtonSlot()));
	connect(accountButton, SIGNAL(released()), this, SLOT(accountButtonSlot()));
	
	/* layout operation */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addStretch(7);
	headerLayout->addWidget(logoutButton);
	headerLayout->addStretch(1);
	headerLayout->addWidget(quitButton);
	
	QGridLayout *buttonsGrid = new QGridLayout();
	buttonsGrid->setContentsMargins(5,0,5,0);
	buttonsGrid->addWidget(patientButton,0,0);
	buttonsGrid->addWidget(examsButton,0,1);
	buttonsGrid->addWidget(notesButton,1,0);
	buttonsGrid->addWidget(accountButton,1,1);
	buttonsGrid->setAlignment(Qt::AlignCenter);
	buttonsGrid->setVerticalSpacing(5);
	buttonsGrid->setHorizontalSpacing(5);
		
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(headerLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(buttonsGrid);
	mainLayout->addStretch();
	mainLayout->setAlignment(Qt::AlignTop);
	
	/* footer operations */
	footer = new ChangePatientFooter(this);
	footer->setVisible(false);
	mainLayout->addStretch();
	mainLayout->addWidget(footer);
	
	creditsFooter = new CreditsFooterWidget();
	creditsFooter->setMinimumHeight(43);
	creditsFooter->setMaximumHeight(43);
	creditsFooter->setBackgroundImage();
	mainLayout->addWidget(creditsFooter);
		
	setLayout(mainLayout);
	
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(patientChangedSlot()));
}

/* patient button slot */
void MainMenuForm::patientButtonSlot()
{
	if (MobiState::getInstance()->getCurrentPatient() != 0) // patient already selected 
	{
		/* create and show the patient menu widget */
		patientMenuForm = new PatientMenuForm(this);
		patientMenuForm->setAttribute(Qt::WA_DeleteOnClose, true);
		patientMenuForm->showFullScreen();
	}
	else // no patient selected
	{
		/* create and show the search menu*/
		SelectSearchMenu *searchMenu = new SelectSearchMenu();
		searchMenu->setAttribute(Qt::WA_DeleteOnClose, true);
		searchMenu->showFullScreen();
		
		/*
		patientSearchForm = new PatientSearchForm();
		patientSearchForm->setAttribute(Qt::WA_DeleteOnClose, true);
		patientSearchForm->showFullScreen();
		*/
	}
}

void MainMenuForm::examsButtonSlot()
{
	if (MobiState::getInstance()->getCurrentPatient() != 0) // patient already selected 
	{
		/* load the configuration files */
		vector<QString> descriptors;
		/*
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		descriptors.push_back(QString(":/xml/actions/action-descriptor.xml"));
		*/
		descriptors.push_back(QString(":/xml/actions/actionTest.xml"));
	
		/* create and show the exams menu widget */
		examsForm = new ActionsMenu(descriptors, this);
		examsForm->setAttribute(Qt::WA_DeleteOnClose, true);
		examsForm->showFullScreen();	
	}
	else // no patient selected
	{
		/* create and show the search menu  */
		SelectSearchMenu *searchMenu = new SelectSearchMenu();
		searchMenu->setAttribute(Qt::WA_DeleteOnClose, true);
		searchMenu->showFullScreen();
		
		/*
		patientSearchForm = new PatientSearchForm();
		patientSearchForm->setAttribute(Qt::WA_DeleteOnClose, true);
		patientSearchForm->showFullScreen();
		*/
	}
}

void MainMenuForm::notesButtonSlot()
{
	/* not yet implemented */
}

void MainMenuForm::accountButtonSlot()
{
	/* not yet implemented */
}

void MainMenuForm::setBackgroundImage()
{
	QPalette p = palette();
	QPixmap pixmap(":/icons/background.png"); 
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

/* patient changet slot (connected to changeCurrentPatientSignal) */
void MainMenuForm::patientChangedSlot()
{
	/* update the footer object with the new patient information */
	QString name = MobiState::getInstance()->getCurrentPatient()->anagrafica->name;
	QString surname = MobiState::getInstance()->getCurrentPatient()->anagrafica->lastName;
	footer->updatePatient(name + " " + surname);
	if (!footer->isVisible())
	{
		footer->setVisible(true);
		creditsFooter->setVisible(false);
	}
	/* activate the main menu form */
	activateWindow();
}

/* logout button slot */
void MainMenuForm::logoutButtonSlot()
{
	/* reset the current patient */
	//MobiState::getInstance()->changeCurrentPatient(0);
	MobiState::getInstance()->reset();
	
	/* reset login field */
	parent->resetText();
	
	/* close the main menu form */
	parent->activateWindow();
	close();
}

MainMenuForm::~MainMenuForm()
{

}
