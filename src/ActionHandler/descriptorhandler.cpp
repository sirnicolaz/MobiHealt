#include "descriptorhandler.h"
#include <QDomNode>
#include <s32file.h>
#include <f32file.h> 
#include <aknviewappui.h> 
#include <EIKENV.H>

#define IO_ReadOnly QIODevice::ReadOnly


DescriptorHandler::DescriptorHandler(QString fileName)
{
	RFile file;
	RFs iFs;
	iFs = CEikonEnv::Static()->FsSession();
	
	TInt err = file.Open(iFs,_L("action-descriptor.xml"),EFileRead|EFileStream);
	
    //QFile file(fileName);
    if(err!=KErrNone){
        cout<<"No files."<<endl<<"Exiting.."<<endl;
        return;
    }

    TInt fileSize; 
    file.Size(fileSize);
    HBufC8* b = HBufC8::NewL(fileSize);
    TPtr8 dest  = b->Des();
    file.Read(dest,fileSize);
    
    TText * text_doc = (TText*)dest.Ptr();
    char* text = (char*)text_doc;
    
    QString qtext(text);
    QString * error = new QString("");
    
    doc = new QDomDocument(fileName);

    int xmlEnd = qtext.lastIndexOf("</action>")+9;
    qtext.remove(xmlEnd,qtext.size()-xmlEnd);
    
    if(!doc->setContent(qtext,error)){
        cout<<"Error parsing xml:"<<endl<<error->toStdString()<<endl<<"Exiting.."<<endl;
        file.Close();
        return;
    }
    //XML ok
    file.Close();
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
