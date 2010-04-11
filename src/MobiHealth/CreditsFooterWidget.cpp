#include <CreditsFooterWidget.h>
#include "buttonlabel.h"
#include "CreditsWidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <buttonlabel.h>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QApplication>

CreditsFooterWidget::CreditsFooterWidget(QWidget *parent)
: QWidget(parent)
{
	setAutoFillBackground(true);
	setContentsMargins(7,7,10,7);
	
	/* create the footer objects */
	creditsButton = new ButtonLabel(QPixmap(":/icons/creditsIcon.png"), QPixmap(":/icons/creditsIcon.png"), this);
	whippyIcon = new QLabel(this);
	whippyIcon->setPixmap(QPixmap(":/icons/whippyIcon.png"));
	
	/* connect the button */
	connect(creditsButton, SIGNAL(released()), this, SLOT(creditsButtonSlot()));
	
	/* layout operations */
	hLayout = new QHBoxLayout();
	hLayout->setContentsMargins(0,0,0,0);

	hLayout->addWidget(whippyIcon);
	hLayout->setAlignment(whippyIcon, Qt::AlignVCenter);
	hLayout->addStretch();
	hLayout->addWidget(creditsButton);
	hLayout->setAlignment(creditsIcon, Qt::AlignVCenter);
	
	setLayout(hLayout);
}

void CreditsFooterWidget::setBackgroundImage()
{

	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/creditsFooterBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();
	QRect rect = this->geometry();
	QSize size(rect.width(), rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

void CreditsFooterWidget::creditsButtonSlot()
{
	/* create and show the credits widget */
	CreditsWidget *creditsWidget = new CreditsWidget(this);
	creditsWidget->setAttribute(Qt::WA_DeleteOnClose, true);
	creditsWidget->showFullScreen();
}

CreditsFooterWidget::~CreditsFooterWidget()
{

}
