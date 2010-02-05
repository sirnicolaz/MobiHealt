/********************************************************************************
** Form generated from reading UI file 'action1.ui'
**
** Created: Mon Feb 1 17:21:26 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTION1_H
#define UI_ACTION1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Action1Class
{
public:

    void setupUi(QDialog *Action1Class)
    {
        if (Action1Class->objectName().isEmpty())
            Action1Class->setObjectName(QString::fromUtf8("Action1Class"));
        Action1Class->resize(400, 300);

        retranslateUi(Action1Class);

        QMetaObject::connectSlotsByName(Action1Class);
    } // setupUi

    void retranslateUi(QDialog *Action1Class)
    {
        Action1Class->setWindowTitle(QApplication::translate("Action1Class", "Action1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Action1Class: public Ui_Action1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTION1_H
