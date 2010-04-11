#ifndef ACTIONITEMWIDGET_H_
#define ACTIONITEMWIDGET_H_

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QVBoxLayout;
class QPixmap;

class ActionItemWidget : public QWidget
	{
	Q_OBJECT
	
private:
	/* number of the action in the array */
	int actionNumber;
	
protected slots:
	void clickWithID();

signals:
	void clickedWithID(int);
	
public:
	ActionItemWidget(QString actionName, int actionNum, QWidget *parent=0);
	virtual ~ActionItemWidget();
	
	void setBackgroundImage();
	};

#endif /* ACTIONITEMWIDGET_H_ */
