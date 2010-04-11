/********************************************************************************
** Form generated from reading UI file 'MobiHealth.ui'
**
** Created: Sun Apr 11 11:48:05 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOBIHEALTH_H
#define UI_MOBIHEALTH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MobiHealth
{
public:

    void setupUi(QWidget *MobiHealth)
    {
        if (MobiHealth->objectName().isEmpty())
            MobiHealth->setObjectName(QString::fromUtf8("MobiHealth"));
        MobiHealth->resize(400, 300);

        retranslateUi(MobiHealth);

        QMetaObject::connectSlotsByName(MobiHealth);
    } // setupUi

    void retranslateUi(QWidget *MobiHealth)
    {
        MobiHealth->setWindowTitle(QApplication::translate("MobiHealth", "MobiHealth", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MobiHealth: public Ui_MobiHealth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOBIHEALTH_H
