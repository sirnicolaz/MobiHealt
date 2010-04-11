#include "buttonlabel.h"

ButtonLabel::ButtonLabel(QPixmap normalIcon, QPixmap pressedIcon, QWidget* parent)
	: QLabel(parent)
	{
		/* set the button icon (in normale state) */
		this->setPixmap(normalIcon);
		
		/* inizialize icon objects */
		this->normalIcon = normalIcon;
		this->pressedIcon = pressedIcon;
	}

/* when the user press the "button" */
void ButtonLabel::mousePressEvent( QMouseEvent * event )
{
	this->setPixmap(pressedIcon);
}

void ButtonLabel::mouseReleaseEvent( QMouseEvent * event )
{
	this->setPixmap(normalIcon);
	/* emit the release signal to notify the action */
	emit ButtonLabel::released();
	
}
