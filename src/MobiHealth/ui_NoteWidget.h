/********************************************************************************
** Form generated from reading UI file 'NoteWidget.ui'
**
** Created: Sun Apr 11 11:47:53 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEWIDGET_H
#define UI_NOTEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteWidgetClass
{
public:

    void setupUi(QWidget *NoteWidgetClass)
    {
        if (NoteWidgetClass->objectName().isEmpty())
            NoteWidgetClass->setObjectName(QString::fromUtf8("NoteWidgetClass"));
        NoteWidgetClass->resize(400, 300);

        retranslateUi(NoteWidgetClass);

        QMetaObject::connectSlotsByName(NoteWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *NoteWidgetClass)
    {
        NoteWidgetClass->setWindowTitle(QApplication::translate("NoteWidgetClass", "NoteWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NoteWidgetClass: public Ui_NoteWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEWIDGET_H
