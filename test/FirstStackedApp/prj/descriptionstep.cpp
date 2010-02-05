#include "descriptionstep.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>


DescriptionStep::DescriptionStep(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
/* start GUI adds */

	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setWidgetResizable(true);

	description = new QLabel("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillu" , this);
	description->setWordWrap(true);
	description->setAlignment(Qt::AlignJustify);
	
	scrollArea->setWidget(description);
	
	QHBoxLayout *step1Layout = new QHBoxLayout();
	step1Layout->addWidget(scrollArea);
	setLayout(step1Layout);
	
/* end GUI adds */
}

DescriptionStep::~DescriptionStep()
{

}
