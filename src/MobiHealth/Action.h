#ifndef ACTION_H
#define ACTION_H

#include <QtGui/QWidget>

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QHBoxLayout>

#include "ui_Action.h"
#include "GenericStep.h"
#include "DescriptorHandler.h"

#include <vector>
using namespace std;

class ActionMenu;
class ButtonLabel;
class ChangePatientFooter;
class QLabel;

class Action : public QWidget
{
    Q_OBJECT

public:
    Action(DescriptorHandler * actionDescriptor_in, QWidget *parent = 0);
    ~Action();
    
    DescriptorHandler* getActionDescriptor();
    bool isLastStep();

private:
    Ui::ActionClass ui;
    
    /* identifier */
    QString ID;
    //QWidget *parent;
    DescriptorHandler *actionDescriptor;
    /* user interface widgets */
    ButtonLabel *nextButton;
    ButtonLabel *backButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QStackedLayout *stepsLayout;

    QLabel *loadingImage;
    
    /* action1 steps (will be an array) */
    vector<GenericStep*> steps;
    
    /* reference to the footer object */
    ChangePatientFooter *footer;
    
    void setBackgroundImage();
    void saveStep(GenericStep *);
        
public slots:
	/* action1 wizard slots */
	void nextStep();
	void preStep();
	void finishButtonSlot();
	
protected:
	virtual GenericStep * createStep(int stepNumber);
	
};

#endif // ACTION_H
