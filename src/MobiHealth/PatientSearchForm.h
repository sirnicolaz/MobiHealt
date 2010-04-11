#ifndef PATIENTSEARCHFORM_H
#define PATIENTSEARCHFORM_H

#include <QtGui/QWidget>
#include "ui_PatientSearchForm.h"

/* forward declaration */
class QLabel;
class QLineEdit;
class ButtonLabel;
class PatientSearchResultForm;
class TextBoxWidget;
class CreditsFooterWidget;

class PatientSearchForm : public QWidget
{
    Q_OBJECT

public:
    PatientSearchForm(QWidget *parent = 0);
    ~PatientSearchForm();

private:
    Ui::PatientSearchFormClass ui;
    
    /* reference to the GUI objects */
    TextBoxWidget *nameTextBox;
    TextBoxWidget *surnameTextBox;
    TextBoxWidget *cityTextBox;
    TextBoxWidget *codeTextBox;
    ButtonLabel *searchButton;
    ButtonLabel *creditsButton;
    ButtonLabel *quitButton;
    QLabel *personLogo;
    
    /* reference to the search result form */
    PatientSearchResultForm *resultsForm;
    
    /* reference to the loading pixmap */
    QLabel *loadingImage;
    
    CreditsFooterWidget *creditsFooter;
    
    void setBackgroundImage();
    
private slots:
	void searchButtonSlot();
	void creditsSlot();
};

#endif // PATIENTSEARCHFORM_H
