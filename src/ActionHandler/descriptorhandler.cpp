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

QDomElement DescriptorHandler::getStep(QString stepID){

    QDomElement e = doc->documentElement();

    QDomNode n = e.firstChild();

    while(!n.isNull() && !n.isNull() && n.toElement().attribute("id") != stepID){
        n = n.nextSibling();
    }

    if(!n.isNull() && !n.toElement().isNull() && n.toElement().attribute("id") == stepID){
        return n.toElement();
    }
    QDomElement notFound;
    notFound.setAttribute("notFound",true);
    return notFound;
}

Element DescriptorHandler::getElementType(QDomElement el){
	
	if(!el.isNull()){
		string tag = el.tagName().toStdString();
	
		if(tag=="text")
				return TEXT;
		else if(tag=="select")
				return SELECT;
		else if(tag=="image") 
				return IMAGE;
		else if(tag=="inputField")
				return INPUTFIELD;
		else if(tag=="option")
				return OPTION;
		else if(tag=="recording")
			return RECORDING;
	}
	
	return VOID;
}

QString DescriptorHandler::getElementAttribute(QDomElement el, QString attribute){
	if(!el.isNull()){
		return el.attribute(attribute);
	}
	
	return "";
}

StepGenericElement * DescriptorHandler::getElement(QDomElement e){ 

	StepGenericElement * element;
	Element el = this->getElementType(e);
	
	float width;
	int rows;
	bool take = false;
	float height;
	
	switch(el){
		case TEXT :
			width = this->getElementAttribute(e,"width").toFloat();
			rows = this->getElementAttribute(e,"rows").toInt();
			element = new Text(this->getElementAttribute(e,"type"),this->getElementAttribute(e,"id"),width, rows,e.firstChild().nodeValue());
			return element;
			
		case INPUTFIELD :
			width = this->getElementAttribute(e,"width").toFloat();
			rows = this->getElementAttribute(e,"rows").toInt();
			Position pos = UP;
			if(this->getElementAttribute(e,"layout")=="down")
				pos = DOWN;
			if(this->getElementAttribute(e,"layout")=="left")
				pos = LEFT;
			if(this->getElementAttribute(e,"layout")=="right")
				pos = RIGHT;
			
			element = new Input(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), width, rows, this->getElementAttribute(e,"label"), pos , e.firstChild().nodeValue());
			return element;

		case SELECT :
			bool mutex = false;
			if(this->getElementAttribute(e,"mutex") == "true"){
				mutex = true;
			}
			element = new Select( this->getElementAttribute(e,"type"),  this->getElementAttribute(e,"id"), mutex , e.firstChild().nodeValue());
			QDomElement opt_el = e.firstChildElement("option");
			Select * tmp_sel = dynamic_cast<Select*>(element);
			while(!opt_el.isNull()){
				Select::Option opt(this->getElementAttribute(opt_el,"type"), this->getElementAttribute(opt_el,"id"), this->getElementAttribute(opt_el,"value"), e.firstChild().nodeValue());
				tmp_sel->addOption(opt);
			}
			tmp_sel->getOption(0).setSelected(true);
			return element;
			
		case IMAGE:
			width = this->getElementAttribute(e,"width").toFloat();
			height = this->getElementAttribute(e,"height").toFloat();
			
			if(this->getElementAttribute(e,"snap")=="true")
					take = true;
			
			element = new Image(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), this->getElementAttribute(e,"caption"), take, width, height, e.firstChild().nodeValue());
			return element;
			
		case RECORDING:
			float dur = this->getElementAttribute(e,"dur").toFloat();
			
			if(this->getElementAttribute(e,"rec")=="true")
					take = true;
			
			element = new Recording(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), this->getElementAttribute(e,"caption"), take, dur, e.firstChild().nodeValue());
			return element;
			
		default:
			break;
	}
	return element;
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

StepGenericElement * DescriptorHandler::getStepChild(int stepNumber, int childNumber){
	 QDomElement stepElement = this->getStep(stepNumber);
	    if(stepElement.attribute("notFound").isNull()){
	        QDomNode n = stepElement.firstChild();
	        int num = 0;
	        while(!n.isNull()){
	            QDomElement e = n.toElement();
	            if(!e.isNull() && num == childNumber)
					return this->getElement(e);
	            n = n.nextSibling();
	            num++;
	        }
	    }
		StepGenericElement * element;
	    return element;
}
	    
StepGenericElement * DescriptorHandler::getStepChild(QString stepID, int childNumber){
	 QDomElement stepElement = this->getStep(stepID);
	    if(stepElement.attribute("notFound").isNull()){
	        QDomNode n = stepElement.firstChild();
	        int num = 0;
	        while(!n.isNull()){
	            QDomElement e = n.toElement();
	            if(!e.isNull() && num == childNumber)
					return this->getElement(e);
	            n = n.nextSibling();
	            num++;
	        }
	    }
		StepGenericElement * element;
	    return element;
}

StepGenericElement * DescriptorHandler::getStepChild(int stepNumber, QString childID){
	 QDomElement stepElement = this->getStep(stepNumber);
	    if(stepElement.attribute("notFound").isNull()){
	        QDomNode n = stepElement.firstChild();
	        while(!n.isNull()){
	            QDomElement e = n.toElement();
	            if(!e.isNull() && e.attribute("id") == childID)
					return this->getElement(e);
	            n = n.nextSibling();
	        }
	    }
		StepGenericElement * element;
	    return element;
}
StepGenericElement * DescriptorHandler::getStepChild(QString stepID, QString childID){
	 QDomElement stepElement = this->getStep(stepID);
	    if(stepElement.attribute("notFound").isNull()){
	        QDomNode n = stepElement.firstChild();
	        while(!n.isNull()){
	            QDomElement e = n.toElement();
	            if(!e.isNull() && e.attribute("id") == childID)
					return this->getElement(e);
	            n = n.nextSibling();
	        }
	    }
		StepGenericElement * element;
	    return element;
}

/*
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
*/ 

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
		Media(type_in,id_in,caption_in,take_in,content_in,IMAGE){
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
		Media(type_in,id_in,caption_in,take_in,content_in,RECORDING){
	this->dur = dur_in;
}

float Recording::getDur(){
	return this->getDur();
}

