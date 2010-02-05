#ifndef SIMPLETEXTSTEP_H
#define SIMPLETEXTSTEP_H

#include <QtGui/QWidget>
#include "ui_simpletextstep.h"

class QLabel;
class QLineEdit;

class SimpleTextStep : public QWidget
{
    Q_OBJECT

public:
    SimpleTextStep(QWidget *parent = 0);
    ~SimpleTextStep();

private:
    Ui::SimpleTextStepClass ui;
    
    QLabel *label;
    QLineEdit *textBox1;
    QLineEdit *textBox2;
    QLineEdit *textBox3;
    
};

#endif // SIMPLETEXTSTEP_H
