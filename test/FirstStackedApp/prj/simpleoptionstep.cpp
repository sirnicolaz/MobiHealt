#include "simpleoptionstep.h"

#include <QButtonGroup>
#include <QRadioButton>
#include <QVBoxLayout>

SimpleOptionStep::SimpleOptionStep(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	
	/* create the radio groups */
	radioGroup = new QButtonGroup();
	
	option1 = new QRadioButton("Option 1", this);
	option2 = new QRadioButton("Option 2", this);
	option3 = new QRadioButton("Option 3", this);
	radioGroup->addButton(option1);
	radioGroup->addButton(option2);
	radioGroup->addButton(option3);
	option1->setChecked(true);
	
	mainLayout->addWidget(option1);
	mainLayout->addWidget(option2);
	mainLayout->addWidget(option3);
	
	setLayout(mainLayout);
	
}

SimpleOptionStep::~SimpleOptionStep()
{

}
