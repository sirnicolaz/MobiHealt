#ifndef ACTIONSMENU_H
#define ACTIONSMENU_H

#include <QtGui/QWidget>
#include <vector>
#include <QString>
#include <QPushButton>
#include "ui_ActionsMenu.h"
#include "Action.h"

using namespace std;

class QHBoxLayout;
class QVBoxLayout;
class ChangePatientFooter;
class ButtonLabel;
class MainMenuForm;

class ActionsMenu : public QWidget
{
    Q_OBJECT
public:
	ActionsMenu(vector<QString> actionDescriptorFilesName, QWidget *parent = 0);
    ~ActionsMenu();

private:
    Ui::ActionsMenuClass ui;
    QVBoxLayout *mainLayout;
    vector<QString> descriptors;
    
    /* reference to the parent widget */
    MainMenuForm *parent;
    
    /* reference to the footer object */
    ChangePatientFooter *footer;
   
    /* references to the GUI objects */
    QLabel *visitsIcon;
    ButtonLabel *backButton; // to patient menu form
    ButtonLabel *quitButton; // quit app
    
    void setBackgroundImage();

private slots:
	void backButtonSlot();
    
public slots:
	void showAction(int);

};



#endif // ACTIONSMENU_H

