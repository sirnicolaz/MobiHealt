/********************************************************************************
** Form generated from reading UI file 'mainmenuform.ui'
**
** Created: Mon 22. Feb 16:59:46 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUFORM_H
#define UI_MAINMENUFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuFormClass
{
public:

    void setupUi(QWidget *MainMenuFormClass)
    {
        if (MainMenuFormClass->objectName().isEmpty())
            MainMenuFormClass->setObjectName(QString::fromUtf8("MainMenuFormClass"));
        MainMenuFormClass->resize(400, 300);

        retranslateUi(MainMenuFormClass);

        QMetaObject::connectSlotsByName(MainMenuFormClass);
    } // setupUi

    void retranslateUi(QWidget *MainMenuFormClass)
    {
        MainMenuFormClass->setWindowTitle(QApplication::translate("MainMenuFormClass", "MainMenuForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainMenuFormClass: public Ui_MainMenuFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUFORM_H
