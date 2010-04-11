#include "DescriptorHandler.h"
#include <QDomNode>
#include <QFile>
#include <QTextStream>
//#include <s32file.h>
//#include <f32file.h> 
//#include <aknviewappui.h> 
//#include <EIKENV.H>
#include <string.h>
//#include <E32SVR.H>
//#include <utf.h>

#define IO_ReadOnly QIODevice::ReadOnly

//For test only
#include <iostream>
using namespace std;

/*
HBufC16 * DescriptorHandler::FName(char* string_in)
{
       TPtr8 tFileName8((unsigned char*)string_in, strlen(string_in), strlen(string_in));
       HBufC* tFileName = CnvUtfConverter::ConvertToUnicodeFromUtf8L(tFileName8);
       HBufC16 * iFileName = tFileName->AllocL();
       delete tFileName;
       return iFileName;
}
*/

DescriptorHandler::DescriptorHandler(QString fileName)
{
	/*
	RFile file;
	RFs iFs;
	iFs = CEikonEnv::Static()->FsSession();
	*/
	/* OLD version: it took a static file name. I keep it here commented just to be sure. */
    //RFileWriteStream base64File;
    //base64File.Replace(iFs,_L("test.txt"),EFileWrite|EFileStream);
    //TODO: convert fileName in something can be accepted by _L
	//TInt err = file.Open(iFs,_S(fileName),EFileRead|EFileStream); //-->to test
	//TInt err = file.Open(iFs,_L("action-descriptor.xml"),EFileRead|EFileStream);
	//this->fileName = "action-descriptor.xml";	
	//QFile file(fileName);
	
    /* OLD VERSION 
    const string fileNameString = fileName.toStdString();
	char * fileNameCharStar = new char[fileNameString.size()];
	
	strcpy(fileNameCharStar,fileNameString.c_str());
	HBufC16 * fileNameBuf = FName(fileNameCharStar);
	
    TInt err = file.Open(iFs , fileNameBuf->Des() , EFileRead | EFileStream);
	
    if(err != KErrNone){
        cout<<"Error: "<< err << endl <<"Exiting.."<<endl;
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
    */
    
	/* inizialize the fileName field */
    this->fileName = fileName;
	
    /* QT VERSION */
    //: read the configuration file 
	QFile file(fileName);
	file.open(QIODevice::ReadOnly);
	//QTextStream in(&file);
	//QString qtext = in.readAll();
	
	//QDomDocument doc("mydocument");
	//QFile file("mydocument.xml");
	//if (!file.open(QIODevice::ReadOnly))
	//    return;
	//if (!doc.setContent(&file)) {
	//    file.close();
	//    return;
	//}
	//file.close();
	
    
    QString * error = new QString("");
    
    doc = new QDomDocument(fileName);

    //int xmlEnd = qtext.lastIndexOf("</action>") + 9;
    //qtext.remove(xmlEnd, qtext.size() - xmlEnd);
    
    if(!doc->setContent(&file)){
        cout<<"Error parsing xml:"<<endl<<error->toStdString()<<endl<<"Exiting.."<<endl;
        //file.Close();
        return;
    }
    //XML ok
    file.close();
}

int DescriptorHandler::getStepsQty(){
	QDomElement e = getStep(0);
	int stepsQty = 0;
	while(e.tagName()!=""){
		stepsQty++;
		e = getStep(stepsQty);
	}
	return stepsQty;
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
    return notFound;
}

QString DescriptorHandler::getStepID(int stepNumber){
	QDomElement step = getStep(stepNumber);
	return step.attribute("id");
}



QDomElement DescriptorHandler::elementById(QDomNode startingNode, QString elementID){
	
	QDomElement nullElement;
	
	if(startingNode.isNull())
		return nullElement;
	
	if(startingNode.toElement().isNull())
		return nullElement;
	
	if(startingNode.toElement().attribute("id")==elementID)
		return startingNode.toElement();
	
	QDomElement childsSearchElement = elementById(startingNode.firstChild(),elementID);
	if(childsSearchElement.tagName()==0){
		return elementById(startingNode.nextSibling(),elementID);
	}
	
	return childsSearchElement;
}

