#include "scoreboard.h"
#include "game.h"

extern Game* game;

ScoreBoard::ScoreBoard(QObject* parent, int f, int s, int u, int t, int sc, int lv)
{
    Q_UNUSED(parent)

    setRect(QRectF(0,0,400,400));
    setBrush(Qt::darkBlue);

    QPen pen(Qt::green, 2);
    setPen(pen);


    finished_processes = new QGraphicsTextItem(this);
    finished_processes->setPlainText(QString("finished processes: %1").arg(f));
    finished_processes->setFont(QFont("times",15));
    finished_processes->setDefaultTextColor(Qt::green);
    finished_processes->setPos(x()+100,y()+60);

    starved_processes = new QGraphicsTextItem(this);
    starved_processes->setPlainText(QString("starved processes:  %1").arg(s));
    starved_processes->setFont(QFont("times",15));
    starved_processes->setPos(x()+100,y()+90);
    starved_processes->setDefaultTextColor(Qt::green);

    user_satisfaction = new QGraphicsTextItem(this);
    user_satisfaction->setPlainText(QString("user satisfaction:     %1").arg(u));
    user_satisfaction->setFont(QFont("times",15));
    user_satisfaction->setPos(x()+100,y()+120);
    user_satisfaction->setDefaultTextColor(Qt::green);

    total_time = new QGraphicsTextItem(this);
    float timeInMinutes = t/60;
    float timeInsSeconds = t - timeInMinutes*60;
    total_time->setPlainText(QString("total time:                %1:%2 ").arg(timeInMinutes).arg(timeInsSeconds));
    total_time->setFont(QFont("times",15));
    total_time->setPos(x()+100,y()+150);
    total_time->setDefaultTextColor(Qt::green);

    score = new QGraphicsTextItem(this);
    score->setPlainText(QString("score:                      %1").arg(sc));
    score->setFont(QFont("times",15));
    score->setPos(x()+100, y()+180);
    score->setDefaultTextColor(Qt::green);

    back_to_menu = new QPushButton();
    back_to_menu->setText("back to menu");
    connect(back_to_menu, &QPushButton::clicked, this, &ScoreBoard::emit_game_finished);

    if(lv!=0)
        tsc = (f + s + u + t + sc)/5*lv;
    else
        tsc = (f + s + u + t + sc)/5;
    TotalScore = new QGraphicsTextItem(this);
    TotalScore->setPlainText(QString("total score:                %1").arg(tsc));
    TotalScore->setFont(QFont("times",15));
    TotalScore->setDefaultTextColor(Qt::green);
    TotalScore->setPos(x()+100,y()+210);
}

int ScoreBoard::getScore()
{
    return tsc;
}

void ScoreBoard::emit_game_finished()
{
    game->emit closeGame();
    game->close();
}
