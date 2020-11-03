#include "pausebutton.h"
#include "game.h"
#include <QDebug>

extern Game* game;

PauseButton::PauseButton(QObject* parent)
{
     Q_UNUSED(parent)
    setRect(0,0,50,50);
    setBrush(Qt::blue);
    txt = new QGraphicsTextItem(this);
    txt->setPlainText("Pause");
    txt->setFont(QFont("times",10));
    txt->setPos(pos());

}

void PauseButton::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
     Q_UNUSED(event)
    stop_start_allTimers();
    return;
}

void PauseButton::stop_start_allTimers()
{
    if(stopped == false)
    {
        paused = new QGraphicsTextItem(this);
        paused->setFont(QFont("times",40));
        paused->setPlainText("PAUSED");
        paused->setPos(QPointF(540, 300));

        txt->setPlainText("Resume");

        for(int i=0; i<game->waitingQueue->Size(); i++)
        {
            game->waitingQueue->processAt(i)->wait_timer->stop();
            game->waitingQueue->processAt(i)->run_timer->stop();
        }
        for(int i=0 ;i<game->InterruptedQueue->Size(); i++)
        {
            game->InterruptedQueue->processAt(i)->get_io->stop();
        }
        if(game->p1->slot1Occupied)
        {
            game->p1->slot1->process->run_timer->stop();
            game->p1->slot1->process->execute_actions->stop();
        }
        if(game->p1->slot2Occupied)
        {
            game->p1->slot2->process->run_timer->stop();
            game->p1->slot2->process->execute_actions->stop();
        }
        if(game->p1->slot3Occupied)
        {
            game->p1->slot3->process->run_timer->stop();
            game->p1->slot3->process->execute_actions->stop();
        }
        if(game->p1->slot4Occupied)
        {
            game->p1->slot4->process->run_timer->stop();
            game->p1->slot4->process->execute_actions->stop();
        }
        stopped = true;
    }
    else
    {
        delete paused;

        txt->setPlainText("Pause");

        for(int i=0; i<game->waitingQueue->Size(); i++)
        {
            game->waitingQueue->processAt(i)->wait_timer->start();
            game->waitingQueue->processAt(i)->run_timer->start();
        }
        for(int i=0; i<game->InterruptedQueue->Size(); i++)
        {
            game->InterruptedQueue->processAt(i)->get_io->start();
        }
        if(game->p1->slot1Occupied)
        {
            game->p1->slot1->process->run_timer->start();
            game->p1->slot1->process->execute_actions->start();
        }
        if(game->p1->slot2Occupied)
        {
            game->p1->slot2->process->run_timer->start();
            game->p1->slot2->process->execute_actions->start();
        }
        if(game->p1->slot3Occupied)
        {
            game->p1->slot3->process->run_timer->start();
            game->p1->slot3->process->execute_actions->start();
        }
        if(game->p1->slot4Occupied)
        {
            game->p1->slot4->process->run_timer->start();
            game->p1->slot4->process->execute_actions->start();
        }
        stopped = false;
    }
}
