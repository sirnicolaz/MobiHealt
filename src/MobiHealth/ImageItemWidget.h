#ifndef IMAGEITEMWIDGET_H
#define IMAGEITEMWIDGET_H

#include <QtGui/QWidget>

class ButtonLabel;
class QLabel;
class QString;

class ImageItemWidget : public QWidget
{
    Q_OBJECT

public:
    ImageItemWidget(QString *imegeItem, QWidget *parent = 0);
    ~ImageItemWidget();

private:
    /* references to the GUI objects */
    ButtonLabel *viewImageButton;
    ButtonLabel *viewNoteButton;
    QLabel *imagePreview;
    
    /* reference to the image item object */
    QString *imageItem;
    
private slots:
	void viewNoteSlot();
	void viewImageSlot();

};

#endif // IMAGEITEMWIDGET_H
