#include "ActionsMenu.h"
#include "DescriptorHandler.h"
#include "DescriptorElements.h"
#include "Action.h"
#include "buttonlabel.h"
#include "ActionItemWidget.h"
#include "ChangePatientFooter.h"
#include "MainMenuForm.h"
#include "MobiState.h"
#include "Patient.h"
#include <QPushButton>
#include <QPalette>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <QRect>
#include <QScrollArea>
#include <vector>

using namespace std;

class QVBoxLayout;

ActionsMenu::ActionsMenu(vector<QString> actionDescriptorFileNames, QWidget *parent)
    : QWidget(0)
{
	this->parent = static_cast<MainMenuForm*>(parent);
	ui.setupUi(this);
	setBackgroundImage();
	this->setContentsMargins(0,0,0,0);
	
	/* inizialize the footer references */
	footer = new ChangePatientFooter();
	
	visitsIcon = new QLabel(this);
	visitsIcon->setPixmap(QPixmap(":/icons/visitsIcon.png"));
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButton.png"));
	backButton = new ButtonLabel(QPixmap(":/icons/backButton.png"), QPixmap(":/icons/backButton.png"));
	
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(backButton, SIGNAL(released()), this, SLOT(backButtonSlot()));
	
	mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignCenter);
	descriptors = actionDescriptorFileNames;
	
	QWidget *scrollWidget = new QWidget(this);
	QVBoxLayout *scrollLayout = new QVBoxLayout();
	scrollLayout->setSpacing(0);
	scrollLayout->setContentsMargins(0,0,0,0);
	
	/* header layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addWidget(visitsIcon);
	headerLayout->addStretch();	
	headerLayout->addWidget(quitButton);
	mainLayout->addLayout(headerLayout);
	mainLayout->setSpacing(0);
	
	for(int i=0; i < actionDescriptorFileNames.size(); i++){

		/* for each actions create an action item widget and add it to layout */
		QString currentFileName = actionDescriptorFileNames[i];
		DescriptorHandler * actionDescriptor = new DescriptorHandler(currentFileName);
		//menuButtons.push_back(new QPushButtonWithID(actionDescriptor->getActionTitle(), i, this));
		//mainLayout->addWidget(menuButtons[i]);
		
		ActionItemWidget *actionItem = new ActionItemWidget(actionDescriptor->getActionTitle(), i, this);
		scrollLayout->addWidget(actionItem);
		actionItem->setBackgroundImage();
		actionItem->setMinimumHeight(79);
		actionItem->setMaximumHeight(79);

		//connect(menuButtons[i], SIGNAL(clicked()), menuButtons[i], SLOT(clickWithID()));
		connect(actionItem, SIGNAL(clickedWithID(int)), this, SLOT(showAction(int)));
	}
	
	scrollLayout->addStretch();
	scrollWidget->setLayout(scrollLayout);
	QScrollArea *scrollArea = new QScrollArea(this);
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();
	scrollWidget->setMinimumWidth(rect.width() - 30);

	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidget(scrollWidget);
	
	mainLayout->addWidget(scrollArea);
	
	/* add back button to layout */
	mainLayout->addSpacing(25);
	mainLayout->addWidget(backButton);
	mainLayout->setAlignment(backButton, Qt::AlignLeft);
	
	/* footer operations */
	mainLayout->addSpacing(40);
	mainLayout->addWidget(footer);
	
	setLayout(mainLayout);
	
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));

}

void ActionsMenu::backButtonSlot()
{
	/* activate the parent widget */
	parent->activateWindow();
	/* close the actions menu widget */
	this->close();
}

/* show action slot implementation */
void ActionsMenu::showAction(int who)
{
	/* create action widget as a main widget (aka without a parent) to have fullscreen widget (todo) */
	DescriptorHandler * actionDescriptor = new DescriptorHandler(descriptors[who]); 
	Action* actionWidget = new Action(actionDescriptor);
	actionWidget->setAttribute(Qt::WA_DeleteOnClose, true);
	actionWidget->showFullScreen(); /* works only with main widget */
}

/* actions menu destructor implementation */
ActionsMenu::~ActionsMenu()
{
	//TODO: deallocation!
}

void ActionsMenu::setBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	QPalette p = palette();
	//Load image to QPixmap, Give full path of image
	QPixmap pixmap(":/icons/background.png"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location
/*
	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();

	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size, Qt::KeepAspectRatioByExpanding));
	//QPixmap pixmap(pixmap1.scaledToWidth(rect.height()));*/
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);	
}
