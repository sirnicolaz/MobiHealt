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
