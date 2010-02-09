/********************************************************************************
** Form generated from reading UI file 'ActionHandler.ui'
**
** Created: Sun Feb 7 16:23:49 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONHANDLER_H
#define UI_ACTIONHANDLER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionHandler
{
public:

    void setupUi(QWidget *ActionHandler)
    {
        if (ActionHandler->objectName().isEmpty())
            ActionHandler->setObjectName(QString::fromUtf8("ActionHandler"));
        ActionHandler->resize(400, 300);

        retranslateUi(ActionHandler);

        QMetaObject::connectSlotsByName(ActionHandler);
    } // setupUi

    void retranslateUi(QWidget *ActionHandler)
    {
        ActionHandler->setWindowTitle(QApplication::translate("ActionHandler", "ActionHandler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActionHandler: public Ui_ActionHandler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONHANDLER_H
