/********************************************************************************
** Form generated from reading UI file 'LoadingForm.ui'
**
** Created: Sun Apr 11 11:48:06 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGFORM_H
#define UI_LOADINGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingFormClass
{
public:

    void setupUi(QWidget *LoadingFormClass)
    {
        if (LoadingFormClass->objectName().isEmpty())
            LoadingFormClass->setObjectName(QString::fromUtf8("LoadingFormClass"));
        LoadingFormClass->resize(400, 300);

        retranslateUi(LoadingFormClass);

        QMetaObject::connectSlotsByName(LoadingFormClass);
    } // setupUi

    void retranslateUi(QWidget *LoadingFormClass)
    {
        LoadingFormClass->setWindowTitle(QApplication::translate("LoadingFormClass", "LoadingForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadingFormClass: public Ui_LoadingFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGFORM_H
