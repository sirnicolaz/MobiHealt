#ifndef TEXTBOXWIDGET_H_
#define TEXTBOXWIDGET_H_

#include <QWidget>
#include <QString>
#include <QPixmap>

class QHBoxLayout;
class QVBoxLayout;
class QPixmap;
class QLineEdit;

class TextBoxWidget : public QWidget
	{
	Q_OBJECT
	
public:
	TextBoxWidget(QPixmap background, QWidget *parent=0);
	virtual ~TextBoxWidget();
	void setBackgroundImage();
	QString getValue();
	
private:
	QPixmap bg;
	QLineEdit *textBox;
};



#endif //TEXTBOXWIDGET

