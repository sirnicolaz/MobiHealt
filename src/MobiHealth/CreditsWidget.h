#ifndef CREDITSWIDGET_H
#define CREDITSWIDGET_H

#include <QtGui/QWidget>
#include "ui_creditswidget.h"

/* forward declaration */
class QLabel;
class ButtonLabel;
class CreditsFooterWidget;

class CreditsWidget : public QWidget
{
    Q_OBJECT

public:
    CreditsWidget(QWidget *parent = 0);
    ~CreditsWidget();
    
private:
    Ui::CreditsWidgetClass ui;
    
    QLabel *creditsText;
    QLabel *personLogo;
    ButtonLabel *quitButton; //quit app
    ButtonLabel *backButton; //to login form (quit this widget)
    CreditsFooterWidget *parent;
    
    void setBackgroundImage();
    
private slots:
	void closeButtonSlot();
};

#endif // CREDITSWIDGET_H
