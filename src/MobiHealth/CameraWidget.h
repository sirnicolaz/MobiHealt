#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QtGui/QWidget>
#include "ui_CameraWidget.h"

/* forward class declaration */
class CameraObserver;
class Action;

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    CameraWidget(Action* actionsForm, QWidget *parent = 0);
    ~CameraWidget();
    
    /* notify to actions form that the picture is captured and saved */
    void pictureSaved();

private:
    Ui::CameraWidgetClass ui;
    
    /* reference to the camera observer object */
    CameraObserver* iCameraObserver;
    /* reference to the action form widget */
    Action* actionsForm;
        
private slots:
	/* buttons slots */
	void zoomInSlot();
	void zoomOutSlot();
	void captureSlot();

};

#endif // CAMERAWIDGET_H
