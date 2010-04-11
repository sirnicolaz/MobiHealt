#ifndef CHANGEPATIENTFOOTER_H_
#define CHANGEPATIENTFOOTER_H_

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QVBoxLayout;
class ButtonLabel;
class QLabel;

class ChangePatientFooter : public QWidget
	{
	Q_OBJECT
	
public:
	ChangePatientFooter(QWidget *parent = 0);
	virtual ~ChangePatientFooter();
	void setBackgroundImage();
	void updatePatient(QString patientName);
	
private:
	QHBoxLayout *hLayout;
	QVBoxLayout *labelLayout;
	ButtonLabel *changePatientButton;
	QLabel *patient;
	QLabel *patientName;
	

private slots:
	void changePatientButtonSlot();
	};

#endif /* CHANGEPATIENTFOOTER_H_ */
