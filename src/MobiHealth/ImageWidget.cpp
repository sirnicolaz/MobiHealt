#include "ImageWidget.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QSize>
#include <QHBoxLayout>
#include <QVBoxLayout>

ImageWidget::ImageWidget(QString image, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	connect(backButton, SIGNAL(released()), this, SLOT(close()));
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	patientIcon = new QLabel(this);
	patientIcon->setPixmap(QPixmap(":/icons/patientIcon.png"));
	
	footer = new ChangePatientFooter(this);
	
	QLabel *imageLabel = new QLabel(this);
	imageLabel->setPixmap(QPixmap(":/icons/testImage.png"));
	
	QLabel *headerText = new QLabel(this);
	headerText->setStyleSheet("font-family: arial; font-weight: bold; font-size: 18px;");
	headerText->setText("<font color=\"#622181\">Paziente</font><font color=\"#9C9E9F\"> / </font><font color=\"#0B72B5\">Immagini</font>");
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(patientIcon);
	headerLayout->addSpacing(3);
	headerLayout->addWidget(headerText);
	headerLayout->setAlignment(headerText, Qt::AlignVCenter);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);
	
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(headerLayout);
	mainLayout->addSpacing(7);
	mainLayout->addWidget(imageLabel);
	mainLayout->addStretch(3);
	mainLayout->addLayout(backHLayout);
	mainLayout->addStretch(1);
	mainLayout->addWidget(footer);
	
	setLayout(mainLayout);
}

void ImageWidget::setBackgroundImage()
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

ImageWidget::~ImageWidget()
{

}
