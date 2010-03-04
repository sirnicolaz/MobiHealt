#include "patientsendform.h"
#include "ProvaFirst.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

PatientSendForm::PatientSendForm(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	nameLabel = new QLabel("Nome", this);
	nameText = new QLineEdit(this);
	surnameLabel = new QLabel("Cognome", this);
	surnameText = new QLineEdit(this);
	locationLabel = new QLabel("Comune", this);
	locationText = new QLineEdit(this);
	codeLabel = new QLabel("Codice", this);
	codeText = new QLineEdit(this);
	searchButton = new QPushButton("Cerca Paziente", this);
	
	QGridLayout *princLayout = new QGridLayout;
	princLayout->addWidget(nameLabel, 0, 0, Qt::AlignLeft);
	princLayout->addWidget(nameText, 1, 0, Qt::AlignCenter);
	princLayout->addWidget(surnameLabel, 2, 0, Qt::AlignLeft);
	princLayout->addWidget(surnameText, 3, 0, Qt::AlignCenter);
	princLayout->addWidget(locationLabel, 4, 0, Qt::AlignLeft);
	princLayout->addWidget(locationText, 5, 0, Qt::AlignCenter);
	princLayout->addWidget(codeLabel, 6, 0, Qt::AlignLeft);
	princLayout->addWidget(codeText, 7, 0, Qt::AlignCenter);
	princLayout->addWidget(searchButton, 8, 0, Qt::AlignCenter);
	setLayout(princLayout);
	
}

PatientSendForm::~PatientSendForm()
{

}

void PatientSendForm::PatientSendResultForm(){
	
	mainMenu = new PatientSendForm();
	mainMenu->showFullScreen();
}
