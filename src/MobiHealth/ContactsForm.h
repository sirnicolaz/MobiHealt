#ifndef CONTACTSFORM_H
#define CONTACTSFORM_H

#include <QtGui/QWidget>
#include "ui_ContactsForm.h"

class QString;
class ButtonLabel;
class QLabel;
class ChangePatientFooter;
class PatientMenuForm;


class ContactsForm : public QWidget
{
    Q_OBJECT

public:
    ContactsForm(QWidget *parent = 0);
    ~ContactsForm();
    void setBackgroundImage();

private:
    Ui::ContactsFormClass ui;
    
    /* reference to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientIcon;
    
    /* reference to the parent widget */
    PatientMenuForm *parent;
    
    /* reference to the footer objects */
    ChangePatientFooter *footer;
    
private slots:
	void backButtonSlot();
    
};

#endif // CONTACTSFORM_H
