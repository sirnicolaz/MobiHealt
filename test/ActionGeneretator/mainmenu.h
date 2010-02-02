#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
    class MainMenu;
}

class MainMenu : public QWidget {
    Q_OBJECT
public:
    MainMenu(QWidget *parent = 0);
    ~MainMenu();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
