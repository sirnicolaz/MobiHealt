#ifndef PATIENTNUMBERLABEL_H_
#define PATIENTNUMBERLABEL_H_

#include <QWidget>
#include <QString>

class PatientNumberLabel: public QWidget
	{
	Q_OBJECT
	
public:
	PatientNumberLabel(int patientNumber, QWidget *parent=0);
	virtual ~PatientNumberLabel();
	void setBackgroundImage();
	
	};

#endif /* PATIENTNUMBERLABEL_H_ */
