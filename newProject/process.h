#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>


class Process : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Process(QObject *parent=0, int priority=0, int id=0, int actions_needed=0);
    void waiting();
    void running();
    void change_status_txt();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    QGraphicsRectItem* bar_waitingTime;
    QGraphicsRectItem* bar_execution;
    QGraphicsRectItem* bar_actionsUntilFinish;
    QGraphicsTextItem* neccessary_actions;
    QGraphicsTextItem* process_id;
    QGraphicsTextItem* process_state;
    QGraphicsTextItem* scoreInfo;
    int ID;
    int actions;
    int wait_counter, run_counter;
    int priority;
    int io_interrupt;
    QTimer* wait_timer;
    QTimer* run_timer;
    QTimer* execute_actions;
    QTimer* get_io;
    QTimer* move;

    void action();
    void change_color(char color);
    void decreasePlayerScore();
    void increasePlayerScore();
    void moveScoreUp();
    void io();

    bool is_waiting=false;
    bool is_running=false;
    bool is_starving=false;
    bool is_interrupted=false;
    bool needs_io=false;
    bool finished=false;

signals:
    void terminated();
    void starved();
    void process_was_terminated(int id);
    void process_starved(int id);

    void notify_process_interrupted(int process_id);
    void notify_process_execution(int process_id);
    void notify_process_needs_io(int process_id, int io);
    void notify_io_ready(int process_id);

    void slotIsOccupied(int slot);
    void slotIsFree(int slot);

    void gameOver();



};

#endif // PROCESS_H
