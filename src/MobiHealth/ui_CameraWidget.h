/********************************************************************************
** Form generated from reading UI file 'CameraWidget.ui'
**
** Created: Sun Apr 11 11:47:48 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWIDGET_H
#define UI_CAMERAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWidgetClass
{
public:

    void setupUi(QWidget *CameraWidgetClass)
    {
        if (CameraWidgetClass->objectName().isEmpty())
            CameraWidgetClass->setObjectName(QString::fromUtf8("CameraWidgetClass"));
        CameraWidgetClass->resize(400, 300);

        retranslateUi(CameraWidgetClass);

        QMetaObject::connectSlotsByName(CameraWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *CameraWidgetClass)
    {
        CameraWidgetClass->setWindowTitle(QApplication::translate("CameraWidgetClass", "CameraWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraWidgetClass: public Ui_CameraWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWIDGET_H
