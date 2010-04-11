#ifndef HISTORYFORM_H
#define HISTORYFORM_H

#include <QtGui/QWidget>
#include "ui_HistoryForm.h"

class ButtonLabel;
class QLabel;
class QString;
class ChangePatientFooter;
class PatientMenuForm;

class HistoryForm : public QWidget
{
    Q_OBJECT

public:
    HistoryForm(QWidget *parent = 0);
    ~HistoryForm();

private:
    Ui::HistoryFormClass ui;
    void setBackgroundImage();
    
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

#endif // HISTORYFORM_H
