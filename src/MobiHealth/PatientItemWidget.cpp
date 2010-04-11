#include "PatientItemWidget.h"
#include "PatientSearchResultForm.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFlag>
#include <QPixmap>
#include "buttonlabel.h"
#include "soapMobiBindingProxy.h"
#include "ErrorForm.h"
#include "MobiState.h"
#include "Patient.h"

PatientItemWidget::PatientItemWidget(QString patientId, QString patientName, QString patientCity, QString patientCode, QWidget *parent)
: QFrame(parent)
{
	this->parent = dynamic_cast<PatientSearchResultForm*>(parent);
	this->setStyleSheet("border-top: 2px dashed gray;");
	//this->setStyleSheet(" QLabel{ font-size : 18px; font-family : helvetica; color: #BE0A26; }");
	this->setContentsMargins(0, 0, 0, 0);
	
	id = patientId;
	hLayout = new QHBoxLayout();
	hLayout->setContentsMargins(0, 0, 0, 0);
	labelLayout = new QVBoxLayout();
	labelLayout->setContentsMargins(0, 0, 0, 0);
	buttonVLabel = new QVBoxLayout();
	buttonVLabel->setContentsMargins(0, 0, 0, 0);
	
	QLabel *border = new QLabel(this);
	border->setStyleSheet("border-style: hidden;");
	border->setPixmap(QPixmap(":/icons/patientItemLeftBorder.png"));
	
	QLabel *nameLabel = new QLabel("NOME  <font color=\"black\">" + patientName + "</font>", this);
	nameLabel->setStyleSheet("border-style: hidden; font-family : helvetica; color: #BE0A26;");
	QLabel *cityLabel = new QLabel("COMUNE DI RESIDENZA  <font color=\"black\">" + patientCity + "</font>", this);
	cityLabel->setStyleSheet("border-style: hidden; font-family : helvetica; color: #BE0A26;");
	QLabel *codeLabel = new QLabel("ID PAZIENTE  <font color=\"black\">" + patientCode+ "</font>", this);
	codeLabel->setStyleSheet("border-style: hidden; font-family : helvetica; color: #BE0A26;");
	
	ButtonLabel *selectPatientButton = new ButtonLabel(QPixmap(":/icons/patientSelectButton.png"), QPixmap(":/icons/patientSelectButtonPushed.png"), this);
	selectPatientButton->setStyleSheet("border-style: hidden;");
	connect(selectPatientButton, SIGNAL(released()), this, SLOT(selectPatientButtonSlot()));
	 
	labelLayout->setSpacing(1);
	//labelLayout->addSpacing(13);
	labelLayout->addStretch();
	labelLayout->addWidget(nameLabel);
	labelLayout->addWidget(cityLabel);
	labelLayout->addWidget(codeLabel);
	labelLayout->addStretch();
	
	buttonVLabel->addSpacing(25);
	buttonVLabel->addWidget(selectPatientButton);
	buttonVLabel->addStretch();
	
	hLayout->addWidget(border);
	hLayout->addSpacing(5);
	hLayout->addLayout(labelLayout);
	hLayout->addStretch();
	hLayout->addLayout(buttonVLabel);
	hLayout->addSpacing(20);
	
	setLayout(hLayout);
	}

/* select patient button slot implementation */
void PatientItemWidget::selectPatientButtonSlot()
{
	/* get the patient object (calling web method) */
	MobiBinding server;
	ns1__getPatientByIdResponse response;
	
	/* show the "loading form" 
	LoadingForm *loadingForm = new LoadingForm();
	loadingForm->setAttribute(Qt::WA_DeleteOnClose, true);
	loadingForm->showFullScreen();*/
	
	/* get the patient object from server */
	int err = server.ns1__getPatientById(id.toLocal8Bit().data(), response);
	
	if (err == SOAP_OK) // no web service error
	{
		ns1__Patient *patient = response.getPatientByIdReturn;
		
		/* construct the patient object */
		Patient *myPatient = new Patient();
		myPatient->patintId = id;
		/* construct the patient anagrafica object */
		myPatient->anagrafica->patientId = QString(patient->anagrafica->patientId);
		myPatient->anagrafica->patientCode = QString(patient->anagrafica->patientCode);
		myPatient->anagrafica->name = QString(patient->anagrafica->name);
		myPatient->anagrafica->lastName = QString(patient->anagrafica->lastName);
		myPatient->anagrafica->address = QString(patient->anagrafica->address);
		myPatient->anagrafica->cap = QString(patient->anagrafica->cap);
		myPatient->anagrafica->city = QString(patient->anagrafica->city);
		myPatient->anagrafica->province = QString(patient->anagrafica->province);
		myPatient->anagrafica->birthDate = QString(patient->anagrafica->birthDate);
		myPatient->anagrafica->GP = QString(patient->anagrafica->GP);
		myPatient->anagrafica->CF = QString(patient->anagrafica->CF);
		myPatient->anagrafica->profession = QString(patient->anagrafica->profession);
		myPatient->anagrafica->birthLocation = QString(patient->anagrafica->birthLocation);
		myPatient->anagrafica->marital = QString(patient->anagrafica->marital);
		/* construct the contacts map */
		ns1__KeyValueObject **contactsArray = patient->contacts->__ptr;
		int contactsArraySize = patient->contacts->__size;
		/* for each contact add it in the patient contacts map */
		for (int i=0; i<contactsArraySize; i++)
		{
			myPatient->contacts->insert(QString(contactsArray[i]->key), QString(contactsArray[i]->value));
		}
		/* construct the images vector */
		ns1__ImageItem **imagesArray = patient->images->__ptr;
		int imagesArraySize = patient->images->__size;
		for (int i=0; i<imagesArraySize; i++)
		{
			ImageItem *image = new ImageItem(); 
			image->imageId = QString(imagesArray[i]->imageId);
			//QString patientId;
			image->base64Preview = QString(imagesArray[i]->base64Preview);
			image->name = QString(imagesArray[i]->name);
			image->imageNote = QString(imagesArray[i]->imageNote);
			myPatient->images.push_back(image);
		}
		/* construct the pathologies map */
		ns1__KeyValueObject **pathologiesArray = patient->pathologies->__ptr;
		int pathologiesArraySize = patient->pathologies->__size;
		/* for each pathologies add it in the patient pathologies map */
		for (int i=0; i<pathologiesArraySize; i++)
		{
			myPatient->pathologies->insert(QString(pathologiesArray[i]->key), QString(pathologiesArray[i]->value));
		}
		/* construct the visits history map */
		ns1__KeyValueObject **visitHistoryArray = patient->visitHistory->__ptr;
		int visitHistoryArraySize = patient->visitHistory->__size;
		/* for each visit add it in the patient visit history map */
		for (int i=0; i<visitHistoryArraySize; i++)
		{
			myPatient->visitsHistory->insert(QString(visitHistoryArray[i]->key), QString(visitHistoryArray[i]->value));
		}
		
		/* update the current patient */
		MobiState::getInstance()->changeCurrentPatient(myPatient);
		
		/* close the form */
		//loadingForm->close();
		parent->close();
	}
	else // web service error
	{
		/* show the error form */
		ErrorForm *error = new ErrorForm(err);
		error->setAttribute(Qt::WA_DeleteOnClose, true);
		error->showFullScreen();
		//loadingForm->close();
	}
	
}

PatientItemWidget::~PatientItemWidget()
	{
	// TODO Auto-generated destructor stub
	}
