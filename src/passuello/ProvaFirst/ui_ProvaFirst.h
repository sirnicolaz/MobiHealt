/********************************************************************************
** Form generated from reading UI file 'ProvaFirst.ui'
**
** Created: Thu 18. Feb 16:14:38 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROVAFIRST_H
#define UI_PROVAFIRST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProvaFirst
{
public:

    void setupUi(QWidget *ProvaFirst)
    {
        if (ProvaFirst->objectName().isEmpty())
            ProvaFirst->setObjectName(QString::fromUtf8("ProvaFirst"));
        ProvaFirst->resize(400, 300);

        retranslateUi(ProvaFirst);

        QMetaObject::connectSlotsByName(ProvaFirst);
    } // setupUi

    void retranslateUi(QWidget *ProvaFirst)
    {
        ProvaFirst->setWindowTitle(QApplication::translate("ProvaFirst", "ProvaFirst", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProvaFirst: public Ui_ProvaFirst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROVAFIRST_H
