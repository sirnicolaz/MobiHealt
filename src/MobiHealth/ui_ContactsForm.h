/********************************************************************************
** Form generated from reading UI file 'ContactsForm.ui'
**
** Created: Sun Apr 11 11:47:56 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSFORM_H
#define UI_CONTACTSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactsFormClass
{
public:

    void setupUi(QWidget *ContactsFormClass)
    {
        if (ContactsFormClass->objectName().isEmpty())
            ContactsFormClass->setObjectName(QString::fromUtf8("ContactsFormClass"));
        ContactsFormClass->resize(400, 300);

        retranslateUi(ContactsFormClass);

        QMetaObject::connectSlotsByName(ContactsFormClass);
    } // setupUi

    void retranslateUi(QWidget *ContactsFormClass)
    {
        ContactsFormClass->setWindowTitle(QApplication::translate("ContactsFormClass", "ContactsForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactsFormClass: public Ui_ContactsFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSFORM_H
