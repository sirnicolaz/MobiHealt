#ifndef DESCRIPTORHANDLER_H
#define DESCRIPTORHANDLER_H


#include <QDomDocument>
#include <QFile>

#include <iostream>
#include <fstream>

using namespace std;

class DescriptorHandler
{

public:
    DescriptorHandler(QString fileName);
    ~DescriptorHandler();
    QString getActionId();
    QString getActionTitle();
    QString getStepType(int stepNumber);
    QString getStepTitle(int stepNumber);
    QString getStepTitle(QString type);
    QString getStepChildType(int stepNumber, int childNumber);
    QString getStepChildContent(int stepNumber, int childNumber);
    QString getStepChildContent(int stepNumber, QString tag, int number = 0);
    QString getStepChildTagName(int stepNumber, int childNumber);

private:
    QDomDocument *doc;

protected:
    QDomElement getStep(int stepNumber);
};



#endif // DESCRIPTORHANDLER_H
