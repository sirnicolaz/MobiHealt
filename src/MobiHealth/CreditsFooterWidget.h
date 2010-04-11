#ifndef CREDITSFOOTERWIDGET_H_
#define CREDITSFOOTERWIDGET_H_

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QVBoxLayout;
class ButtonLabel;
class QLabel;

class CreditsFooterWidget : public QWidget
	{
	Q_OBJECT
	
public:
	CreditsFooterWidget(QWidget *parent = 0);
	virtual ~CreditsFooterWidget();
	void setBackgroundImage();
	
private:
	QHBoxLayout *hLayout;
	QVBoxLayout *vLayout;
	ButtonLabel *creditsButton;
	QLabel *creditsIcon;
	QLabel *whippyIcon;
	
private slots:
	void creditsButtonSlot();
};

#endif /* CREDITSFOOTERWIDGET_H_ */
