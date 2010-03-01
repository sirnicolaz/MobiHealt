#ifndef GENERICSTEP_H
#define GENERICSTEP_H

#include <QtGui/QWidget>
#include "ui_GenericStep.h"
#include "DescriptorElements.h"
#include <vector>

using namespace std;

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
    GenericStep(bool isInput_in, QString ID_in, vector<StepGenericElement*> elements_in, QWidget *parent = 0);
    ~GenericStep();
    
    //TODO: get methods
    QWidget * getInputElement(int pos);
    QString getID();
    bool isInput();
protected:
    vector<QWidget*> inputElements;
private:
    Ui::GenericStepClass ui;
    QString ID;
    bool inputStep;
};



#endif // GENERICSTEP_H
