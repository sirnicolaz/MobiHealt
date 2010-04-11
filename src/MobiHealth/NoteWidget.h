#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QtGui/QWidget>
#include "ui_NoteWidget.h"

class ButtonLabel;
class QLabel;
class ChangePatientFooter;

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    NoteWidget(QString title, QString text, QWidget *parent = 0);
    ~NoteWidget();

private:
    Ui::NoteWidgetClass ui;
    
    /* references to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientIcon;
            
    /* reference to the footer objects */
    ChangePatientFooter *footer;
        
    void setBackgroundImage();
};

#endif // NOTEWIDGET_H
