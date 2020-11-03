#include "mainmenu.h"
#include "ui_mainmenu.h"

Game* game;

mainMenu::mainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::on_pushButton_campaign_clicked()
{
    hide();
    stage_select = new LvSelection();
    stage_select->user_logged = user_logged;
    stage_select->SetUserData();
    stage_select->setAttribute(Qt::WA_DeleteOnClose);
    connect(stage_select, &LvSelection::closeLvSelection, this, &mainMenu::closeLvSelection);
    stage_select->show();
}

void mainMenu::on_pushButton_survival_clicked()
{
    game = new Game(this,5,1,10,user_logged,0,0);
    game->setAttribute(Qt::WA_DeleteOnClose);
    connect(game, &Game::closeGame, this, &mainMenu::game_finished);
    game->show();
}

void mainMenu::game_finished()
{
    qInfo("game finished");
}



void mainMenu::logged_player(QString username)
{
    user_logged = QString("%1").arg(username);
}

void mainMenu::closeLvSelection()
{
    show();
    stage_select->close();
    stage_select = nullptr;
}

void mainMenu::closeStatsWindow()
{
    show();
    stats_window->close();
    stats_window = nullptr;
}

void mainMenu::on_pushButton_logout_clicked()
{
    emit closeMenu();
}

void mainMenu::on_pushButton_clicked()
{
    stats_window = new Stats(this);
    stats_window->setAttribute(Qt::WA_DeleteOnClose);
    connect(stats_window, &Stats::closeStatsWindow, this, &mainMenu::closeStatsWindow);
    stats_window->setData(user_logged);
    stats_window->show();
    hide();
}
