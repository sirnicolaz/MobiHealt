/********************************************************************************
** Form generated from reading UI file 'Action.ui'
**
** Created: Tue Feb 23 09:20:09 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTION_H
#define UI_ACTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionClass
{
public:

    void setupUi(QWidget *ActionClass)
    {
        if (ActionClass->objectName().isEmpty())
            ActionClass->setObjectName(QString::fromUtf8("ActionClass"));
        ActionClass->resize(240, 242);

        retranslateUi(ActionClass);

        QMetaObject::connectSlotsByName(ActionClass);
    } // setupUi

    void retranslateUi(QWidget *ActionClass)
    {
        ActionClass->setWindowTitle(QApplication::translate("ActionClass", "Action", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActionClass: public Ui_ActionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTION_H
