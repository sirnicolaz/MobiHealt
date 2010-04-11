#ifndef SELECTSEARCHMENU_H
#define SELECTSEARCHMENU_H

#include <QtGui/QWidget>
#include "ui_SelectSearchMenu.h"
#include "coemain.h"

/* forward class declaration */
class ButtonLabel;
class QPushButton;
class CreditsFooterWidget;
class QLabel;

class SelectSearchMenu : public QWidget, public MCoeMessageObserver
{
    Q_OBJECT

public:
    SelectSearchMenu(QWidget *parent = 0);
    ~SelectSearchMenu();

private:
    Ui::SelectSearchMenuClass ui;
    
    /* GUI objects references */
    ButtonLabel *quitButton;
    //ButtonLabel *logoutButton;
    QPushButton *qrCodeButton;
    QPushButton *searchButton;
    
    /* reference to the loading pixmap */
    QLabel *loadingImage;
    
    /* label test */
    QLabel *label;
    
    /* reference to the credits footer */
    CreditsFooterWidget *creditsFooter;
    
    void setBackgroundImage();
    void StartQRDecoder();
    virtual TMessageResponse SelectSearchMenu::HandleMessageL(TUint32 aClientHandleOfTargetWindowGroup, TUid aMessageUid, const TDesC8 &aMessageParameters);
    
private slots:
	void qrCodeButtonSlot();
	void searchButtonSlot();
};

#endif // SELECTSEARCHMENU_H
