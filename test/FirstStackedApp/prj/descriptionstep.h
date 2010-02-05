#ifndef DESCRIPTIONSTEP_H
#define DESCRIPTIONSTEP_H

#include <QtGui/QWidget>
#include "ui_descriptionstep.h"

class QLabel;

class DescriptionStep : public QWidget
{
    Q_OBJECT

public:
    /* description step constructor */
    DescriptionStep(QWidget *parent = 0);
    ~DescriptionStep();

private:
    Ui::DescriptionStepClass ui;
    
    /* GUI private reference */
    QLabel *description;
};

#endif // DESCRIPTIONSTEP_H
