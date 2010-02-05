#ifndef ACTION1WIDGET_H
#define ACTION1WIDGET_H

#include <QtGui/QWidget>
#include "ui_action1widget.h"

/* QtGui backward class declaration */
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QStackedLayout;

/* steps backward class declaration */
class DescriptionStep;
class SimpleTextStep;
class SimpleOptionStep;

class Action1Widget : public QWidget
{
    Q_OBJECT

public:
    /* action1 widget constructor */
    Action1Widget(QWidget *parent = 0);
    /* action1 widget destructor */
    ~Action1Widget();

private:
    /* user interface obj, used by QtDesigner */
    Ui::Action1WidgetClass ui;
    
    /* user interface widgets */
    QPushButton *closeButton;
    QPushButton *nextButton;
    QPushButton *backButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;
    QStackedLayout *stepsLayout;
    
    /* action1 steps (will be an array) */
    DescriptionStep *step1;
    SimpleTextStep *step2;
    SimpleOptionStep *step3;
    
private slots:
	/* action1 wizard slots */
	void nextStep();
	void preStep();
};

#endif // ACTION1WIDGET_H
