#include "ErrorForm.h"
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "buttonlabel.h"

ErrorForm::ErrorForm(int error, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundImage();
	
	QLabel *errorMsg = new QLabel("ERROR: " + QString::number(error), this);
	QLabel *personLogo = new QLabel(this);
	personLogo->setPixmap(QPixmap(":/icons/userIcon.png"));
	ButtonLabel *quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButton.png"), this);
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	ButtonLabel *backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButton.png"), this);
	connect(backButton, SIGNAL(released()), this, SLOT(close()));
	
	/* layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(5, 5, 5, 5);
	headerLayout->addWidget(personLogo);
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(headerLayout);
	mainLayout->addWidget(errorMsg);
	mainLayout->setAlignment(errorMsg, Qt::AlignLeft);
	mainLayout->addStretch();
	mainLayout->addWidget(backButton);
	mainLayout->setAlignment(backButton, Qt::AlignLeft);
	
	setLayout(mainLayout);
}

void ErrorForm::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();

	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

ErrorForm::~ErrorForm()
{

}
