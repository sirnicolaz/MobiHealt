#ifndef PATIENTMENUFORM_H
#define PATIENTMENUFORM_H

#include <QtGui/QWidget>
#include "ui_PatientMenuForm.h"

class ButtonLabel;
class QLabel;
class ChangePatientFooter;
class MainMenuForm;
class AnagraficaForm;
class ContactsForm;
class ImagesForm;
class PathologiesForm;
class HistoryForm;

class PatientMenuForm : public QWidget
{
    Q_OBJECT

public:
    PatientMenuForm(QWidget *parent = 0);
    ~PatientMenuForm();

private:
    Ui::PatientMenuFormClass ui;
    
    /* references to the GUI objects */
    ButtonLabel *anagraficaButton;
    ButtonLabel *contactsButton;
    ButtonLabel *medicalReportButton;
    ButtonLabel *pathologiesButton;
    ButtonLabel *imagesButton;
    ButtonLabel *historyButton;
    ButtonLabel *backButton; // to main menu form
    ButtonLabel *quitButton; // quit app
    QLabel *userIcon;
    
    /* reference to the footer object */
    ChangePatientFooter *footer;
    
    /* parent widget */
    MainMenuForm* parent;
    
    AnagraficaForm *anagraficaForm;
    ContactsForm *contactsForm;
    //MedicalReportForm *medicalReportForm;
    PathologiesForm *pathologiesForm;
    ImagesForm *imagesForm;
    HistoryForm *historyForm;
    
    void setBackgroundImage();
    
private slots:
    void backButtonSlot();
    void anagraficaButtonSlot();
    void contactsButtonSlot();
    void imagesButtonSlot();
    void medicalReportButtonSlot();
    void historyButtonSlot();
    void pathologiesButtonSlot();
};

#endif // PATIENTMENUFORM_H
