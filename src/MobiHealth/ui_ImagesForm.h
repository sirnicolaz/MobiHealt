/********************************************************************************
** Form generated from reading UI file 'ImagesForm.ui'
**
** Created: Sun Apr 11 11:47:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESFORM_H
#define UI_IMAGESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagesFormClass
{
public:

    void setupUi(QWidget *ImagesFormClass)
    {
        if (ImagesFormClass->objectName().isEmpty())
            ImagesFormClass->setObjectName(QString::fromUtf8("ImagesFormClass"));
        ImagesFormClass->resize(400, 300);

        retranslateUi(ImagesFormClass);

        QMetaObject::connectSlotsByName(ImagesFormClass);
    } // setupUi

    void retranslateUi(QWidget *ImagesFormClass)
    {
        ImagesFormClass->setWindowTitle(QApplication::translate("ImagesFormClass", "ImagesForm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImagesFormClass: public Ui_ImagesFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESFORM_H
