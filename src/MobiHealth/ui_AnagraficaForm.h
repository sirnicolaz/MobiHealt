/********************************************************************************
** Form generated from reading UI file 'AnagraficaForm.ui'
**
** Created: Sun Apr 11 11:47:58 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANAGRAFICAFORM_H
#define UI_ANAGRAFICAFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnagraficaFormClass
{
public:

    void setupUi(QWidget *AnagraficaFormClass)
    {
        if (AnagraficaFormClass->objectName().isEmpty())
            AnagraficaFormClass->setObjectName(QString::fromUtf8("AnagraficaFormClass"));
        AnagraficaFormClass->resize(400, 300);

        retranslateUi(AnagraficaFormClass);

        QMetaObject::connectSlotsByName(AnagraficaFormClass);
    } // setupUi

    void retranslateUi(QWidget *AnagraficaFormClass)
    {
        AnagraficaFormClass->setWindowTitle(QApplication::translate("AnagraficaFormClass", "AnagraficaForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnagraficaFormClass: public Ui_AnagraficaFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAGRAFICAFORM_H
