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

class Action : public QWidget
{
    Q_OBJECT

public:
    Action(DescriptorHandler * actionDescriptor_in, QWidget *parent = 0);
    ~Action();

private:
    Ui::ActionClass ui;
    
    /* identifier */
    QString ID;
    DescriptorHandler * actionDescriptor;
    /* user interface widgets */
    QPushButton *closeButton;
    QPushButton *nextButton;
    QPushButton *backButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QStackedLayout *stepsLayout;

    /* action1 steps (will be an array) */
    vector<GenericStep*> steps;
        
protected slots:
	/* action1 wizard slots */
	void nextStep();
	void preStep();

protected:
	virtual GenericStep * createStep(int stepNumber);
	
};

#endif // ACTION_H
