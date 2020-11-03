#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QDebug>

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_pushButton_login_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "conn");
    db.setHostName("localhost");
    db.setDatabaseName("ProjetoIntegrador");
    db.setUserName("root");
    db.setPassword("M4a10121");
    bool ok = db.open();

    if(!ok)
    {
        QMessageBox::warning(this, "connection", "can not open connection!");
    }
    else
    {
        QSqlQuery q(db);
        q.prepare("SELECT login, password FROM users");
        if(q.exec())
        {
            while(q.next())
            {
                if(q.value(0).toString() == login && q.value(1).toString() == password)
                {
                    m = new mainMenu();
                    m->setAttribute(Qt::WA_DeleteOnClose);
                    connect(m, &mainMenu::closeMenu, this, &LoginScreen::closeMenu);
                    connect(this, &LoginScreen::logged_player, m, &mainMenu::logged_player);
                    m->show();

                    emit logged_player(login);//gives the mainMenu class the username of the player that is logged
                    disconnect(this, &LoginScreen::logged_player, m, &mainMenu::logged_player);
                    db.close();
                    hide();
                    return;
                }
            }
            QMessageBox::warning(this, "error", "authentication failed!");
            return;
        }
    }
}

void LoginScreen::on_pushButton_clicked()
{
    c = new AccountCreation(this);
    c->setAttribute(Qt::WA_DeleteOnClose);
    connect(c, &AccountCreation::closeAccountCreation, this, &LoginScreen::closeAccountCreation);
    hide();
    c->show();
}

void LoginScreen::closeMenu()
{
    show();
    m->close();
}

void LoginScreen::closeAccountCreation()
{
    show();
    c->close();
}
