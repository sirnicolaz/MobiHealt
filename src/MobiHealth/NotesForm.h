#ifndef NOTESFORM_H
#define NOTESFORM_H

#include <QtGui/QWidget>
#include "ui_NotesForm.h"

class ButtonLabel;
class QLabel;
class ChangePatientFooter;

class NotesForm : public QWidget
{
    Q_OBJECT

public:
    NotesForm(QString title, QString text, QWidget *parent = 0);
    ~NotesForm();

private:
    Ui::NotesFormClass ui;
    
    /* references to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientImagesIcon;
        
    /* reference to the footer objects */
    ChangePatientFooter *footer;
    
    void setBackgroundImage();
};

#endif // NOTESFORM_H
