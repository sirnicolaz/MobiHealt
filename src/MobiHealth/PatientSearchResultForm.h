#ifndef PATIENTSEARCHRESULTFORM_H
#define PATIENTSEARCHRESULTFORM_H

#include <QtGui/QWidget>
#include "ui_PatientSearchResultForm.h"

class ns1__SimplePatient;
class PatientSearchForm;

class PatientSearchResultForm : public QWidget
{
    Q_OBJECT

public:
    PatientSearchResultForm(ns1__SimplePatient **array, int size, QWidget *parent = 0);
    ~PatientSearchResultForm();

private:
    Ui::PatientSearchResultFormClass ui;
    void setBackgroundImage();
    
    /* parent widget */
    PatientSearchForm *parent;
    
private slots:
	void closeButtonSlot();
};

#endif // PATIENTSEARCHRESULTFORM_H
