#include "ActionItemWidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFlag>
#include <QPixmap>
#include "buttonlabel.h"

ActionItemWidget::ActionItemWidget(QString actionName, int actionNum, QWidget *parent)
: QWidget(parent)
	{
	setAutoFillBackground(true);
	
	actionNumber = actionNum;
	
	//QLabel *actionIcon = new QLabel(this);
	//actionIcon->setPixmap(QPixmap(":/icons/visitaverde.png"));
	ButtonLabel *actionButton = new ButtonLabel(QPixmap(":/icons/visitaverde.png"), QPixmap(":/icons/visitaverde.png"), this);
	connect(actionButton, SIGNAL(released()), this, SLOT(clickWithID()));
	
	QLabel *actionLabel = new QLabel(actionName,this);
	
	QHBoxLayout *hLayout = new QHBoxLayout();
	//hLayout->setSpacing(10);
	QVBoxLayout *iconVLayout = new QVBoxLayout();
	QVBoxLayout *labelVLayout = new QVBoxLayout();
	
	iconVLayout->addSpacing(7);
	iconVLayout->addWidget(actionButton);
	iconVLayout->addStretch();
	
	labelVLayout->addSpacing(20);
	labelVLayout->addWidget(actionLabel);
	labelVLayout->addStretch();
	
	hLayout->addLayout(iconVLayout);
	hLayout->addSpacing(10);
	hLayout->addLayout(labelVLayout);
	hLayout->addStretch();

	setLayout(hLayout);
	}

void ActionItemWidget::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/actionBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();
	QRect rect = this->geometry();
	QSize size(rect.width(), rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::IgnoreAspectRatio));
	p.setBrush(QPalette::Background,  pixmap1);
	setPalette(p);
}

void ActionItemWidget::clickWithID()
{
	emit clickedWithID(this->actionNumber);
}

ActionItemWidget::~ActionItemWidget()
	{
	
	}
