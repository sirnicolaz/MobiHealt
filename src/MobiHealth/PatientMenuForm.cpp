#include "PatientMenuForm.h"
#include "MainMenuForm.h"
#include "ChangePatientFooter.h"
#include "buttonlabel.h"
#include "MobiState.h"
#include "soapMobiBindingProxy.h"
#include "AnagraficaForm.h"
#include "ContactsForm.h"
#include "ImagesForm.h"
#include "PathologiesForm.h"
#include "HistoryForm.h"
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QPalette>
#include <QRect>
#include <QSize>

PatientMenuForm::PatientMenuForm(QWidget *parent)
    : QWidget(0)
{
	this->parent = dynamic_cast<MainMenuForm*>(parent);
	
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	anagraficaButton = new ButtonLabel(QPixmap(":/icons/anagraficaButton.png"), QPixmap(":/icons/anagraficaButtonPushed.png"), this);
	contactsButton = new ButtonLabel(QPixmap(":/icons/contactsButton.png"), QPixmap(":/icons/contactsButtonPushed.png"), this);
	medicalReportButton = new ButtonLabel(QPixmap(":/icons/medicalReportButton.png"), QPixmap(":/icons/medicalReportButtonPushed.png"), this);
	pathologiesButton = new ButtonLabel(QPixmap(":/icons/pathologiesButton.png"), QPixmap(":/icons/pathologiesButtonPushed.png"), this);
	imagesButton = new ButtonLabel(QPixmap(":/icons/imagesButton.png"), QPixmap(":/icons/imagesButtonPushed.png"), this);
	historyButton = new ButtonLabel(QPixmap(":/icons/historyButton.png"), QPixmap(":/icons/historyButtonPushed.png"), this);
	
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	userIcon = new QLabel(this);
	userIcon->setPixmap(QPixmap(":/icons/userIcon.png"));
	
	/* connect the buttons */
	connect(backButton, SIGNAL(released()), this, SLOT(backButtonSlot()));
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	
	connect(anagraficaButton, SIGNAL(released()), this, SLOT(anagraficaButtonSlot()));
	connect(contactsButton, SIGNAL(released()), this, SLOT(contactsButtonSlot()));
	connect(imagesButton, SIGNAL(released()), this, SLOT(imagesButtonSlot()));
	connect(medicalReportButton, SIGNAL(released()), this, SLOT(medicalReportButtonSlot()));
	connect(historyButton, SIGNAL(released()), this, SLOT(historyButtonSlot()));
	connect(pathologiesButton, SIGNAL(released()), this, SLOT(pathologiesButtonSlot()));
	
	/* create the footer */
	footer = new ChangePatientFooter(this);
	
	/* layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(userIcon);
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);

	QGridLayout *buttonsGrid = new QGridLayout();
	//buttonsGrid->setContentsMargins(0,0,0,0);
	buttonsGrid->addWidget(anagraficaButton,0,0);
	buttonsGrid->addWidget(contactsButton,0,1);
	buttonsGrid->addWidget(medicalReportButton,1,0);
	buttonsGrid->addWidget(pathologiesButton,1,1);
	buttonsGrid->addWidget(imagesButton,2,0);
	buttonsGrid->addWidget(historyButton,2,1);
	buttonsGrid->setAlignment(Qt::AlignCenter);
	buttonsGrid->setVerticalSpacing(0);
	buttonsGrid->setHorizontalSpacing(0);
	
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);
	
	QFrame *line = new QFrame(this);
	line->setFixedHeight(2);
	line->setStyleSheet("border-top: 2px dashed gray");
		
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(headerLayout);
	mainLayout->addSpacing(7);
	mainLayout->addWidget(line);
	mainLayout->addStretch(3);
	mainLayout->addLayout(buttonsGrid);
	mainLayout->addStretch(3);
	mainLayout->addLayout(backHLayout);
	mainLayout->addStretch(1);
	mainLayout->setAlignment(Qt::AlignTop);
	
	/* footer operations */
	mainLayout->addStretch();
	mainLayout->addWidget(footer);
	
	setLayout(mainLayout);
	
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
}

void PatientMenuForm::backButtonSlot()
{
	/* activate the main menu widget */
	parent->activateWindow();
	/* close the patient form */
	this->close();
}

void PatientMenuForm::anagraficaButtonSlot()
{
	anagraficaForm = new AnagraficaForm(this);
	anagraficaForm->setAttribute(Qt::WA_DeleteOnClose, true);
	anagraficaForm->showFullScreen();
}

void PatientMenuForm::contactsButtonSlot()
{
	contactsForm = new ContactsForm(this);
	contactsForm->setAttribute(Qt::WA_DeleteOnClose, true);
	contactsForm->showFullScreen();
}

void PatientMenuForm::imagesButtonSlot()
{
	imagesForm = new ImagesForm(this);
	imagesForm->setAttribute(Qt::WA_DeleteOnClose, true);
	imagesForm->showFullScreen();
}

void PatientMenuForm::medicalReportButtonSlot()
{
	
}

void PatientMenuForm::pathologiesButtonSlot()
{
	pathologiesForm = new PathologiesForm(this);
	pathologiesForm->setAttribute(Qt::WA_DeleteOnClose, true);
	pathologiesForm->showFullScreen();
}

void PatientMenuForm::historyButtonSlot()
{
	historyForm = new HistoryForm(this);
	historyForm->setAttribute(Qt::WA_DeleteOnClose, true);
	historyForm->showFullScreen();
}

PatientMenuForm::~PatientMenuForm()
{

}

void PatientMenuForm::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap(":/icons/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();

	//QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}
