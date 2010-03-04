#include "mainmenuform.h"
#include <QPushButton>
#include <QGridLayout>

#include "setbackground.h"
#include <QDesktopWidget>

MainMenuForm::MainMenuForm(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
exitButton = new QPushButton("Exit", this);
	connect(exitButton, SIGNAL(clicked()),
	                      this, SLOT(loginSlot()));

patientButton = new QPushButton("Paziente", this);
examsButton = new QPushButton("Visite", this);
notesButton = new QPushButton("Note", this);
accountButton = new QPushButton("My Account", this);

QGridLayout *princLayout = new QGridLayout;
princLayout->addWidget(patientButton, 0, 0, Qt::AlignLeft);
princLayout->addWidget(examsButton, 0, 0, Qt::AlignRight);
princLayout->addWidget(notesButton, 1, 0, Qt::AlignLeft);
princLayout->addWidget(accountButton, 1, 0, Qt::AlignRight);
princLayout->addWidget(exitButton, 2, 0, Qt::AlignLeft);
setLayout(princLayout);
}

void SetBackground::SetBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	 QPalette p = palette();
	 
	 //Load image to QPixmap, Give full path of image
	QPixmap pixmap1("c://01.JPG"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location
	
	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();
	
	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size));
	
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}


MainMenuForm::~MainMenuForm()
{
}
