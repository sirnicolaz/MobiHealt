#ifndef SIMPLEOPTIONSTEP_H
#define SIMPLEOPTIONSTEP_H

#include <QtGui/QWidget>
#include "ui_simpleoptionstep.h"

class QButtonGroup;
class QRadioButton;

class SimpleOptionStep : public QWidget
{
    Q_OBJECT

public:
    SimpleOptionStep(QWidget *parent = 0);
    ~SimpleOptionStep();

private:
    Ui::SimpleOptionStepClass ui;
    
    QButtonGroup *radioGroup;
    QRadioButton *option1;
    QRadioButton *option2;
    QRadioButton *option3;
};

#endif // SIMPLEOPTIONSTEP_H
