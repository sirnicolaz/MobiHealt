/********************************************************************************
** Form generated from reading UI file 'ActionsMenu.ui'
**
** Created: Sun Apr 11 11:47:53 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONSMENU_H
#define UI_ACTIONSMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionsMenuClass
{
public:

    void setupUi(QWidget *ActionsMenuClass)
    {
        if (ActionsMenuClass->objectName().isEmpty())
            ActionsMenuClass->setObjectName(QString::fromUtf8("ActionsMenuClass"));
        ActionsMenuClass->resize(400, 300);

        retranslateUi(ActionsMenuClass);

        QMetaObject::connectSlotsByName(ActionsMenuClass);
    } // setupUi

    void retranslateUi(QWidget *ActionsMenuClass)
    {
        ActionsMenuClass->setWindowTitle(QApplication::translate("ActionsMenuClass", "ActionsMenu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActionsMenuClass: public Ui_ActionsMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONSMENU_H
