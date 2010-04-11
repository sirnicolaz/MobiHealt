#ifndef SCROLLFRAME_H_
#define SCROLLFRAME_H_

#include <QFrame>

class ns1__SimplePatient;

class ScrollFrame : public QFrame
{
Q_OBJECT
public:
	ScrollFrame(ns1__SimplePatient **array, int size, QWidget *parent = 0);
	virtual ~ScrollFrame();

};

#endif /* SCROLLFRAME_H_ */
