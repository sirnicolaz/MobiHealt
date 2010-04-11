#include "NotesForm.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QSize>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>


NotesForm::NotesForm(QString title, QString text, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundImage();
	
	/* create the GUI objects */
	backButton = new ButtonLabel(QPixmap(":/backButton.png"), QPixmap(":/backButton.png"), this);
	connect(backButton, SIGNAL(released()), this, SLOT(close()));
	quitButton = new ButtonLabel(QPixmap(":/quitButton.png"), QPixmap(":/quitButton.png"), this);
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	patientImagesIcon = new QLabel(this);
	patientImagesIcon->setPixmap(QPixmap(":/icons/patient_images.png"));
	
	/* initialize the footer object */
	footer = new ChangePatientFooter(this);
	
	 /* layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setMargin(5);
	headerLayout->addWidget(patientImagesIcon);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QLabel *note = new QLabel(text, this);
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidget(note);
	
	mainLayout->addLayout(headerLayout);
	mainLayout->addStretch();
	mainLayout->addWidget(scrollArea);
	mainLayout->addStretch();
	mainLayout->addWidget(backButton);

	/* footer operations */
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();
	QSize footerSize(rect.width() , 60);
	footer->setMinimumSize(footerSize);
	footer->setMaximumSize(footerSize);
	footer->setBackgroundImage();
	mainLayout->addStretch();
	mainLayout->addWidget(footer);
			
	setLayout(mainLayout);
}

void NotesForm::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap1(":/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

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


NotesForm::~NotesForm()
{

}
