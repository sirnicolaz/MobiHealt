#include "PatientNumberLabel.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QColor>

PatientNumberLabel::PatientNumberLabel(int patientNumber, QWidget *parent)
: QWidget(parent)
{	
	setAutoFillBackground(true);
	
	/* patient number */
	
	QString text;
	if (patientNumber==1)
		text = " PAZIENTE TROVATO!";
	else
		text = " PAZIENTI TROVATI!";
	
	QLabel *patientNumberLabel = new QLabel(QString::number(patientNumber) + text, this);
	patientNumberLabel->setStyleSheet("color: white; font-family: helvetica;");
	
	/* layout operations */
	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addSpacing(8);
	vLayout->addWidget(patientNumberLabel);
	vLayout->setAlignment(patientNumberLabel, Qt::AlignCenter);
	
	setLayout(vLayout);
}

void PatientNumberLabel::setBackgroundImage()
{

	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/icons/patientNumberLabelBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

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

PatientNumberLabel::~PatientNumberLabel()
{
	
}

