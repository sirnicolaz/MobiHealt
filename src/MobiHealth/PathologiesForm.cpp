#include "PathologiesForm.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include "PatientMenuForm.h"
#include "MobiState.h"
#include "Patient.h"
#include <QString>
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QSize>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>

PathologiesForm::PathologiesForm(QWidget *parent)
    : QWidget(0)
{
	this->parent = static_cast<PatientMenuForm*>(parent);
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	patientIcon = new QLabel(this);
	patientIcon->setPixmap(QPixmap(":/icons/patientIcon.png")); //TODO: change to correct icon!!! (or set text)
	
	/* connect the buttons */
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(backButton, SIGNAL(released()), this, SLOT(backButtonSlot()));
	
	/* inizialize the footer object */
	footer = new ChangePatientFooter();
	    
	QLabel *headerText = new QLabel(this);
	headerText->setStyleSheet("font-family: arial; font-weight: bold; font-size: 18px;");
	headerText->setText("<font color=\"#622181\">Paziente</font><font color=\"#9C9E9F\"> / </font><font color=\"#0B72B5\">Patologie</font>");
	        
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
	scrollWidget->setContentsMargins(0,0,0,0);
	QVBoxLayout *scrollLayout = new QVBoxLayout();
	scrollLayout->setContentsMargins(23,10,40,0);
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setFixedHeight(400);
		
	scrollLayout->setSpacing(1);
		
	/* add the contacts to scrollarea */
	QMap<QString, QString> map = *(MobiState::getInstance()->getCurrentPatient()->pathologies);
	QMapIterator<QString, QString> i(map);
	while (i.hasNext()) {
		i.next();
		QFrame *line = new QFrame(this);
		line->setFixedHeight(2);
		line->setStyleSheet("border-top: 2px dashed gray;");
		QLabel *pathologyLabel = new QLabel(i.key(), this);
		pathologyLabel->setStyleSheet("font-family : helvetica; color: #BE0A26;");
		QLabel *pathology = new QLabel(i.value(), this);
		pathology->setStyleSheet("font-family : helvetica; color: black;");
		scrollLayout->addWidget(pathologyLabel);
		scrollLayout->addWidget(line);
		scrollLayout->addWidget(pathology);
		scrollLayout->addSpacing(30);
	}
		
	scrollWidget->setLayout(scrollLayout);
		
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);

	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidget(scrollWidget);

	
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

	/* footer operations */
	mainLayout->addStretch(1);
	mainLayout->addWidget(footer);
			
	setLayout(mainLayout);

	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
}

void PathologiesForm::backButtonSlot()
{
	/* activate the parent widget */
	parent->activateWindow();
	/* close the pathologies form */
	this->close();
}

void PathologiesForm::setBackgroundImage()
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

PathologiesForm::~PathologiesForm()
{

}
