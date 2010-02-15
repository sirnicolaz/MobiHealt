#include "Action.h"
#include "DescriptorElements.h"

Action::Action(DescriptorHandler * actionDescriptor_in, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	actionDescriptor = actionDescriptor_in;
	ID = actionDescriptor->getActionId();
	/* start user interface adds */
	
	/* action1 wizard buttons (todo: dynamic!!!) */
	closeButton = new QPushButton(tr("Finish"), this);
	nextButton = new QPushButton(tr("Next"), this);
	backButton = new QPushButton(tr("Back"), this);
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
	
	/* Generate steps */
	int stepsQty = actionDescriptor->getStepsQty();
	GenericStep * step;
	for(int i=0; i<stepsQty; i++){
		step = createStep(i);
		if(step!=0)
			steps.push_back(step);
		stepsLayout->addWidget(step);
	}
	
	mainLayout->addLayout(stepsLayout);
	mainLayout->addLayout(buttonsLayout);
	
	
	/* set the main window layout */
	this->setLayout(mainLayout);
	
	/* finish user interface adds */
}

GenericStep * Action::createStep(int stepNumber){
	if(actionDescriptor != 0){
		int elementsQty = actionDescriptor->getStepChildsQty(stepNumber);
		
		vector<StepGenericElement*> elements;
		StepGenericElement * element;
		for(int i=0; i<elementsQty; i++){
			element = actionDescriptor->getStepChild(stepNumber,i);
			elements.push_back(element);
		}
		bool isInput = false;
		if(actionDescriptor->getStepType(stepNumber)=="true")
			isInput = true;
		
		return new GenericStep(isInput,elements,this);
	}
	
	//TODO: handle this situation using an exception
	return 0;
}

void Action::nextStep()
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

void Action::preStep()
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


/* Action destructor implementation */
Action::~Action()
{

}
