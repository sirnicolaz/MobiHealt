#ifndef PATIENTSENDFORM_H
#define PATIENTSENDFORM_H

#include <QtGui/QWidget>
#include "ui_patientsendform.h"

class QPushButton;
class QLabel;
class QLineEdit;
class MainMenuForm;


class PatientSendForm : public QWidget
{
    Q_OBJECT

public:
    PatientSendForm(QWidget *parent = 0);
    ~PatientSendForm();

private:
    Ui::PatientSendFormClass ui;
    QLabel * nameLabel;
	QLineEdit * nameText;
	QLabel surnameLabel;
	QLineEdit * surnameText;
	QLabel * locationLabel;
	QLineEdit * locationText;
	QLabel * codeLabel;
	QLineEdit * codeText;
	QPushButton * searchButton;
	
private slots:
void PatientSendResultForm();
};
