/********************************************************************************
** Form generated from reading UI file 'PatientMenuForm.ui'
**
** Created: Sun Apr 11 11:48:03 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMENUFORM_H
#define UI_PATIENTMENUFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMenuFormClass
{
public:

    void setupUi(QWidget *PatientMenuFormClass)
    {
        if (PatientMenuFormClass->objectName().isEmpty())
            PatientMenuFormClass->setObjectName(QString::fromUtf8("PatientMenuFormClass"));
        PatientMenuFormClass->resize(400, 300);

        retranslateUi(PatientMenuFormClass);

        QMetaObject::connectSlotsByName(PatientMenuFormClass);
    } // setupUi

    void retranslateUi(QWidget *PatientMenuFormClass)
    {
        PatientMenuFormClass->setWindowTitle(QApplication::translate("PatientMenuFormClass", "PatientMenuForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PatientMenuFormClass: public Ui_PatientMenuFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMENUFORM_H
