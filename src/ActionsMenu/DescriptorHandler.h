#ifndef DESCRIPTORHANDLER_H
#define DESCRIPTORHANDLER_H

/*
 * This class is supposed to be used as an xml action configuration file handler.
 * It gives methods to extract steps and childs information of the given document.
 */

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
    
    /* Get methods: every kind of element can be get using the ID of the element
     * or its position in the file. For example:
     * 		getStepTitle(3) takes the title of the step number 3.
     * An empty string as a returned value means that no elements has been selected.
     */
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

    /* Set methods: the same thing is for the set methods. They can use both che ids and
     * the numbers of the elements. For instance:
     * 		setStepChildContent("ImageStep", 3, "base64 Encoded Image") sets the content 
     * 		of the 3rd child of the	step "ImageStep" (the id) with "base64 Endoded Image". 
     */ 
    
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
    /*
     * These methods are used inside the class for helping retrive 
     * the elements inside the file.
     */
    QDomElement getStep(int stepNumber);
    QDomElement getStep(QString stepID);
    QDomElement getChild(int stepNumber, int childNumber);
    QDomElement getChild(QString stepID, int childNumber);
    QDomElement getChild(QString stepID, QString childID);
    QDomElement elementById(QDomNode startingNode, QString elementId);
    Element getElementType(QDomElement el);
    QString getElementAttribute(QDomElement el, QString attribute);
    StepGenericElement * getElement(QDomElement e);
    
    //Helpers
    HBufC16 * FName(char * string_in);
};

#endif // DESCRIPTORHANDLER_H
