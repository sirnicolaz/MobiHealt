#ifndef SETBACKGROUND_H
#define SETBACKGROUND_H

#include <QtGui/QMainWindow>
#include "ui_SetBackground.h"

class SetBackground : public QMainWindow
{
    Q_OBJECT

public:
	SetBackground(QWidget *parent = 0);
    ~SetBackground();
    void SetBackgroundImage();
private:
    Ui::SetBackgroundClass ui;
};

#endif // SETBACKGROUND_H
