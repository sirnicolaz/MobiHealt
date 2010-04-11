#include "MobiState.h";

/* initialize the singleton instance */
MobiState* MobiState::state = 0;

/* current patient getter (return 0 if no patient selected) */
Patient* MobiState::getCurrentPatient()
{
	return currentPatient;
}

/* update/set the current patient */

void MobiState::changeCurrentPatient(Patient* newPatient)
{
	Patient* oldPatient = currentPatient;
	currentPatient = newPatient;
	/* TODO: FIX GARBAGE!!! */
	//delete oldPatient;
	
	/* notify the other GUI */
	emit changeCurrentPatientSignal();
}

void MobiState::reset()
{
	Patient* oldPatient = currentPatient;
	currentPatient = 0;
	/* TODO: FIX GARBAGE!!! */
	//if(oldPatient)
		//delete oldPatient;
}


