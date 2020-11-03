#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QFont>
#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlDriver>

#include "processqueue.h"
#include "processslot.h"
#include "cpucore.h"
#include "pausebutton.h"
#include "interruptprocess.h"
#include "finishprocess.h"
#include "proccess.h"
#include "displayscreen.h"
#include "scoreboard.h"


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent, int total_processes=0, int priority_low=1, int priority_high=10, QString username=0, int gamemode=0, int lv=0);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void interruptProcess(Process* p, ProcessSlot* slot_the_process_is_coming_from);
    void set_time();
    int countProcesses();
    bool dragging;//true if player clicks and drag some process
    bool foundInSlot=false;
    bool found_in_waiting=false;
    bool found_in_interrupted=false;
    bool losed=false;

    //pointer to dragging process
    Process* dragging_process;
    ProcessSlot* slot_the_process_is_going_to;
    ProcessSlot* slot_the_process_is_coming_from;
    QString user_name;

    //member attributes
    int GAMEMODE=0;//0 - survival/ 1 - campaign
    int LV=0;
    int processes_in_scene=0;
    int totalProcesses=0;
    int prior_low=0;
    int prior_high=0;


    int finished_processes=0;
    int starved_processes=0;
    int hp_count;
    int time_count=0;

    QTimer* gameTime;
    QTimer* count_remainig_processes;
    QGraphicsScene* scene;
    QGraphicsRectItem* hp_bar;
    QGraphicsRectItem* hp_bar_border;
    QGraphicsRectItem* cursor;
    ProcessQueue* InterruptedQueue;
    ProcessQueue* waitingQueue;
    PauseButton* pause;
    InterruptProcess* interruptArea;
    FinishProcess* finishArea;

    CpuCore* p1;
    displayScreen* monitor;
    ScoreBoard* score_board;

public slots:
    void fill_waiting_queue();
    void game_over();

signals:
    void closeGame();
    void update_userData();
};

#endif // GAME_H
