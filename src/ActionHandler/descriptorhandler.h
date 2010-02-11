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
    QString getActionId();
    QString getActionTitle();

    QString getStepID(int stepNumber);
    
    QString getStepType(int stepNumber);
    QString getStepType(QString ID);
    
    QString getStepTitle(int stepNumber);
    QString getStepTitle(QString ID);
    
    StepGenericElement * getStepChild(int stepNumber, int childNumber);
    StepGenericElement * getStepChild(QString stepID, int childNumber);
    StepGenericElement * getStepChild(int stepNumber, QString childID);
    StepGenericElement * getStepChild(QString stepID, QString childID);

private:
    QDomDocument *doc;

protected:
    QDomElement getStep(int stepNumber);
    Element getElementType(QDomElement el);
    QString getElementAttribute(QDomElement el, QString attribute);
    StepGenericElement * getElement(QDomElement e);
    QDomElement getStep(QString stepID);
};

#endif // DESCRIPTORHANDLER_H
