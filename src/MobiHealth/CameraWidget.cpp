#include "CameraWidget.h"
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QPushButton>
#include "CameraObserver.h"
#include "Action.h"
#include "ViewFinder.h"

CameraWidget::CameraWidget(Action* actionsForm, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	this->actionsForm = actionsForm;
	
	this->setContentsMargins(0,0,0,0);
	QVBoxLayout *layout = new QVBoxLayout();
	layout->setContentsMargins(0,0,0,0);
	ViewFinder *viewFinder = new ViewFinder(this); 
		
	QPushButton *quit = new QPushButton("Quit", this);
	QPushButton *capture = new QPushButton("Capture", this);
	QPushButton *zoomIn = new QPushButton("+", this);
	QPushButton *zoomOut = new QPushButton("-", this);
	zoomIn->setAutoRepeat(true);
	zoomOut->setAutoRepeat(true);
		
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));
	connect(capture, SIGNAL(clicked()), this, SLOT(captureSlot()));
	connect(zoomIn, SIGNAL(clicked()), this, SLOT(zoomInSlot()));
	connect(zoomOut, SIGNAL(clicked()), this, SLOT(zoomOutSlot()));
		
	QHBoxLayout *zoomHLayout = new QHBoxLayout();
	zoomHLayout->addWidget(zoomIn);
	zoomHLayout->addWidget(zoomOut);
		
	QHBoxLayout *captureHLayout = new QHBoxLayout();
	captureHLayout->addWidget(capture);
	captureHLayout->addWidget(quit);
		
	layout->addWidget(viewFinder);
	layout->addLayout(zoomHLayout);
	layout->addLayout(captureHLayout);
		
	TRAPD(err, iCameraObserver = CameraObserver::NewL( TRect( TPoint(0,0) , TSize( 800 , 800 ) ), viewFinder, this ));	
	if (err != KErrNone) // ERROR
	{
		QLabel *label = new QLabel("ERROR:" + QString::number(err), this);
		layout->addWidget(label);
	}
	else
	{
		//QLabel *label = new QLabel("NO ERROR", this);
		//layout->addWidget(label);
	}
		
	setLayout(layout);
}

CameraWidget::~CameraWidget()
{
	delete iCameraObserver;
}

void CameraWidget::captureSlot()
{
	iCameraObserver->startFocusing();
}

void CameraWidget::zoomInSlot()
{
	iCameraObserver->zoom(ETrue);
}

void CameraWidget::zoomOutSlot()
{
	iCameraObserver->zoom(EFalse);
}

void CameraWidget::pictureSaved()
{
	// proceed to next step or (if it was the last step) close wizard
	if (actionsForm->isLastStep())
	{
		actionsForm->finishButtonSlot();
	}
	else
	{
		actionsForm->nextStep();
	}
	/* close the camera widget */
	this->close();
}
