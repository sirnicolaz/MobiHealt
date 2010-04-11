/********************************************************************************
** Form generated from reading UI file 'creditswidget.ui'
**
** Created: Sun Apr 11 11:48:04 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITSWIDGET_H
#define UI_CREDITSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditsWidgetClass
{
public:

    void setupUi(QWidget *CreditsWidgetClass)
    {
        if (CreditsWidgetClass->objectName().isEmpty())
            CreditsWidgetClass->setObjectName(QString::fromUtf8("CreditsWidgetClass"));
        CreditsWidgetClass->resize(400, 300);

        retranslateUi(CreditsWidgetClass);

        QMetaObject::connectSlotsByName(CreditsWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *CreditsWidgetClass)
    {
        CreditsWidgetClass->setWindowTitle(QApplication::translate("CreditsWidgetClass", "CreditsWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreditsWidgetClass: public Ui_CreditsWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITSWIDGET_H
