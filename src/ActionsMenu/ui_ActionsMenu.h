/********************************************************************************
** Form generated from reading UI file 'ActionsMenu.ui'
**
** Created: Mon Mar 1 11:48:28 2010
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

class Ui_ActionsMenu
{
public:

    void setupUi(QWidget *ActionsMenu)
    {
        if (ActionsMenu->objectName().isEmpty())
            ActionsMenu->setObjectName(QString::fromUtf8("ActionsMenu"));
        ActionsMenu->resize(400, 300);

        retranslateUi(ActionsMenu);

        QMetaObject::connectSlotsByName(ActionsMenu);
    } // setupUi

    void retranslateUi(QWidget *ActionsMenu)
    {
        ActionsMenu->setWindowTitle(QApplication::translate("ActionsMenu", "ActionsMenu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActionsMenu: public Ui_ActionsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONSMENU_H
