#ifndef DESCRIPTORHANDLER_H
#define DESCRIPTORHANDLER_H

#include <QDomDocument>
#include <QFile>

#include <iostream>
#include <fstream>

#include "descriptorelements.h"

using namespace std;


class DescriptorHandler
{

public:
    DescriptorHandler(QString fileName);
    ~DescriptorHandler();
    
    //Get methods
    QString getActionId();
    QString getActionTitle();

    int getStepsQty();
    
    QString getStepID(int stepNumber);
    
    QString getStepType(int stepNumber);
    QString getStepType(QString ID);
    
    QString getStepTitle(int stepNumber);
    QString getStepTitle(QString ID);
    
    int getStepChildsQty(int stepNumber);
    int getStepChildsQty(QString stepID);
    
    StepGenericElement * getStepChild(int stepNumber, int childNumber);
    StepGenericElement * getStepChild(QString stepID, int childNumber);
    StepGenericElement * getStepChild(int stepNumber, QString childID);
    StepGenericElement * getStepChild(QString stepID, QString childID);

    //Set methods
    bool setStepChildAttribute(int stepNumber, int childNumber, QString attributeName_in, QString attributeName_value);
    bool setStepChildContent(int stepNumber, int childNumber, QString content);
    bool setStepChildAttribute(QString stepID, int childNumber, QString attributeName_in, QString attributeName_value);
    bool setStepChildAttribute(QString stepID, QString childID, QString attributeName_in, QString attributeName_value);
    bool setStepChildContent(QString stepID, int childNumber, QString content);
    bool setStepChildContent(QString stepID, QString childID, QString content);
    
    //Save
    bool saveToFS(QString fileName_in = "");
    
private:
    QDomDocument *doc;
    QString fileName;

protected:
    QDomElement getStep(int stepNumber);
    QDomElement getStep(QString stepID);
    QDomElement getChild(int stepNumber, int childNumber);
    QDomElement getChild(QString stepID, int childNumber);
    QDomElement getChild(QString stepID, QString childID);
    QDomElement elementById(QDomNode startingNode, QString elementId);
    Element getElementType(QDomElement el);
    QString getElementAttribute(QDomElement el, QString attribute);
    StepGenericElement * getElement(QDomElement e);
};

#endif // DESCRIPTORHANDLER_H
