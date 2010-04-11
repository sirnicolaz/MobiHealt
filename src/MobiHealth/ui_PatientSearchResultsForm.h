/********************************************************************************
** Form generated from reading UI file 'PatientSearchResultsForm.ui'
**
** Created: Sun Apr 11 11:48:06 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTSEARCHRESULTSFORM_H
#define UI_PATIENTSEARCHRESULTSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientSearchResultsFormClass
{
public:

    void setupUi(QWidget *PatientSearchResultsFormClass)
    {
        if (PatientSearchResultsFormClass->objectName().isEmpty())
            PatientSearchResultsFormClass->setObjectName(QString::fromUtf8("PatientSearchResultsFormClass"));
        PatientSearchResultsFormClass->resize(400, 300);

        retranslateUi(PatientSearchResultsFormClass);

        QMetaObject::connectSlotsByName(PatientSearchResultsFormClass);
    } // setupUi

    void retranslateUi(QWidget *PatientSearchResultsFormClass)
    {
        PatientSearchResultsFormClass->setWindowTitle(QApplication::translate("PatientSearchResultsFormClass", "PatientSearchResultsForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PatientSearchResultsFormClass: public Ui_PatientSearchResultsFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTSEARCHRESULTSFORM_H
