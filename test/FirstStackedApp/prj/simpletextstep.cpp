#include "simpletextstep.h"

#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

SimpleTextStep::SimpleTextStep(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	/* step2 main layout */
	QVBoxLayout *mainLayout = new QVBoxLayout();
	
	/* step2 widgets */
	label = new QLabel("Text Edit", this);
	textBox1 = new QLineEdit(this);
	textBox2 = new QLineEdit(this);
	textBox3 = new QLineEdit(this);
	
	mainLayout->addWidget(label);
	mainLayout->addWidget(textBox1);
	mainLayout->addWidget(textBox2);
	mainLayout->addWidget(textBox3);
	
	setLayout(mainLayout);
	
}

SimpleTextStep::~SimpleTextStep()
{
	
}
