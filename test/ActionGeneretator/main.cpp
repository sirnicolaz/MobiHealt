#include <QtGui/QApplication>
#include "mainmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
