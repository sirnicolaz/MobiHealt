/********************************************************************************
** Form generated from reading UI file 'GenericStep.ui'
**
** Created: Mon Mar 1 11:48:27 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERICSTEP_H
#define UI_GENERICSTEP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenericStepClass
{
public:

    void setupUi(QWidget *GenericStepClass)
    {
        if (GenericStepClass->objectName().isEmpty())
            GenericStepClass->setObjectName(QString::fromUtf8("GenericStepClass"));
        GenericStepClass->resize(400, 300);

        retranslateUi(GenericStepClass);

        QMetaObject::connectSlotsByName(GenericStepClass);
    } // setupUi

    void retranslateUi(QWidget *GenericStepClass)
    {
        GenericStepClass->setWindowTitle(QApplication::translate("GenericStepClass", "GenericStep", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GenericStepClass: public Ui_GenericStepClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERICSTEP_H
