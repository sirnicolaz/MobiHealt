#include "action1widget.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QHBoxLayout>
#include "descriptionstep.h"
#include "simpletextstep.h"
#include "simpleoptionstep.h"

/* action1 widget constructor implementation */
Action1Widget::Action1Widget(QWidget *parent)
    : QWidget(parent)
{
	/* setup user interface from QtDesigner settings (nothing) */
	ui.setupUi(this);
	
/* start user interface adds */

	/* action1 wizard buttons (todo: dynamic!!!) */
	closeButton = new QPushButton(tr("Close"), this);
	nextButton = new QPushButton(tr("Next"), this);
	backButton = new QPushButton(tr("Pre"), this);
	backButton->setEnabled(false);
	
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(backButton, SIGNAL(clicked()), this, SLOT(preStep()));
	connect(nextButton, SIGNAL(clicked()), this, SLOT(nextStep()));
	
	
	
	/* layout managers */
	mainLayout = new QVBoxLayout();
	stepsLayout = new QStackedLayout();
	buttonsLayout = new QHBoxLayout();
	
	buttonsLayout->addWidget(closeButton);
	buttonsLayout->addWidget(backButton);
	buttonsLayout->addWidget(nextButton);
	
	mainLayout->addLayout(stepsLayout);
	mainLayout->addLayout(buttonsLayout);
	
	stepsLayout->addWidget(new DescriptionStep(this));
	stepsLayout->addWidget(new SimpleTextStep(this));
	stepsLayout->addWidget(new SimpleOptionStep(this));
	
	/* set the main window layout */
	this->setLayout(mainLayout);
	
/* finish user interface adds */
}

void Action1Widget::nextStep()
{
	/* increment the stacked layout index */
	stepsLayout->setCurrentIndex(stepsLayout->currentIndex() + 1);
	
	/* if current step is the last step, disable "next" button */
	if (stepsLayout->currentIndex() == stepsLayout->count() - 1)
	{
		nextButton->setEnabled(false);
	}
	
	/* if current step isn't the first step, enable the "back" button */
	if (stepsLayout->currentIndex() == 1)
	{
		backButton->setEnabled(true);
	}
}

void Action1Widget::preStep()
{
	/* decrement the stacked layout index */
	stepsLayout->setCurrentIndex(stepsLayout->currentIndex() - 1);
	
	/* if current step is the first, disable "back" button */
	if (stepsLayout->currentIndex() == 0)
	{
		backButton->setEnabled(false);
	}
	
	/* if current step isn't the last step, enable "next" button */
	if (stepsLayout->currentIndex() == stepsLayout->count() - 2)
	{
		nextButton->setEnabled(true);
	}
}


/* action1 widget destructor implementation */
Action1Widget::~Action1Widget()
{
}
