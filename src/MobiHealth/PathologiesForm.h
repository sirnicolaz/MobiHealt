#ifndef PATHOLOGIESFORM_H
#define PATHOLOGIESFORM_H

#include <QtGui/QWidget>
#include "ui_PathologiesForm.h"

class QString;
class ButtonLabel;
class QLabel;
class ChangePatientFooter;
class PatientMenuForm;

class PathologiesForm : public QWidget
{
    Q_OBJECT

public:
    PathologiesForm(QWidget *parent = 0);
    ~PathologiesForm();

private:
    Ui::PathologiesFormClass ui;
    void setBackgroundImage();
    
    /* reference to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientIcon;
    
    /* reference to the footer objects */
    ChangePatientFooter *footer;
    
    /* reference to the parent widget */
    PatientMenuForm *parent;
    
private slots:
	void backButtonSlot();
};

#endif // PATHOLOGIESFORM_H
