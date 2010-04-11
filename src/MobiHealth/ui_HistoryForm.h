/********************************************************************************
** Form generated from reading UI file 'HistoryForm.ui'
**
** Created: Sun Apr 11 11:47:55 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYFORM_H
#define UI_HISTORYFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryFormClass
{
public:

    void setupUi(QWidget *HistoryFormClass)
    {
        if (HistoryFormClass->objectName().isEmpty())
            HistoryFormClass->setObjectName(QString::fromUtf8("HistoryFormClass"));
        HistoryFormClass->resize(400, 300);

        retranslateUi(HistoryFormClass);

        QMetaObject::connectSlotsByName(HistoryFormClass);
    } // setupUi

    void retranslateUi(QWidget *HistoryFormClass)
    {
        HistoryFormClass->setWindowTitle(QApplication::translate("HistoryFormClass", "HistoryForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistoryFormClass: public Ui_HistoryFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYFORM_H
