/********************************************************************************
** Form generated from reading UI file 'ErrorForm.ui'
**
** Created: Sun Apr 11 11:47:50 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORFORM_H
#define UI_ERRORFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorFormClass
{
public:

    void setupUi(QWidget *ErrorFormClass)
    {
        if (ErrorFormClass->objectName().isEmpty())
            ErrorFormClass->setObjectName(QString::fromUtf8("ErrorFormClass"));
        ErrorFormClass->resize(400, 300);

        retranslateUi(ErrorFormClass);

        QMetaObject::connectSlotsByName(ErrorFormClass);
    } // setupUi

    void retranslateUi(QWidget *ErrorFormClass)
    {
        ErrorFormClass->setWindowTitle(QApplication::translate("ErrorFormClass", "ErrorForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ErrorFormClass: public Ui_ErrorFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORM_H
