#include "PatientSearchResultForm.h"
#include "PatientSearchForm.h"
#include "PatientItemWidget.h"
#include "buttonlabel.h"
#include "ScrollFrame.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QScrollArea>
#include <QDesktopWidget>
#include <QSize>
#include <QLabel>
#include "PatientNumberLabel.h"
#include "soapMobiBindingProxy.h"
#include "CreditsWidget.h"
#include "CreditsFooterWidget.h"


PatientSearchResultForm::PatientSearchResultForm(ns1__SimplePatient **array, int size, QWidget *parent)
    : QWidget(0)
{
	/* initialize the parent widget reference */
	this->parent = dynamic_cast<PatientSearchForm*>(parent);
	
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	/* main widget layout */
	QVBoxLayout *layout = new QVBoxLayout();
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);
	
	/* scroll frame */
	//ScrollFrame *scrollFrame = new ScrollFrame(array, size, this);
		
	/* scroll area */
	QScrollArea *scrollArea = new QScrollArea(this);
	//scrollArea->setStyleSheet("border-style: hidden;");
	scrollArea->setAutoFillBackground(true);
	scrollArea->setFixedHeight(300);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		
	/* widget in the sroll area and its layout */
	QWidget *mainWidget = new QWidget(this);
	mainWidget->setAutoFillBackground(true);
	mainWidget->setFixedWidth(355);
	QVBoxLayout *mainLayout = new QVBoxLayout();
		
	/* iterate on the simplePatient and foreach add patient item widget to scroll area */
	int i;
	for (i=0; i < size; i++)
	{
		/* for each patient in the array (aka founded), create a patient item widget and add to the layout */
		PatientItemWidget *widget = new PatientItemWidget(QString(array[i]->patientId), QString(array[i]->name)+" "+ QString(array[i]->lastName), array[i]->city , array[i]->patientCode, this);
		widget->setFixedHeight(100);
		if (i==0) // fist item without border
			widget->setStyleSheet("border-top-style: hidden;");
		//QLabel *widget = new QLabel("foo", this);
		mainLayout->addWidget(widget);
	}
		
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->setSpacing(0);
	mainWidget->setContentsMargins(0,0,0,0);
	/* TODO: now it's not correct for horizontal layout */
	mainWidget->setLayout(mainLayout);
	scrollArea->setWidget(mainWidget);
	
	/* back button layout */
	QHBoxLayout *backHLayout = new QHBoxLayout();
	
	/* create the credits footer objects */
	CreditsFooterWidget *creditsFooter = new CreditsFooterWidget(this);
	creditsFooter->setMinimumHeight(43);
	creditsFooter->setMaximumHeight(43);
	creditsFooter->setBackgroundImage();
	
	QLabel *personLogo = new QLabel(this);
	personLogo->setPixmap(QPixmap(":/icons/userIcon.png"));
	ButtonLabel *quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	ButtonLabel *backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	PatientNumberLabel *patientNumberLabel = new PatientNumberLabel(size, this);
	patientNumberLabel->setFixedHeight(54);
	patientNumberLabel->setBackgroundImage();
	
	/* connect the buttons */
	connect(backButton, SIGNAL(released()), this, SLOT(closeButtonSlot()));
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	
	/* header layout */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(personLogo);
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);
	
	backHLayout->setContentsMargins(16, 0,0,0);
	backHLayout->addWidget(backButton);
	
	QFrame *line = new QFrame(this);
	line->setFixedHeight(2);
	line->setStyleSheet("border-top: 2px dashed gray");
	
	/* adding component to main widget layout */
	layout->addLayout(headerLayout);
	layout->addStretch(5);
	layout->addWidget(patientNumberLabel);
	layout->addWidget(scrollArea);
	layout->addWidget(line);
	layout->addStretch(4);
	layout->addLayout(backHLayout);
	layout->addStretch(1);
	layout->addWidget(creditsFooter);
	
	
	setLayout(layout);
}

void PatientSearchResultForm::setBackgroundImage()
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
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	 */
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

void PatientSearchResultForm::closeButtonSlot()
{
	/* activate the parent widget */
	parent->activateWindow();
	
	/* close the result form */
	this->close();	
}

PatientSearchResultForm::~PatientSearchResultForm()
{

}
