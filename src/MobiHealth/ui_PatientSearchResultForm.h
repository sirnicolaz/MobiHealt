/********************************************************************************
** Form generated from reading UI file 'PatientSearchResultForm.ui'
**
** Created: Sun Apr 11 11:48:00 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTSEARCHRESULTFORM_H
#define UI_PATIENTSEARCHRESULTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientSearchResultFormClass
{
public:

    void setupUi(QWidget *PatientSearchResultFormClass)
    {
        if (PatientSearchResultFormClass->objectName().isEmpty())
            PatientSearchResultFormClass->setObjectName(QString::fromUtf8("PatientSearchResultFormClass"));
        PatientSearchResultFormClass->resize(400, 300);

        retranslateUi(PatientSearchResultFormClass);

        QMetaObject::connectSlotsByName(PatientSearchResultFormClass);
    } // setupUi

    void retranslateUi(QWidget *PatientSearchResultFormClass)
    {
        PatientSearchResultFormClass->setWindowTitle(QApplication::translate("PatientSearchResultFormClass", "PatientSearchResultForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PatientSearchResultFormClass: public Ui_PatientSearchResultFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTSEARCHRESULTFORM_H
