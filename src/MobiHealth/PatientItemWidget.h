#ifndef PATIENTITEMWIDGET_H_
#define PATIENTITEMWIDGET_H_

#include <QFrame>
#include <QString>

class QHBoxLayout;
class QVBoxLayout;
class QPixmap;
class PatientSearchResultForm;

class PatientItemWidget : public QFrame
	{
	Q_OBJECT
	
public:
	PatientItemWidget(QString patientId, QString patientName, QString patientCity, QString patientCode, QWidget *parent=0);
	virtual ~PatientItemWidget();
	
private:
	PatientSearchResultForm *parent;
	QHBoxLayout *hLayout;
	QVBoxLayout *labelLayout;
	QVBoxLayout *buttonVLabel;
	QPixmap icon;
	QPixmap iconPressed;
	QString id;
	
private slots:
	void selectPatientButtonSlot();
	
};

#endif /* PATIENTITEMWIDGET_H_ */
