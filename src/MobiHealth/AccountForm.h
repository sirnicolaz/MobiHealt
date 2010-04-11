#ifndef ACCOUNTFORM_H
#define ACCOUNTFORM_H

#include <QtGui/QWidget>
#include "ui_AccountForm.h"

class AccountForm : public QWidget
{
    Q_OBJECT

public:
    AccountForm(QWidget *parent = 0);
    ~AccountForm();

private:
    Ui::AccountFormClass ui;
};

#endif // ACCOUNTFORM_H
