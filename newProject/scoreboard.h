#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QPushButton>
#include <QTime>

class ScoreBoard: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ScoreBoard(QObject* parent=0, int f=0, int s=0, int u=0, int t=0, int sc=0, int lv=0);
    QGraphicsTextItem* finished_processes;
    QGraphicsTextItem* starved_processes;
    QGraphicsTextItem* user_satisfaction;
    QGraphicsTextItem* total_time;
    QGraphicsTextItem* score;
    QGraphicsTextItem* TotalScore;
    QPushButton* back_to_menu;
    int tsc;
    int getScore();

private slots:
    void emit_game_finished();

};

#endif // SCOREBOARD_H
