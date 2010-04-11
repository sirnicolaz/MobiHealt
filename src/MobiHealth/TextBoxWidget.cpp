#include <TextBoxWidget.h>
#include <QPalette>
#include <QPixmap>
#include <QRect>
#include <QSize>
#include <QLineEdit>
#include <QHBoxLayout>

TextBoxWidget::TextBoxWidget(QPixmap background, QWidget *parent)
:QWidget(parent)
{
	setStyleSheet("QLineEdit { font-size: 18px; font-family: helvetica; color: red; background-color: white; border: 1px solid gray; border-radius: 10px;}");
	
	bg = background;
	setAutoFillBackground(true);
	this->setMinimumHeight(44);
	this->setMaximumHeight(44);
	this->setContentsMargins(0,0,0,0);
	
	textBox = new QLineEdit(this);
	textBox->setFixedWidth(300);
	textBox->setFixedHeight(30);
	
	QHBoxLayout *hLayout = new QHBoxLayout();
	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addSpacing(2);
	vLayout->addWidget(textBox);
	hLayout->addLayout(vLayout);
	
	setLayout(hLayout);
}

void TextBoxWidget::setBackgroundImage()
{

	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	//QPixmap pixmap1(":/icons/searchLabelBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();
	//QRect rect = this->geometry();
	//QSize size(rect.width(), rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	p.setBrush(QPalette::Background,  bg);
	setPalette(p);
}

QString TextBoxWidget::getValue()
{
	return textBox->text();
}

TextBoxWidget::~TextBoxWidget()
	{
	
	}
