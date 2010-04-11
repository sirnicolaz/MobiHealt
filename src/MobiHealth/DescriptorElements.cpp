/*

 * descriptorelements.cpp

 *

 *  Created on: Feb 11, 2010

 *      Author: Jack

 *  

 *  The package contains a collection of classes that are supposed to represent

 *  a step object. They are an high level abstraction of the elements that

 *  may be found in the xml step configuration file.

 */



#include "DescriptorElements.h"



//StepGenericElement methods implementation







StepGenericElement::StepGenericElement(QString type_in, QString id_in, Element el_in, QString content_in){

	this->type = type_in; 

	this->el = el_in;

	this->id = id_in;

	this->content = content_in;

}



QString StepGenericElement::getContent(){

	return content;

}



Element StepGenericElement::getElementName(){

	return el;

}



QString StepGenericElement::getId(){

	return id;

}



QString StepGenericElement::getType(){

	return type;

}



//Text class methods implementation

Text::Text(QString type_in, QString id_in, float width_in, int rows_in, QString content_in, Element el_in) :

	StepGenericElement(type_in,id_in,el_in,content_in) {

	

	this->width = width_in;

	this->rows = rows_in;

	

}



float Text::getWidth(){

	return width;

}



int Text::getRows(){

	return rows;

}



//Input class methods implementation



Input::Input(QString type_in, QString id_in, float width_in, int rows_in, QString label_in, Position pos_in, QString content_in) :

		Text(type_in,id_in,width_in,rows_in,content_in,INPUTFIELD) {

	

	this->label = label_in;

	this->pos = pos_in;

}

	

QString Input::getLabel(){

	return this->label;

}



Position Input::getPos(){

	return this->pos;

}



//Select class methods implementation



Select::Select(QString type_in, QString id_in, bool mutex, QString content_in, Element el_in) :

		StepGenericElement(type_in,id_in,el_in,content_in){

	

	this->mutex = mutex;

	

}



void Select::addOption(Select::Option opt_in){

	opt_in.setFather(this);

	this->options_list.push_back(opt_in);

}



Select::Option Select::getOption(QString ID){

	

	for(int i = 0; i<this->options_list.size(); i++){

		if(this->options_list[i].id == ID)

			return this->options_list[i];

	}

	

	Select::Option nullOpt("","","","");

	nullOpt.id = "-1";

	

	return nullOpt;

	

}



Select::Option Select::getOption(int num){

	if(num < this->options_list.size()){

		return this->options_list[num];

	}



	Select::Option nullOpt("","","","");

	nullOpt.id = "-1";

	

	return nullOpt;

}



vector<Select::Option> Select::getOptions(){

	return this->options_list;

}



bool Select::isMutex(){

	return this->mutex;

}





Select::Option::Option(QString type_in, QString id_in, QString value_in, QString content_in) :

		StepGenericElement(type_in,id_in,OPTION,content_in){

	this->value = value_in;

}



bool Select::Option::isSelected(){

	return this->selected;

}



QString Select::Option::getValue(){

	return this->value;

}



void Select::Option::setFather(Select * father_in){

	father = father_in;

}



void Select::Option::setSelected(bool selected_in){

	selected = selected_in;

}





Media::Media(QString type_in, QString id_in, QString caption_in, bool take_in, QString content_in, Element el_in) :

		StepGenericElement(type_in,id_in,el_in,content_in){

	this->caption = caption_in; // ""

	this->take = take_in; // false

}



bool Media::isTake(){

	return this->take;

}



QString Media::getCaption(){

	return this->caption;

}



Image::Image(QString type_in, QString id_in, QString caption_in, bool take_in, float width_in, float height_in, QString content_in) :

		Media(type_in,id_in,caption_in,take_in,content_in,IMAGE){

	this->width = width_in; // 0

	this->height = height_in; // 0

}



float Image::getWidth(){

	return this->width;

}



float Image::getHeight(){

	return this->height;

}



Recording::Recording(QString type_in, QString id_in, QString caption_in, bool take_in, float dur_in, QString content_in) :

		Media(type_in,id_in,caption_in,take_in,content_in,RECORDING){

	this->dur = dur_in;

}



float Recording::getDur(){

	return this->dur;

}

StepGenericElement::~StepGenericElement() {}

Text::~Text() {}

Input::~Input() {}

Select::~Select() {}

Select::Option::~Option() {}

Media::~Media() {}

Image::~Image() {}

Recording::~Recording() {}
