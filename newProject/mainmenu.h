#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

#include "game.h"
#include "lvselection.h"
#include "stats.h"

namespace Ui {
class mainMenu;
}

class mainMenu : public QDialog
{
    Q_OBJECT
public:
    explicit mainMenu(QWidget *parent = nullptr);
    ~mainMenu();
    QString user_logged;

private slots:
    void on_pushButton_campaign_clicked();

    void on_pushButton_survival_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_clicked();

private:
    Ui::mainMenu *ui;
    int playedInSurvival;
    int playedInCampaign;
    int losedCampaign1;
    int maxScoreSurvival;
    int maxScoreCapaign1;
    LvSelection* stage_select;
    Stats* stats_window;

public slots:
    void game_finished();
    void logged_player(QString username);
    void closeLvSelection();
    void closeStatsWindow();
signals:
    void closeMenu();
};

#endif // MAINMENU_H
