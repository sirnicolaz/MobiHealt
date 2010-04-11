/********************************************************************************
** Form generated from reading UI file 'ImageWidget.ui'
**
** Created: Sun Apr 11 11:47:54 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWidgetClass
{
public:

    void setupUi(QWidget *ImageWidgetClass)
    {
        if (ImageWidgetClass->objectName().isEmpty())
            ImageWidgetClass->setObjectName(QString::fromUtf8("ImageWidgetClass"));
        ImageWidgetClass->resize(400, 300);

        retranslateUi(ImageWidgetClass);

        QMetaObject::connectSlotsByName(ImageWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ImageWidgetClass)
    {
        ImageWidgetClass->setWindowTitle(QApplication::translate("ImageWidgetClass", "ImageWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageWidgetClass: public Ui_ImageWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
