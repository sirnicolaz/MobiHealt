#include <LabelWidget.h>
#include <QPalette>
#include <QPixmap>
#include <QRect>
#include <QSize>
#include <QLabel>
#include <QHBoxLayout>

LabelWidget::LabelWidget(QString inputLabel, QWidget *parent)
:QWidget(parent)
{
	setAutoFillBackground(true);
	setMinimumHeight(36);
	setMaximumHeight(36);
	setContentsMargins(0,0,0,0);
	
	QLabel *label = new QLabel(inputLabel, this);
	label->setContentsMargins(0,0,0,0);
	label->setStyleSheet("font-family : helvetica; color: black;");
	QLabel *plusIcon = new QLabel(this);
	plusIcon->setPixmap(QPixmap(":/icons/plusIcon.png"));
	
	//QVBoxLayout *vLabelLayout = new QVBoxLayout();
	//vLabelLayout->setContentsMargins(0,0,0,0);
	//vLabelLayout->setSpacing(0);
	//vLabelLayout->addWidget(label);

	//QVBoxLayout *vIconLayout = new QVBoxLayout();
	//vIconLayout->addWidget(plusIcon);
	
	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->setContentsMargins(27,0,13,0);
	//hLayout->addSpacing(25);
	hLayout->addWidget(label);
	//hLayout->addLayout(vLabelLayout);
	hLayout->addStretch();
	hLayout->addWidget(plusIcon);
	//hLayout->addLayout(vIconLayout);
	
	setLayout(hLayout);
}

void LabelWidget::setBackgroundImage()
{

	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/searchLabelBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();
	QRect rect = this->geometry();
	QSize size(rect.width(), rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	p.setBrush(QPalette::Background,  pixmap1);
	setPalette(p);
}

LabelWidget::~LabelWidget()
	{
	
	}
