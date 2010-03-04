#ifndef MAINMENUFORM_H
#define MAINMENUFORM_H

#include <QtGui/QWidget>
#include "ui_mainmenuform.h"

class QPushButton;

class MainMenuForm : public QWidget
{
    Q_OBJECT

public:
    MainMenuForm(QWidget *parent = 0);
    ~MainMenuForm();

private:
    Ui::MainMenuFormClass ui;
    QPushButton *patientButton;
    QPushButton *examsButton;
    QPushButton *notesButton;
    QPushButton *accountButton;
    QPushButton *exitButton;
 /*   
private slots:
void patientSlot();
void examsSlot();
void notesSlot();
void accountSlot();
*/
};

#endif // MAINMENUFORM_H
