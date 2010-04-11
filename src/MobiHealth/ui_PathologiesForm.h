/********************************************************************************
** Form generated from reading UI file 'PathologiesForm.ui'
**
** Created: Sun Apr 11 11:47:56 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHOLOGIESFORM_H
#define UI_PATHOLOGIESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathologiesFormClass
{
public:

    void setupUi(QWidget *PathologiesFormClass)
    {
        if (PathologiesFormClass->objectName().isEmpty())
            PathologiesFormClass->setObjectName(QString::fromUtf8("PathologiesFormClass"));
        PathologiesFormClass->resize(400, 300);

        retranslateUi(PathologiesFormClass);

        QMetaObject::connectSlotsByName(PathologiesFormClass);
    } // setupUi

    void retranslateUi(QWidget *PathologiesFormClass)
    {
        PathologiesFormClass->setWindowTitle(QApplication::translate("PathologiesFormClass", "PathologiesForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PathologiesFormClass: public Ui_PathologiesFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHOLOGIESFORM_H
