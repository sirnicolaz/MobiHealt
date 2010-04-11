#ifndef BUTTONLABEL_H
#define BUTTONLABEL_H
#include <QLabel>

class ButtonLabel : public QLabel
{
	Q_OBJECT
private:
	/* icons object */
	QPixmap normalIcon;
	QPixmap pressedIcon;
	
public:
	ButtonLabel(QPixmap normalIcon, QPixmap pressedIcon, QWidget *parent=0);
	void mousePressEvent( QMouseEvent * event );
	void mouseReleaseEvent( QMouseEvent * event );

signals:
	/* signal to notify the press action */
	//void clicked();
	/* signal to notify the release action */
	void released();
};

#endif // BUTTONLABEL_H
