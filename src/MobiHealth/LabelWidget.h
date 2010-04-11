#ifndef LABELWIDGET_H_
#define LABELWIDGET_H_

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QVBoxLayout;
class QPixmap;

class LabelWidget : public QWidget
	{
	Q_OBJECT
	
public:
	LabelWidget(QString label, QWidget *parent=0);
	virtual ~LabelWidget();
	void setBackgroundImage();
	
	};



#endif //LABELWIDGET

