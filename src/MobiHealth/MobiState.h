#ifndef MOBISTATE_H_
#define MOBISTATE_H_

#include <QObject>
#include "Patient.h"

class MobiState : public QObject
{
	Q_OBJECT
private:
	/* private constructor */
	MobiState() { currentPatient = 0; }
	/* private copy constructor */
	//MobiState(MobiState a) {}
	//MobiState& operator=(MobiState& a) {}

	/* signleton instance reference */
	static MobiState *state;
	
	/* reference to the current patient object */
	Patient* currentPatient;
	
signals:
	void changeCurrentPatientSignal();
	
public:
	~MobiState() { }
	
	static MobiState* getInstance()
	{
		if (state == 0)
		{
			state = new MobiState();
			return state;
		}
		else
			return state;	
	}
	
	Patient* getCurrentPatient();
	void changeCurrentPatient(Patient* newPatient);
	void reset();
};

#endif /* MOBISTATE_H_ */
