#include "SetBackground.h"
#include <QPalette>
#include <QDesktopWidget>

SetBackground::SetBackground(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("Setbackground");
	SetBackgroundImage();
}

SetBackground::~SetBackground()
{

}
