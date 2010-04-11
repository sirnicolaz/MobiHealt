/********************************************************************************
** Form generated from reading UI file 'SelectSearchMenu.ui'
**
** Created: Sun Apr 11 11:47:47 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSEARCHMENU_H
#define UI_SELECTSEARCHMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectSearchMenuClass
{
public:

    void setupUi(QWidget *SelectSearchMenuClass)
    {
        if (SelectSearchMenuClass->objectName().isEmpty())
            SelectSearchMenuClass->setObjectName(QString::fromUtf8("SelectSearchMenuClass"));
        SelectSearchMenuClass->resize(400, 300);

        retranslateUi(SelectSearchMenuClass);

        QMetaObject::connectSlotsByName(SelectSearchMenuClass);
    } // setupUi

    void retranslateUi(QWidget *SelectSearchMenuClass)
    {
        SelectSearchMenuClass->setWindowTitle(QApplication::translate("SelectSearchMenuClass", "SelectSearchMenu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectSearchMenuClass: public Ui_SelectSearchMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSEARCHMENU_H
