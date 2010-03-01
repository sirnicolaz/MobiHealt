#include "GenericStep.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QTextEdit>
#include <QRadioButton>
#include <QButtonGroup>

//Only for test
#include <iostream>
using namespace std;

GenericStep::GenericStep( bool isInput_in, QString ID_in, vector<StepGenericElement*> elements_in, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	inputStep = isInput_in;
	ID = ID_in; 
	QVBoxLayout * mainLayout = new QVBoxLayout();
	StepGenericElement * currentElement;
	//Loop through the elements
	for(int i = 0; i<elements_in.size(); i++){
	
		currentElement = elements_in.at(i);
		
		if(currentElement != 0){
			//Check the type of element
			switch(currentElement->getElementName()){
				case TEXT:
					
					Text * textElement = dynamic_cast<Text*>(currentElement);
					
					//Generating area where to insert the text
					QScrollArea * scrollArea = new QScrollArea();
					scrollArea->setWidgetResizable(true);
						
					//if(textElement->getWidth() != 0)
						//scrollArea->setFixedWidth(textElement->getWidth());
					//if(textElement->getRows() != 0)
						//scrollArea->setFixedHeight(textElement->getRows());
					
					QLabel *description = new QLabel(textElement->getContent(), this);
					description->setWordWrap(true);
					description->setAlignment(Qt::AlignJustify);
				
					scrollArea->setWidget(description);
					mainLayout->addWidget(scrollArea);
					break;
					
				case INPUTFIELD:
					
					Input * inputElement = dynamic_cast<Input*>(currentElement);
					
					//Generating a gridlayout where to put both the label and the field
					QGridLayout * inputContainerLayout = new QGridLayout(this);
					QWidget * inputContainer = new QWidget(this);
					
					QLabel * inputLabel = new QLabel(inputElement->getLabel(),this);
					QTextEdit * inputText = new QTextEdit(inputElement->getContent(),this);
					
					inputText->setObjectName(inputElement->getId());
					inputElements.push_back(inputText);
					
					if(inputElement->getWidth() != 0)
						inputText->setFixedHeight(inputElement->getWidth());
					if(inputElement->getRows() != 0)
						inputText->setFixedHeight(inputElement->getRows()*20);
					
					switch(inputElement->getPos()){
						case UP:
							inputContainerLayout->addWidget(inputLabel,0,0);
							inputContainerLayout->addWidget(inputText,1,0);
							break;
						case DOWN:
							inputContainerLayout->addWidget(inputLabel,1,0);
							inputContainerLayout->addWidget(inputText,0,0);
							break;
						case LEFT:
							inputContainerLayout->addWidget(inputLabel,0,0);
							inputContainerLayout->addWidget(inputText,0,1);
							break;
						case RIGHT:
							inputContainerLayout->addWidget(inputLabel,0,1);
							inputContainerLayout->addWidget(inputText,0,0);
							break;
						default : break;
							
					}
					inputContainer->setLayout(inputContainerLayout);										
					inputContainerLayout->setVerticalSpacing(1);
					mainLayout->addWidget(inputContainer);
					break;
				case IMAGE:
					/* TODO: Given an Image element, this part of the code should
					 * renderize a box (as big as width and height attributes say)
					 * containing the image. The base64 encoding of the image is given
					 * by the content of the element. Probably the most part of the times
					 * this functionality won't be required. The important thing to do
					 * is to renderize a button to snap the photo.
					 */
					break;
				case RECORDING:
					/* TODO:
					 * The stuff to do is exactly the same then the one of the image. The only 
					 * differenze is that you have to renderize a "record","play","pause" button
					 * to interact with the mobile recorder.
					 */
					break;
				case SELECT:
					Select * selectElement = dynamic_cast<Select*>(currentElement);
						QButtonGroup * radioGroup = new QButtonGroup();
						radioGroup->setExclusive(selectElement->isMutex());
						for(int j = 0; j < selectElement->getOptions().size(); j++){
							Select::Option optionElement = selectElement->getOption(j);
							QRadioButton * option = new QRadioButton(optionElement.getContent(), this);
							option->setChecked(optionElement.isSelected());
							
							//The object name is eventually used to retrive the object reference
							//(During the saving process).
							//So the ID in the configuration file MUST be unique.
							option->setObjectName(optionElement.getId());
							inputElements.push_back(option);
							radioGroup->addButton(option);
							mainLayout->addWidget(option);
						}
						
						
					break;
				default:
					//TODO: handle exception
					break;
			}
		}
	}
	this->setLayout(mainLayout);
	this->resize(400,600);
}

QString GenericStep::getID(){
	return ID;
}

bool GenericStep::isInput(){
	return inputStep;
}

QWidget * GenericStep::getInputElement(int pos){
	if(pos<inputElements.size()){
		return inputElements[pos];
	}
	
	//TODO:Handle with exception
	return 0;
}

GenericStep::~GenericStep()
{

}