QDomElement DescriptorHandler::getChild(int stepNumber, int childNumber){

	QDomElement step = getStep(stepNumber);
	
	if(step.tagName()!=""){
		int index = 0;
		QDomNode child = step.firstChild();
		while(index != childNumber && !child.isNull()){
			child = child.nextSibling();
		}
		
		if(!child.isNull() && !child.toElement().isNull())
			return child.toElement();
	}
	
    QDomElement notFound;
    return notFound;
}

QDomElement DescriptorHandler::getChild(QString stepID, int childNumber){

	QDomElement step = getStep(stepID);
	
	if(step.tagName()!=""){
		int index = 0;
		QDomNode child = step.firstChild();
		while(index != childNumber && !child.isNull()){
			child = child.nextSibling();
		}
		
		if(!child.isNull() && !child.toElement().isNull())
			return child.toElement();
	}
	
    QDomElement notFound;
    return notFound;
}

QDomElement DescriptorHandler::getChild(QString stepID, QString childID)
{
	/* get the step */
	QDomElement step = getStep(stepID);
	if(step.tagName() != ""){
		QDomNode child = step.firstChild();
		return elementById(child,childID);
	}
    QDomElement notFound;
    return notFound;
}

QDomElement DescriptorHandler::getStep(QString stepID)
{
    QDomElement e = doc->documentElement();

    QDomNode n = e.firstChild();

    while(!n.isNull() && !n.isNull() && n.toElement().attribute("id") != stepID){
        n = n.nextSibling();
    }

    if(!n.isNull() && !n.toElement().isNull() && n.toElement().attribute("id") == stepID){
        return n.toElement();
    }
    QDomElement notFound;
    notFound.setAttribute("notFound","true");
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

/* given a dom step element, return the corresponding stepGenericElement */
StepGenericElement * DescriptorHandler::getElement(QDomElement e){ 

	StepGenericElement * element;
	/* get the element type (text, input...) */
	Element el = this->getElementType(e);
	
	float width;
	int rows;
	bool take = false;
	float height;
	
	/* variable declaration */
	Position pos;
	bool mutex;
	QDomElement opt_el;
	
	/* if the element is a... */
	switch(el) {
		case TEXT :
			/* get the dimensions of the text area and return the element */
			width = this->getElementAttribute(e,"width").toFloat();
			rows = this->getElementAttribute(e,"rows").toInt();
			element = new Text(this->getElementAttribute(e,"type"),this->getElementAttribute(e,"id"),width, rows,e.firstChild().nodeValue());
			return element;
			
		case INPUTFIELD :
			/* get the dimensions of the input text area and return the element */
			width = this->getElementAttribute(e,"width").toFloat();
			rows = this->getElementAttribute(e,"rows").toInt();
			
			pos = UP;
			if(this->getElementAttribute(e,"layout")=="down")
				pos = DOWN;
			if(this->getElementAttribute(e,"layout")=="left")
				pos = LEFT;
			if(this->getElementAttribute(e,"layout")=="right")
				pos = RIGHT;
			
			element = new Input(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), width, rows, this->getElementAttribute(e,"label"), pos , e.firstChild().nodeValue());
			return element;

		case SELECT :
			mutex = false;
			if(this->getElementAttribute(e,"mutex") == "true"){
				mutex = true;
			}
			element = new Select( this->getElementAttribute(e,"type"),  this->getElementAttribute(e,"id"), mutex , e.firstChild().nodeValue());
			opt_el = e.firstChildElement("option");
			Select * tmp_sel = dynamic_cast<Select*>(element);
			if(tmp_sel != 0){
				while(!opt_el.isNull()){
					Select::Option opt(this->getElementAttribute(opt_el,"type"), this->getElementAttribute(opt_el,"id"), this->getElementAttribute(opt_el,"value"), opt_el.text());
					tmp_sel->addOption(opt);
					opt_el = opt_el.nextSiblingElement("option");
				}
				//TODO: verify that there is an option to select
				tmp_sel->getOption(0).setSelected(true);
			}
			return element;
			
		case IMAGE:
			/* in case of an image, the wizard have to show only a text and a button so the element to return is the text */
			//width = this->getElementAttribute(e,"width").toFloat();
			//height = this->getElementAttribute(e,"height").toFloat();
			
			//if(this->getElementAttribute(e,"snap")=="true")
			//		take = true;
			
			//element = new Image(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), this->getElementAttribute(e,"caption"), take, width, height, e.firstChild().nodeValue());
			
			/* construct the Image element passing the text in the xml as content */
			//element = new Image(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), "", false, 0, 0, e.firstChild().nodeValue());
			element = new Text(this->getElementAttribute(e,"type"), this->getElementAttribute(e,"id"), 0, 0, e.firstChild().nodeValue());
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
	//TODO: don't return null!!!!
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

int DescriptorHandler::getStepChildsQty(int stepNumber){
	QDomElement stepElement = this->getStep(stepNumber);
	int childsQty = 0;
	bool exit = false;
	QDomElement stepChildElement = stepElement.firstChild().toElement();
	while(!stepChildElement.isNull() && !exit){
			childsQty++;
		if(!stepChildElement.nextSibling().isNull())
			stepChildElement = stepChildElement.nextSibling().toElement();
		else
			exit = true;
	}
	return childsQty;
}

int DescriptorHandler::getStepChildsQty(QString stepID){
	QDomElement stepElement = this->getStep(stepID);
	int childsQty = 0;
	bool exit = false;
	QDomElement stepChildElement = stepElement.firstChild().toElement();
	while(!stepChildElement.isNull() && !exit){
			childsQty++;
		if(!stepChildElement.nextSibling().isNull())
			stepChildElement = stepChildElement.nextSibling().toElement();
		else
			exit = true;
	}
	return childsQty;
	
}

/* return the generic step element  of the childNumber-th child of the stepNumber-th step*/
StepGenericElement * DescriptorHandler::getStepChild(int stepNumber, int childNumber)
{
	/* get the step xml element */
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
	/* if error in parsing... */
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


bool DescriptorHandler::setStepChildAttribute(int stepNumber, int childNumber, QString attributeName_in, QString attributeValue_in){
	QDomElement child = getChild(stepNumber,childNumber);
	child.setAttribute(attributeName_in,attributeValue_in);
	return true;
}

bool DescriptorHandler::setStepChildContent(int stepNumber, int childNumber, QString content){
	QDomElement child = getChild(stepNumber,childNumber);
	child.firstChild().setNodeValue(content);
	return true;
}

bool DescriptorHandler::setStepChildAttribute(QString stepID, int childNumber, QString attributeName_in, QString attributeValue_in){
	QDomElement child = getChild(stepID,childNumber);
	child.setAttribute(attributeName_in,attributeValue_in);
	return true;
}

bool DescriptorHandler::setStepChildAttribute(QString stepID, QString childID, QString attributeName_in, QString attributeValue_in){
	QDomElement child = getChild(stepID,childID);
	child.setAttribute(attributeName_in,attributeValue_in);
	return true;
}

bool DescriptorHandler::setStepChildContent(QString stepID, int childNumber, QString content){
	QDomElement child = getChild(stepID,childNumber);
	child.firstChild().setNodeValue(content);
	return true;
}

bool DescriptorHandler::setStepChildContent(QString stepID, QString childID, QString content){
	QDomElement child = getChild(stepID,childID);
	child.firstChild().setNodeValue(content);
	return true;
}
/*
/* save to FS the xml (now the xml is the input xml!)
bool DescriptorHandler::saveToFS(QString fileName_in)
{
	QString fileN = fileName_in;
	if(fileN == "")
		fileN = fileName;
	
	RFs iFs;
	iFs = CEikonEnv::Static()->FsSession();	
	
	RFileWriteStream saveFile;
	
	string prefix = "save-";
    const string fileNameString = prefix.append(fileName.toStdString());
	char * fileNameCharStar = new char[fileNameString.size()];
	
	strcpy(fileNameCharStar,fileNameString.c_str());
	HBufC16 * fileNameBuf = FName(fileNameCharStar);
	
	saveFile.Replace(iFs,  fileNameBuf->Des(),EFileWrite|EFileStream);
	
	const string documentString = doc->toString(1).toStdString();
	char * document = new char[documentString.size()];
	
	strcpy(document,documentString.c_str());
	
	TText * output = (TText*)document;
	TPtrC ptr(output);
	saveFile.WriteL(ptr);
	     
	saveFile.Close();
	
	return true;
}
*/

QDomDocument* DescriptorHandler::getXmlDocument()
{
	return doc;
}
