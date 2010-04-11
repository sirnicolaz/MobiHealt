#include <ChangePatientFooter.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <buttonlabel.h>
#include <QDesktopWidget>
#include <QRect>
#include <QSize>
#include <QApplication>
//#include "PatientSearchForm.h"
#include "SelectSearchMenu.h"
#include "MobiState.h"
#include "Patient.h"

ChangePatientFooter::ChangePatientFooter(QWidget *parent)
: QWidget(parent)
{
	setStyleSheet("QLabel{ font-size : 15px; font-family : helvetica;}");
	setBackgroundImage();
	setFixedHeight(57);
	setAutoFillBackground(true);
	this->setContentsMargins(0,0,0,0);
	
	/* create the footer objects */
	patient = new QLabel("Paziente", this);
	patient->setStyleSheet("color: black;");
	
	/* if current patient is selected set the patient name */
	if (MobiState::getInstance()->getCurrentPatient() != 0)
	{
		QString name = MobiState::getInstance()->getCurrentPatient()->anagrafica->name;
		QString surname = MobiState::getInstance()->getCurrentPatient()->anagrafica->lastName;
		patientName = new QLabel(name + " " + surname);
	}
	else
		patientName = new QLabel("", this);
	
	patientName->setStyleSheet("color: white;");
	changePatientButton = new ButtonLabel(QPixmap(":/icons/changePatientButton.png"), QPixmap(":/icons/changePatientButton.png"), this);
	
	/* connect the button */
	connect(changePatientButton, SIGNAL(released()), this, SLOT(changePatientButtonSlot()));
	
	/* layout operations */
	hLayout = new QHBoxLayout();
	hLayout->setContentsMargins(13, 0, 13, 0);
	
	labelLayout = new QVBoxLayout();
	labelLayout->setContentsMargins(0,13,0,13);
	//labelLayout->addSpacing(2);
	labelLayout->addWidget(patient);
	//labelLayout->addSpacing(2);
	labelLayout->addStretch();
	labelLayout->addWidget(patientName);
	//labelLayout->addStretch();
	//labelLayout->setSpacing(1);
	hLayout->addLayout(labelLayout);
	hLayout->addStretch();
	
	hLayout->addWidget(changePatientButton);
	hLayout->setAlignment(changePatientButton, Qt::AlignCenter);
	
	setLayout(hLayout);
}

/* change patient button slot */
void ChangePatientFooter::changePatientButtonSlot()
{
	/* create and show the search menu  */
	SelectSearchMenu *searchMenu = new SelectSearchMenu();
	searchMenu->setAttribute(Qt::WA_DeleteOnClose);
	searchMenu->showFullScreen();
	
	/*
	PatientSearchForm *patientSearchForm = new PatientSearchForm();
	patientSearchForm->setAttribute(Qt::WA_DeleteOnClose, true);
	patientSearchForm->showFullScreen();
	*/
}

void ChangePatientFooter::setBackgroundImage()
{

	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	//QPixmap pixmap1(":/changePatientFooterBg.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

	//resize image if it is larger than screen size.
	//QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect rect = desktopWidget->availableGeometry();
	//QRect rect = this->geometry();
	//QSize size(rect.width(), rect.height());
	//resize as per your reqirement..
	//QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));
	//p.setBrush(QPalette::Background,  pixmap);
	p.setBrush(QPalette::Background, QColor(190, 10, 38, 200));
	//p.setBrush(QPalette::Background, QColor(255, 255, 255));
	setPalette(p);
}

void ChangePatientFooter::updatePatient(QString newPatientName)
{
	patientName->setText(newPatientName);
}

ChangePatientFooter::~ChangePatientFooter()
{
	
}
