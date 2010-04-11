#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QMap>
#include <vector>

/* Patient anagrafica object */
class Anagrafica {
public:
	QString patientId;	
	QString patientCode;
	QString name;
	QString lastName;	
	QString address;
	QString cap;
	QString city;
	QString province;
	QString birthDate;
	QString GP;
	QString CF;
	QString profession;
	QString birthLocation;
	QString marital;
	
	Anagrafica(){}
};

class ImageItem {
public:
	QString imageId;
	//QString patientId;
	QString base64Preview;
	QString name;
	QString imageNote;
	
	ImageItem() {}
};

/* Patient object */
class Patient {
public:
	QString patintId;
	Anagrafica *anagrafica;
	QMap<QString, QString> *contacts;
	std::vector<ImageItem*> images;
	QMap<QString, QString> *pathologies;
	QMap<QString, QString> *visitsHistory;
	
	/* patient object constructor */
	Patient() 
	{
		anagrafica = new Anagrafica();
		contacts = new QMap<QString, QString>();
		pathologies = new QMap<QString, QString>();
		visitsHistory = new QMap<QString, QString>();
	}
};

#endif // PATIENT_H
