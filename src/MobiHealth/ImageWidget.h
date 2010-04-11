#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QtGui/QWidget>
#include "ui_ImageWidget.h"

class ButtonLabel;
class QLabel;
class ChangePatientFooter;

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    ImageWidget(QString base64Image, QWidget *parent = 0);
    ~ImageWidget();

private:
    Ui::ImageWidgetClass ui;
    
    /* references to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientIcon;
    
    /* reference to the footer objects */
    ChangePatientFooter *footer;
   
    void setBackgroundImage();
};

#endif // IMAGEWIDGET_H
