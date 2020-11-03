#include "lvselection.h"
#include "ui_lvselection.h"

extern Game* game;

LvSelection::LvSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LvSelection)
{
    ui->setupUi(this);
}

LvSelection::~LvSelection()
{
    delete ui;
}

void LvSelection::SetUserData()
{
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
        q.prepare(QString("SELECT * FROM users WHERE login = '%1'").arg(user_logged));
        if(q.exec())
        {
            while(q.next())
            {
                Lv1Clear = q.value(4).toBool();
                Lv2Clear = q.value(5).toBool();
                Lv3Clear = q.value(6).toBool();
                Lv4Clear = q.value(7).toBool();
                Lv5Clear = q.value(8).toBool();
                Lv6Clear = q.value(9).toBool();
                Lv7Clear = q.value(10).toBool();
                Lv8Clear = q.value(11).toBool();
                lv9Clear = q.value(12).toBool();
            }
        }
        else
        {
            QMessageBox::warning(this, "error", "queue failed!");
            return;
        }
    }
}

void LvSelection::update_userData()
{
    SetUserData();
}

void LvSelection::on_pushButton_Lv1_clicked()
{
    game = new Game(this,5,1,10,user_logged,1,1);
    game->setAttribute(Qt::WA_DeleteOnClose);
    connect(game, &Game::update_userData, this, &LvSelection::update_userData);
    game->show();
}

void LvSelection::on_pushButton_Lv2_clicked()
{
    if(Lv1Clear)
    {
        game = new Game(this,8,1,8,user_logged,1,2);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 1 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv3_clicked()
{
    if(Lv2Clear)
    {
        game = new Game(this,11,1,8,user_logged,1,3);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 2 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv4_clicked()
{
    if(Lv3Clear)
    {
        game = new Game(this,15,1,7,user_logged,1,4);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 3 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv5_clicked()
{
    if(Lv4Clear)
    {
        game = new Game(this,18,1,7,user_logged,1,5);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 4 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv6_clicked()
{
    if(Lv5Clear)
    {
        game = new Game(this,21,1,7,user_logged,1,6);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 5 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv7_clicked()
{
    if(Lv6Clear)
    {
        game = new Game(this,21,1,6,user_logged,1,7);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 6 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv8_clicked()
{
    if(Lv7Clear)
    {
        game = new Game(this,21,1,6,user_logged,1,8);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 7 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_Lv9_clicked()
{
    if(Lv8Clear)
    {
        game = new Game(this,21,1,5,user_logged,1,9);
        game->setAttribute(Qt::WA_DeleteOnClose);
        connect(game, &Game::update_userData, this, &LvSelection::update_userData);
        game->show();
    }
    else
    {
        QMessageBox warning;
        warning.setText("stage locked!" "you must clear stage 8 first.");
        warning.exec();
    }
}

void LvSelection::on_pushButton_clicked()
{
    emit closeLvSelection();
}
