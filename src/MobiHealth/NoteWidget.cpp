#include "NoteWidget.h"
#include "buttonlabel.h"
#include "ChangePatientFooter.h"
#include <QPalette>
#include <QSizePolicy>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QSize>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

NoteWidget::NoteWidget(QString title, QString text, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButtonPushed.png"), this);
	connect(backButton, SIGNAL(released()), this, SLOT(close()));
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	patientIcon = new QLabel(this);
	patientIcon->setPixmap(QPixmap(":/icons/patientIcon.png"));
	
	/* initialize the footer object */
	footer = new ChangePatientFooter(this);
	
    QLabel *headerText = new QLabel(this);
    headerText->setStyleSheet("font-family: arial; font-weight: bold; font-size: 18px;");
    headerText->setText("<font color=\"#622181\">Paziente</font><font color=\"#9C9E9F\"> / </font><font color=\"#0B72B5\">Immagini</font>");
        
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(patientIcon);
	headerLayout->addSpacing(3);
	headerLayout->addWidget(headerText);
	headerLayout->setAlignment(headerText, Qt::AlignVCenter);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	
	QLabel *titleLabel = new QLabel("<font color=\"black\">Soggetto<br/></font> <font color=\"white\" >"+ title +"</font>", this);
	titleLabel->setMinimumHeight(100);
	titleLabel->setAutoFillBackground(true);
	titleLabel->setFont(QFont("helvetica"));
	titleLabel->setAlignment(Qt::AlignVCenter);
	QPalette titlePal(titleLabel->palette());
	titlePal.setColor(QPalette::Background, QColor(190,10,38));
	titleLabel->setPalette(titlePal);
	
	QLabel *note = new QLabel(text, this);
	note->setFont(QFont("helvetica"));
	QPalette notePal(note->palette());
	notePal.setColor(QPalette::Text, Qt::black);
	note->setPalette(notePal);
	note->setWordWrap(true);
	note->setAlignment(Qt::AlignJustify);
	note->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setWidgetResizable(true);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setWidget(note);
	scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(headerLayout);
	mainLayout->addWidget(titleLabel);
	
	QHBoxLayout *backHLayout = new QHBoxLayout();
	backHLayout->setContentsMargins(15, 0,0,0);
	backHLayout->addWidget(backButton);
	
	QHBoxLayout *scrollLayout = new QHBoxLayout();
	scrollLayout->addWidget(scrollArea);
	scrollLayout->setAlignment(scrollArea, Qt::AlignVCenter);
	mainLayout->addLayout(scrollLayout);
	mainLayout->addStretch(3);
	mainLayout->addLayout(backHLayout);
	mainLayout->addStretch(1);
	mainLayout->addWidget(footer);
			
	setLayout(mainLayout);
}

void NoteWidget::setBackgroundImage()
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

NoteWidget::~NoteWidget()
{

}
