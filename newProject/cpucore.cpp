#include "cpucore.h"
#include "game.h"
#include "QDebug"

extern Game* game;

CpuCore::CpuCore(QObject* parent, int playerNumber)
{
     Q_UNUSED(parent)
    slot1 = new ProcessSlot(this);
    slot2 = new ProcessSlot(this);
    slot3 = new ProcessSlot(this);
    slot4 = new ProcessSlot(this);
    slot1Occupied=false;
    slot2Occupied=false;
    slot3Occupied=false;
    slot4Occupied=false;

    P = new QGraphicsTextItem(this);
    P->setPlainText(QString("P%1").arg(playerNumber));
    P->setFont(QFont("times",20));
    P->setDefaultTextColor(Qt::black);
    P->setPos(x()-40,y()+30);


    border = new QGraphicsRectItem(this);
    border->setRect(QRectF(0,0,215,215));

    blocker = new QGraphicsRectItem(this);
    blocker->setRect(QRectF(0,0,215,215));
    blocker->setBrush(Qt::red);
    blocker->setOpacity(0.5);
    blocker->setZValue(zValue()+1);
    blocker->setPos(pos());
    blocker->hide();


    info = new QGraphicsTextItem(this);
    info->setPos(x()-150,y());


    fadeText_timer = new QTimer(this);
    fadeText_timer->setInterval(500);
    connect(fadeText_timer, &QTimer::timeout, this, &CpuCore::fadeInfoText);



    scoreCount=0;
    Pscore = new QGraphicsTextItem(this);
    Pscore->setPlainText(QString("Score: %1").arg(scoreCount));
    Pscore->setFont(QFont("times",20));
    Pscore->setDefaultTextColor(Qt::black);
    Pscore->setPos(x()-30,y()+210);
}

void CpuCore::process_was_terminated(int process_id)
{
    info->setPlainText(QString("The process ID: %1 terminated").arg(process_id));
    qInfo() << "process ID: " << process_id << "was terminated\n";    
}

void CpuCore::process_starved(int process_id)
{
    info->setPlainText(QString("The process ID: %1 starved!").arg(process_id));
    qInfo() << "process id:" <<process_id << " starved\n";
}

void CpuCore::fadeInfoText()
{
    if(info->opacity()>0)
    {
        info->setOpacity(info->opacity()-0.1);
    }
    else
    {
        fadeText_timer->stop();
    }
}



void CpuCore::decrease()
{
    if(game->hp_count>0)
    {
        if(game->hp_count <= 120)
            game->hp_bar->setBrush(Qt::yellow);
        if(game->hp_count <= 60)
            game->hp_bar->setBrush(Qt::red);
        game->hp_count-=30;
        game->hp_bar->setRect(0,0,game->hp_count,20);
    }
}

void CpuCore::increase()
{
    if(game->hp_count<200)
    {
        game->hp_count+=30;
        game->hp_bar->setRect(0,0,game->hp_count,20);
    }
}

void CpuCore::slotIsOccupied(int slot)
{
    switch (slot) {
    case 1: slot1Occupied = true; break;
    case 2: slot2Occupied = true; break;
    case 3: slot3Occupied = true; break;
    case 4: slot4Occupied = true; break;
    }
}

void CpuCore::slotIsFree(int slot)
{
    switch (slot) {
    case 1: slot1Occupied = false; break;
    case 2: slot2Occupied = false; break;
    case 3: slot3Occupied = false; break;
    case 4: slot4Occupied = false; break;
    }
}
