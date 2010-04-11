/********************************************************************************
** Form generated from reading UI file 'ImageItemWidget.ui'
**
** Created: Sun Apr 11 11:48:06 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEITEMWIDGET_H
#define UI_IMAGEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageItemWidgetClass
{
public:

    void setupUi(QWidget *ImageItemWidgetClass)
    {
        if (ImageItemWidgetClass->objectName().isEmpty())
            ImageItemWidgetClass->setObjectName(QString::fromUtf8("ImageItemWidgetClass"));
        ImageItemWidgetClass->resize(400, 300);

        retranslateUi(ImageItemWidgetClass);

        QMetaObject::connectSlotsByName(ImageItemWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ImageItemWidgetClass)
    {
        ImageItemWidgetClass->setWindowTitle(QApplication::translate("ImageItemWidgetClass", "ImageItemWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageItemWidgetClass: public Ui_ImageItemWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEITEMWIDGET_H
