/********************************************************************************
** Form generated from reading UI file 'PatientSearchForm.ui'
**
** Created: Sun Apr 11 11:48:01 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTSEARCHFORM_H
#define UI_PATIENTSEARCHFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientSearchFormClass
{
public:

    void setupUi(QWidget *PatientSearchFormClass)
    {
        if (PatientSearchFormClass->objectName().isEmpty())
            PatientSearchFormClass->setObjectName(QString::fromUtf8("PatientSearchFormClass"));
        PatientSearchFormClass->resize(400, 300);

        retranslateUi(PatientSearchFormClass);

        QMetaObject::connectSlotsByName(PatientSearchFormClass);
    } // setupUi

    void retranslateUi(QWidget *PatientSearchFormClass)
    {
        PatientSearchFormClass->setWindowTitle(QApplication::translate("PatientSearchFormClass", "PatientSearchForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PatientSearchFormClass: public Ui_PatientSearchFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTSEARCHFORM_H
