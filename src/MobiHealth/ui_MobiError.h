/********************************************************************************
** Form generated from reading UI file 'MobiError.ui'
**
** Created: Sun Apr 11 11:47:47 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOBIERROR_H
#define UI_MOBIERROR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MobiErrorClass
{
public:

    void setupUi(QWidget *MobiErrorClass)
    {
        if (MobiErrorClass->objectName().isEmpty())
            MobiErrorClass->setObjectName(QString::fromUtf8("MobiErrorClass"));
        MobiErrorClass->resize(400, 300);

        retranslateUi(MobiErrorClass);

        QMetaObject::connectSlotsByName(MobiErrorClass);
    } // setupUi

    void retranslateUi(QWidget *MobiErrorClass)
    {
        MobiErrorClass->setWindowTitle(QApplication::translate("MobiErrorClass", "MobiError", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MobiErrorClass: public Ui_MobiErrorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOBIERROR_H
