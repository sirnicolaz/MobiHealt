#include "creditswidget.h"
#include "CreditsFooterWidget.h"
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QDesktopWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QRect>
#include <QSize>
#include <QHBoxLayout>
#include "buttonlabel.h"
#include <QLineEdit>
#include <QRect>



CreditsWidget::CreditsWidget(QWidget *parent)
    : QWidget(0)
{
	ui.setupUi(this);
	
	this->parent = dynamic_cast<CreditsFooterWidget*>(parent);
	
	/* set the background image */
	setBackgroundImage();
	
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	creditsText = new QLabel("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", this);
	creditsText->setAlignment(Qt::AlignJustify);
	creditsText->setWordWrap(true);
	creditsText->setStyleSheet("font-family: helvetica; color: black;");
	creditsText->setContentsMargins(0,0,0,0);
	personLogo = new QLabel(this);
	
	/* connect buttons to their slots */
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(backButton, SIGNAL(released()), this, SLOT(closeButtonSlot()));
	
	/* set the icos */
	personLogo->setPixmap(QPixmap(":/icons/userIcon.png"));
	
	/* layout operation */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(personLogo);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QHBoxLayout *footerLayout = new QHBoxLayout();
	footerLayout->setContentsMargins(13, 0, 0, 15);
	footerLayout->addWidget(backButton);
	footerLayout->addStretch();
	
	QHBoxLayout *textLayout = new QHBoxLayout();
	textLayout->setContentsMargins(13,0,13,0);
	textLayout->addWidget(creditsText);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(headerLayout);
	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addLayout(textLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(footerLayout);
	
	setLayout(mainLayout);
}

void CreditsWidget::closeButtonSlot()
{
	parent->activateWindow();
	this->close();
}

void CreditsWidget::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();

	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	p.setBrush(QPalette::Background,  pixmap1);
	setPalette(p);
}

CreditsWidget::~CreditsWidget()
{

}
