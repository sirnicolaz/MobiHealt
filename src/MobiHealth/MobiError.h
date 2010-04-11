#ifndef MOBIERROR_H
#define MOBIERROR_H

#include <QtGui/QWidget>
#include "ui_MobiError.h"

/* forward class declaration */
class MobiHealth;

class MobiError : public QWidget
{
    Q_OBJECT

public:
    MobiError(QWidget *parent = 0);
    ~MobiError();

private:
    Ui::MobiErrorClass ui;
    MobiHealth *parent;
    
    void setBackgroundImage();
    
private slots:
	void quitButtonSlot();
    
};

#endif // MOBIERROR_H
