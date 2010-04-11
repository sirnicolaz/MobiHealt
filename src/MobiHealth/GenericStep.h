#ifndef GENERICSTEP_H
#define GENERICSTEP_H

#include <QtGui/QWidget>
#include "ui_GenericStep.h"
#include "DescriptorElements.h"
#include "DescriptorHandler.h"
#include <vector>

using namespace std;

class Action;

/*This class represents the simplest kind of step. In this step
 *the elements are simply renderized in the order they are given.
 *If the step is supposed to contain input fields ( bool inputStep = 3 ),
 *then some get methods will allow the client to obtain the correspondent
 *values
*/

class GenericStep : public QWidget
{
    Q_OBJECT

public:
    GenericStep(QString isInput_in, QString ID_in, vector<StepGenericElement*> elements_in, QWidget *parent, DescriptorHandler *descriptor);
    ~GenericStep();
    
    //TODO: get methods
    QWidget * getInputElement(int pos);
    QString getID();
    bool isInput();
protected:
    vector<QWidget*> inputElements;
private slots:
	void yesSlot();
	void noSlot();
	void showViewFinderWidgetSlot();

private:
    Ui::GenericStepClass ui;
    QString ID;
    bool inputStep;
    DescriptorHandler *descriptor;
    Action *action;
};



#endif // GENERICSTEP_H
