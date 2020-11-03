#include <QApplication>
#include "game.h"
#include "mainmenu.h"
#include "loginscreen.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginScreen* l = new LoginScreen;
    l->show();
    return a.exec();
}
