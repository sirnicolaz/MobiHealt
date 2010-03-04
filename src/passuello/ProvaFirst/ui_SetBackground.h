/********************************************************************************
** Form generated from reading ui file 'SetBackground.ui'
**
** Created: Wed Jun 3 20:24:47 2009
**      by: Qt User Interface Compiler version 4.5.0-garden
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SETBACKGROUND_H
#define UI_SETBACKGROUND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetBackgroundClass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetBackgroundClass)
    {
        if (SetBackgroundClass->objectName().isEmpty())
            SetBackgroundClass->setObjectName(QString::fromUtf8("SetBackgroundClass"));
        SetBackgroundClass->resize(800, 600);
        centralwidget = new QWidget(SetBackgroundClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SetBackgroundClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SetBackgroundClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SetBackgroundClass->setMenuBar(menubar);
        statusbar = new QStatusBar(SetBackgroundClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SetBackgroundClass->setStatusBar(statusbar);

        retranslateUi(SetBackgroundClass);

        QMetaObject::connectSlotsByName(SetBackgroundClass);
    } // setupUi

    void retranslateUi(QMainWindow *SetBackgroundClass)
    {
        SetBackgroundClass->setWindowTitle(QApplication::translate("SetBackgroundClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SetBackgroundClass);
    } // retranslateUi

};

namespace Ui {
    class SetBackgroundClass: public Ui_SetBackgroundClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETBACKGROUND_H
