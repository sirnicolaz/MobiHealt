#include "descriptorhandler.h"
#include <QDomNode>

#define IO_ReadOnly QIODevice::ReadOnly

DescriptorHandler::DescriptorHandler(QString fileName)
{
    QFile file(fileName);

    if(!file.open(IO_ReadOnly)){
        cout<<"No files."<<endl<<"Exiting.."<<endl;
        return;
    }

    doc = new QDomDocument("descriptor");

    if(!doc->setContent(&file)){
        cout<<"File empty"<<endl<<"Exiting.."<<endl;
        file.close();
        return;
    }

    file.close();
}

QDomElement DescriptorHandler::getStep(int stepNumber){

    QDomElement e = doc->documentElement();

    int currentNode = 0;
    QDomNode n = e.firstChild();

    while(currentNode != stepNumber && !n.isNull()){
        currentNode ++;
        n = n.nextSibling();
    }

    if(!n.isNull() && !n.toElement().isNull()){
        return n.toElement();
    }
    QDomElement notFound;
    notFound.setAttribute("notFound",true);
    return notFound;
}

QString DescriptorHandler::getActionId(){
    QDomElement e = doc->documentElement();
    return e.attribute("id");
}

QString DescriptorHandler::getActionTitle(){
    QDomElement e = doc->documentElement();
    return e.attribute("title");
}

QString DescriptorHandler::getStepType(int stepNumber){

    QDomElement stepElement = this->getStep(stepNumber);
    if( stepElement.attribute("notFound").isNull() ){
        return stepElement.attribute("type");
    }
    return "";
}

QString DescriptorHandler::getStepTitle(int stepNumber){

    QDomElement stepElement = this->getStep(stepNumber);
    if( stepElement.attribute("notFound").isNull() ){
        return stepElement.attribute("title");
    }
    return "";
}

QString DescriptorHandler::getStepTitle(QString type){

    int currentIndex = 0;
    QDomElement stepElement = this->getStep(currentIndex);
    while( !stepElement.attribute("notFound").isNull() && stepElement.attribute("type") != type ){
       currentIndex ++;
       stepElement = this->getStep(currentIndex);
    }
    if(stepElement.attribute("notFound").isNull()){
        cout<<"Attribute type:"<<stepElement.attribute("type").toStdString()<<endl;
        return stepElement.attribute("title");
    }
    return "";

}

QString DescriptorHandler::getStepChildType(int stepNumber, int childNumber){
    return "";
}

QString DescriptorHandler::getStepChildContent(int stepNumber, int childNumber){
    return "";
}

QString DescriptorHandler::getStepChildContent(int stepNumber, QString tag, int number){
    QDomElement stepElement = this->getStep(stepNumber);
    if(stepElement.attribute("notFound").isNull()){
        QDomNode n = stepElement.firstChild();
        int num = 0;
        while(!n.isNull()){
            QDomElement e = n.toElement();
            if(!e.isNull() && e.tagName()==tag && num == number){
                return e.firstChild().nodeValue();
            }
            else if(e.tagName()=="tag" && num != number){
                num++;
            }
            n = n.nextSibling();
        }
    }
    return "";
}

QString DescriptorHandler::getStepChildTagName(int stepNumber, int childNumber){
    return "";
}

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

QString StepGenericElement::getElementName(){
	return el;
}

QString StepGenericElement::getId(){
	return id;
}

QString StepGenericElement::getType(){
	return type;
}

//Text class methods implementation
Text::Text(QString type_in, QString id_in, float width_in, int rows_in, Element el_in, QString content_in) :
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
		Text(type_in,id_in,width_in,rows_in,INPUTFIELD,content_in) {
	
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

Select::Select(QString type_in, QString id_in, bool mutex, Element el_in, QString content_in) :
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


Media::Media(QString type_in, QString id_in, QString caption_in, bool take_in, Element el_in, QString content_in) :
		StepGenericElement(type_in,id_in,el_in,content_in){
	this->caption = caption_in;
	this->take = take_in;
}

bool Media::isTake(){
	return this->take;
}

QString Media::getCaption(){
	return this->caption;
}

Image::Image(QString type_in, QString id_in, QString caption_in, bool take_in, float width_in, float height_in, QString content_in) :
		Media(type_in,id_in,caption_in,take_in,IMAGE){
	this->width = width_in;
	this->height = height_in;
}

float Image::getWidth(){
	return this->width;
}

float Image::getHeight(){
	return this->height;
}

Recording::Recording(QString type_in, QString id_in, QString caption_in, bool take_in, float dur_in, QString content_in) :
		Media(type_in,id_in,caption_in,take_in,RECORDING){
	this->dur = dur_in;
}

float Recording::getDur(){
	return this->getDur();
}

