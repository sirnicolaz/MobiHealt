#ifndef MAINMENUFORM_H
#define MAINMENUFORM_H

#include <QtGui/QWidget>
#include "ui_MainMenuForm.h"

/* forward declaration */
class MobiHealth;
class ButtonLabel;
class QLabel;
class PatientMenuForm;
class ActionsMenu;
class ChangePatientFooter;
class PatientSearchForm;
class AccountForm;
class NotesForm;
class CreditsFooterWidget;

class MainMenuForm : public QWidget
{
    Q_OBJECT

public:
    MainMenuForm(QWidget *parent = 0);
    ~MainMenuForm();
    void changeCurrentPatient(QString newPatient);
    QString* getCurrentPatient();
    void changeCurrentPatient(QString *newPatient);

private:
    Ui::MainMenuFormClass ui;
    
    /* reference to the parent window (now it's MobiHealth) */
    MobiHealth *parent;
    
    /* references to the GUI objects */
    ButtonLabel *patientButton; // to patient menu
    ButtonLabel *examsButton; // to exams menu
    ButtonLabel *notesButton; // to notes menu (not active)
    ButtonLabel *accountButton; // to accont menu (not active)
    ButtonLabel *logoutButton; // to prev form (main menu) (SLOT(close()))
    ButtonLabel *quitButton; // quit app (SLOT(Qt::Application.instance().quit()))
    ButtonLabel *changePatientButton; // to search patient form
    
    /* references to the footer objects */
    ChangePatientFooter *footer;
    CreditsFooterWidget *creditsFooter;
    
    /* references to the forms */
    PatientMenuForm *patientMenuForm;
    ActionsMenu *examsForm;
    NotesForm *notesForm;
    AccountForm *accountForm;

    /* reference to the search form */
    PatientSearchForm *patientSearchForm;
    
    void setBackgroundImage();
    
private slots:
	void patientButtonSlot();
	void examsButtonSlot();
	void notesButtonSlot();
	void accountButtonSlot();
	void patientChangedSlot();
	void logoutButtonSlot();
    
};

#endif // MAINMENUFORM_H
