/********************************************************************************
** Form generated from reading UI file 'ActionsHandler.ui'
**
** Created: Mon Feb 15 05:31:51 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONSHANDLER_H
#define UI_ACTIONSHANDLER_H

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

class Ui_ActionsHandler
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ActionsHandler)
    {
        if (ActionsHandler->objectName().isEmpty())
            ActionsHandler->setObjectName(QString::fromUtf8("ActionsHandler"));
        ActionsHandler->resize(800, 600);
        centralwidget = new QWidget(ActionsHandler);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ActionsHandler->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ActionsHandler);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ActionsHandler->setMenuBar(menubar);
        statusbar = new QStatusBar(ActionsHandler);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ActionsHandler->setStatusBar(statusbar);

        retranslateUi(ActionsHandler);

        QMetaObject::connectSlotsByName(ActionsHandler);
    } // setupUi

    void retranslateUi(QMainWindow *ActionsHandler)
    {
        ActionsHandler->setWindowTitle(QApplication::translate("ActionsHandler", "ActionsHandler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActionsHandler: public Ui_ActionsHandler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONSHANDLER_H
