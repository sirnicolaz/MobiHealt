/********************************************************************************
** Form generated from reading UI file 'NotesForm.ui'
**
** Created: Sun Apr 11 11:48:02 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTESFORM_H
#define UI_NOTESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotesFormClass
{
public:

    void setupUi(QWidget *NotesFormClass)
    {
        if (NotesFormClass->objectName().isEmpty())
            NotesFormClass->setObjectName(QString::fromUtf8("NotesFormClass"));
        NotesFormClass->resize(400, 300);

        retranslateUi(NotesFormClass);

        QMetaObject::connectSlotsByName(NotesFormClass);
    } // setupUi

    void retranslateUi(QWidget *NotesFormClass)
    {
        NotesFormClass->setWindowTitle(QApplication::translate("NotesFormClass", "NotesForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NotesFormClass: public Ui_NotesFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTESFORM_H
