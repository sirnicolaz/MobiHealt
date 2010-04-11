/********************************************************************************
** Form generated from reading UI file 'AccountForm.ui'
**
** Created: Sun Apr 11 11:48:00 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTFORM_H
#define UI_ACCOUNTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountFormClass
{
public:

    void setupUi(QWidget *AccountFormClass)
    {
        if (AccountFormClass->objectName().isEmpty())
            AccountFormClass->setObjectName(QString::fromUtf8("AccountFormClass"));
        AccountFormClass->resize(400, 300);

        retranslateUi(AccountFormClass);

        QMetaObject::connectSlotsByName(AccountFormClass);
    } // setupUi

    void retranslateUi(QWidget *AccountFormClass)
    {
        AccountFormClass->setWindowTitle(QApplication::translate("AccountFormClass", "AccountForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccountFormClass: public Ui_AccountFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTFORM_H
