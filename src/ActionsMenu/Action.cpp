#include "Action.h"
#include "DescriptorElements.h"
#include <QTextEdit>
#include <QRadioButton>

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
	
	mainLayout->addLayout(stepsLayout);
	mainLayout->addLayout(buttonsLayout);
	
	/* Generate steps */
	int stepsQty = actionDescriptor->getStepsQty();
	
	GenericStep * step;
	for(int i=0; i<stepsQty; i++){
		step = createStep(i);
		if(step!=0)
			steps.push_back(step);
		stepsLayout->addWidget(step);
	}
	
	
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
		if(actionDescriptor->getStepType(stepNumber)=="in")
			isInput = true;
		
		return new GenericStep(isInput,actionDescriptor->getStepID(stepNumber),elements,this);
	}
	
	//TODO: handle this situation using an exception
	return 0;
}

/*
 * This method save the current state of a step. For now it only works with
 * the inputText and radio button elements, because images and recordings are
 * not yet implemented.
 */

void Action::saveStep(GenericStep * step_in){
	for(int i=0; step_in->getInputElement(i)!=0; i++){
		QWidget * inputWidg = step_in->getInputElement(i);
		
		QTextEdit * inputText = dynamic_cast<QTextEdit*>(inputWidg);
		QRadioButton * radioButton = dynamic_cast<QRadioButton*>(inputWidg);
		/* 
		 * TODO: images and recordings save. 
		 * 		HINT:
		 * 			Use something like
		 * 				Q<what you used to render image> * image = dynamic_cast<...*>(inputWidg);
		 * 				if(image != 0){
		 * 					string base64image = <convert the image in base 64>
		 *					actionDescriptor->setStepChildContent(step_in->getID(),image->objectName(),base64image);
		 *				}
		 *		Whortless to say that this step require that the image objectName is set to the ID of the corresponding 
		 *		element in the configuration file.
		 */
		
		
		if(inputText != 0){
			actionDescriptor->setStepChildContent(step_in->getID(),inputText->objectName(),inputText->toPlainText());
		}
		else if(radioButton != 0){
			QString isSelected = "false"; 
			if(radioButton->isChecked())
				isSelected = "true";
			actionDescriptor->setStepChildAttribute(step_in->getID(),radioButton->objectName(), QString("selected"), isSelected);
		}
	}
	actionDescriptor->saveToFS();
}

void Action::nextStep()
{
	/* If the action accepts inputs, then save the current state of the step */
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);

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

bool Action::close(){
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);
	return QWidget::close();
}

void Action::preStep()
{
	/* If the action accepts inputs, then save the current state of the step */
	GenericStep * step = dynamic_cast<GenericStep*>(stepsLayout->currentWidget());
	if(step->isInput())
		saveStep(step);
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
