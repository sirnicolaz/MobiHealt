#include "ScrollFrame.h"
#include "soapMobiBindingProxy.h"
#include "PatientItemWidget.h"
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>



ScrollFrame::ScrollFrame(ns1__SimplePatient **array, int size, QWidget *parent)
: QFrame(parent)
{
	this->setContentsMargins(0,0,0,0);
	//this->setStyleSheet("border: 2px dashed gray;");
	
	QVBoxLayout *layout = new QVBoxLayout();
	layout->setContentsMargins(0,0,0,0);
	
	/* scroll area */
	QScrollArea *scrollArea = new QScrollArea(this);
	//scrollArea->setStyleSheet("border-style: hidden;");
	scrollArea->setAutoFillBackground(true);
	scrollArea->setFixedHeight(300);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	/* widget in the sroll area and its layout */
	QWidget *mainWidget = new QWidget(this);
	mainWidget->setAutoFillBackground(true);
	//mainWidget->setFixedWidth(335);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	
	/* iterate on the simplePatient and foreach add patient item widget to scroll area */
	int i;
	for (i=0; i < size; i++)
	{
		/* for each patient in the array (aka founded), create a patient item widget and add to the layout */
		PatientItemWidget *widget = new PatientItemWidget(QString(array[i]->patientId), QString(array[i]->name)+" "+ QString(array[i]->lastName), array[i]->city , array[i]->patientCode, this);
		widget->setFixedHeight(100);
		if (i==0) // fist item without border
			widget->setStyleSheet("border-style: hidden;");
		//QLabel *widget = new QLabel("foo", this);
		mainLayout->addWidget(widget);
	}
	
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->setSpacing(0);
	mainWidget->setContentsMargins(0,0,0,0);
	/* TODO: now it's not correct for horizontal layout */
	mainWidget->setLayout(mainLayout);
	scrollArea->setWidget(mainWidget);
	
	layout->addWidget(scrollArea);
	setLayout(layout);
	
}

ScrollFrame::~ScrollFrame() {}
