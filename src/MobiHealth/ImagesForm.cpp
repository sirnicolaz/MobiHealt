#include "ImagesForm.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include "PatientMenuForm.h"
#include "ImageItemWidget.h"
#include "MobiState.h"
#include "Patient.h"
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QSize>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>

ImagesForm::ImagesForm(QWidget *parent)
    : QWidget(0)
{
	/* initialize the parten widget reference */
	this->parent = static_cast<PatientMenuForm*>(parent);
	this->setContentsMargins(0,0,0,0);
	
	ui.setupUi(this);
	setBackgroundImage();
	
	/* create the GUI objects */
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	patientIcon = new QLabel(this);
	patientIcon->setPixmap(QPixmap(":/icons/patientIcon.png"));
	
	connect(backButton, SIGNAL(released()), this, SLOT(backButtonSlot()));
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	
	/* inizialize the footer object */
	footer = new ChangePatientFooter(this);
	
	QLabel *headerText = new QLabel(this);
	headerText->setStyleSheet("font-family: arial; font-weight: bold; font-size: 18px;");
	headerText->setText("<font color=\"#622181\">Paziente</font><font color=\"#9C9E9F\"> / </font><font color=\"#0B72B5\">Immagini</font>");
	        
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(patientIcon);
	headerLayout->addSpacing(3);
	headerLayout->addWidget(headerText);
	headerLayout->setAlignment(headerText, Qt::AlignVCenter);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	QWidget *scrollWidget = new QWidget(this);
	scrollWidget->setFixedWidth(350);
	scrollWidget->setContentsMargins(0,0,37,0);
	QVBoxLayout *scrollLayout = new QVBoxLayout();
	scrollLayout->setContentsMargins(23,10,0,0);
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setFixedHeight(400);
	
	scrollLayout->setSpacing(1);
	
	/* add the image items to scrollarea */
	/* TODO: get the images items from patient objects and iterate */
	
	/* test image items */
	ImageItemWidget *preview1 = new ImageItemWidget(new QString("TestImage1"), this);
	ImageItemWidget *preview2 = new ImageItemWidget(new QString("TestImage2"), this);
	ImageItemWidget *preview3 = new ImageItemWidget(new QString("TestImage3"), this);
	ImageItemWidget *preview4 = new ImageItemWidget(new QString("TestImage4"), this);
	ImageItemWidget *preview5 = new ImageItemWidget(new QString("TestImage5"), this);
	ImageItemWidget *preview6 = new ImageItemWidget(new QString("TestImage6"), this);
	ImageItemWidget *preview7 = new ImageItemWidget(new QString("TestImage7"), this);
	
	/* add the test image items to scroll area */
	scrollLayout->addWidget(preview1);
	scrollLayout->addSpacing(15);
	QFrame *line1 = new QFrame(this);
	line1->setFixedHeight(2);
	line1->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line1);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview2);
	scrollLayout->addSpacing(15);
	QFrame *line2 = new QFrame(this);
	line2->setFixedHeight(2);
	line2->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line2);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview3);
	scrollLayout->addSpacing(15);
	QFrame *line3 = new QFrame(this);
	line3->setFixedHeight(2);
	line3->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line3);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview4);
	scrollLayout->addSpacing(15);
	QFrame *line4 = new QFrame(this);
	line4->setFixedHeight(2);
	line4->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line4);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview5);
	scrollLayout->addSpacing(15);
	QFrame *line5 = new QFrame(this);
	line5->setFixedHeight(2);
	line5->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line5);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview6);
	scrollLayout->addSpacing(15);
	QFrame *line6 = new QFrame(this);
	line6->setFixedHeight(2);
	line6->setStyleSheet("border-top: 2px dashed gray;");
	scrollLayout->addWidget(line6);
	scrollLayout->addSpacing(15);
	scrollLayout->addWidget(preview7);
	
	/* TODO: static dimension!!! */
	scrollWidget->setLayout(scrollLayout);

	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidget(scrollWidget);
	
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);
	
	QFrame *headerLine = new QFrame(this);
	headerLine->setFixedHeight(2);
	headerLine->setStyleSheet("border-top: 2px solid #CB0133");
	QFrame *scrollLine = new QFrame(this);
	scrollLine->setFixedHeight(2);
	scrollLine->setStyleSheet("border-top: 2px solid #CB0133");
	
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

/* back button slot */
void ImagesForm::backButtonSlot()
{
	/* active the parent widget */
	parent->activateWindow();
	/* close the images form */
	this->close();
}

void ImagesForm::setBackgroundImage()
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

ImagesForm::~ImagesForm()
{

}
