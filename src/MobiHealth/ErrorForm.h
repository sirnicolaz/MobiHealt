#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QtGui/QWidget>
#include "ui_ErrorForm.h"

class ErrorForm : public QWidget
{
    Q_OBJECT

public:
    ErrorForm(int error, QWidget *parent = 0);
    ~ErrorForm();

private:
    Ui::ErrorFormClass ui;
    void setBackgroundImage();
};

#endif // ERRORFORM_H
