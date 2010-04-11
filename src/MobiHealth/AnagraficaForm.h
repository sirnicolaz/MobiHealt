#ifndef ANAGRAFICAFORM_H
#define ANAGRAFICAFORM_H

#include <QtGui/QWidget>
#include "ui_AnagraficaForm.h"

class QString;
class QLabel;
class ButtonLabel;
class ChangePatientFooter;
class PatientMenuForm;

class AnagraficaForm : public QWidget
{
    Q_OBJECT

public:
    AnagraficaForm(QWidget *parent = 0);
    ~AnagraficaForm();

private:
    Ui::AnagraficaFormClass ui;
    PatientMenuForm *parent;
    
    /* reference to the GUI objects */
    QLabel *nameLabel;
    QLabel *name;
    QLabel *surnameLabel;
    QLabel *surname;
    QLabel *codeLabel;
    QLabel *code;
    QLabel *addressLabel;
    QLabel *address;
    QLabel *capLabel;
    QLabel *cap;
    QLabel *cityLabel;
    QLabel *city;
    QLabel *provinceLabel;
    QLabel *province;
    QLabel *birthDateLabel;
    QLabel *birthDate;
    QLabel *GPLabel;
    QLabel *GP;
    QLabel *CFLabel;
    QLabel *CF;
    QLabel *professionLabel;
    QLabel *profession;
    QLabel *birthLocationLabel;
    QLabel *birthLocation;
    QLabel *maritalLabel;
    QLabel *marital;
    QLabel *patientIcon;
    ButtonLabel *backButton; // to patient menu form
    ButtonLabel *quitButton; // quit app
    
    /* reference to the footer object */
    ChangePatientFooter *footer;
     
    void setBackgroundImage();
    
private slots:
	void backButtonSlot();
    
};

#endif // ANAGRAFICAFORM_H
