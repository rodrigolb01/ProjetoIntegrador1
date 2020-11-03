#include "process.h"
#include <QDebug>
#include "game.h"

extern Game* game;

Process::Process( QObject *parent, int priority, int id, int actions_needed)
{
    Q_UNUSED(parent)
    this->priority = priority;
    this->ID = id;

    setRect(0,0,90,90);
    setBrush(Qt::blue);

    id=0;
    process_id = new QGraphicsTextItem(this);
    process_id->setFont(QFont("times",12));
    process_id->setPlainText(QString("ID: %1").arg(ID));
    process_id->setDefaultTextColor(Qt::yellow);
    process_id->setPos(x(),y()+18);

    actions = actions_needed;
    neccessary_actions = new QGraphicsTextItem(this);
    neccessary_actions->setFont(QFont("times",12));
    neccessary_actions->setPlainText(QString("Actions: %1").arg(actions));
    neccessary_actions->setDefaultTextColor(Qt::yellow);
    neccessary_actions->setPos(x(),y()+40);


    process_state = new QGraphicsTextItem(this);
    process_state->setPos(x(),y()+60);
    process_state->setFont(QFont("times",12));
    process_state->setDefaultTextColor(Qt::yellow);
    is_waiting=true;
    change_status_txt();

    wait_counter = 100;
    run_counter = 0;

    bar_execution = new QGraphicsRectItem(this);
    bar_execution->setRect(0,0,10,run_counter);
    bar_execution->setBrush(Qt::green);

    bar_execution->setPos(pos());
    bar_execution->hide();

    bar_waitingTime = new QGraphicsRectItem(this);
    bar_waitingTime->setRect(0,0,wait_counter,10);
    bar_waitingTime->setBrush(Qt::green);

    bar_waitingTime->setPos(pos());

    wait_timer = new QTimer(this);
    connect(wait_timer, &QTimer::timeout, this, &Process::waiting);
    wait_timer->setInterval(priority*300); // adjust waiting time here

    run_timer = new QTimer(this);
    run_timer->setInterval(300);

    execute_actions = new QTimer(this);
    execute_actions->setInterval(1000);

    move = new QTimer(this);
    move->setInterval(100);

    get_io = new QTimer(this);
}

// when a process is clicked once, hides it and show the game cursor instead,
//when clicking again, hides cursor, changes process to clicked position and show.

void Process::mousePressEvent(QGraphicsSceneMouseEvent* event){
    Q_UNUSED(event)


   qInfo() << "you cliked this process";
}

void Process::change_status_txt()
{
    if(is_waiting)
    {
        if(needs_io)
        {
            process_state->setPlainText("wating for i/o");
        }
        else
        {
            process_state->setPlainText("waiting");
        }
    }
    if(is_running)
        process_state->setPlainText("Running");
    if(is_interrupted)
        process_state->setPlainText("Interrupted");
    if(finished)
        process_state->setPlainText("Finished");
}

void Process::change_color(char color)
{
    switch (color) {
    case 'R': setBrush(Qt::red);break;
    case 'B': setBrush(Qt::blue);break;
    }
}

void Process::decreasePlayerScore()
{
    scoreInfo = new QGraphicsTextItem(this);
    scoreInfo->setPlainText("-30");
    scoreInfo->setDefaultTextColor(Qt::red);
    scoreInfo->setFont(QFont("times",20));

    connect(move, &QTimer::timeout, this, &Process::moveScoreUp);
    move->start();
}

void Process::moveScoreUp()
{
    if(scoreInfo)
    {
        scoreInfo->setPos(scoreInfo->x(),scoreInfo->y()-5);
        scoreInfo->setOpacity(scoreInfo->opacity()-0.05);
        if(scoreInfo->opacity()== 0)
            move->stop();
    }
}

void Process::waiting()
{
    if( is_running)//if the process is inside a cpu slot, stop waiting and start execute
    {    
        is_waiting=false;
        change_status_txt();
        emit notify_process_execution(ID);

        wait_timer->stop();
        bar_waitingTime->hide();
        disconnect(wait_timer, &QTimer::timeout, this, &Process::waiting);
        bar_execution->show();
        run_counter=0;
        setBrush(Qt::blue);
        bar_execution->setRect(0,0,10,run_counter);

        connect(run_timer, &QTimer::timeout, this, &Process::running);
        run_timer->start();
        execute_actions->start();
    }//if is not, keep waiting...

    wait_counter--;
    bar_waitingTime->setRect(0,0,wait_counter,10);



    //change the color of the bar as it decreases
    if(wait_counter <= 90)
        change_color('B');

    if(wait_counter <= 75)
        bar_waitingTime->setBrush(Qt::yellow);
    if(wait_counter <= 25)
        bar_waitingTime->setBrush(Qt::red);

    if(wait_counter == 0)//if this process ran out of time and was not processed by the cpu, stop everything and send the starved()
        //signal to the queue for deleting this process.
    {
        if(!is_running)
        {
            if(game->hp_count>0)
            {
                is_starving = true;
                wait_counter=100;
                bar_waitingTime->setBrush(Qt::green);
                game->p1->decrease();
                change_color('R');
                decreasePlayerScore();
                game->starved_processes++;
                game->losed = false;
            }
            else
            {
                game->losed = true;
                emit gameOver();
            }
        }
    }
}

void Process::running()
{
    if(actions<1)// if process already finished all his actions, stop running
    {
        run_timer->stop();
        is_running=false;
        finished=true;
        change_status_txt();
        bar_execution->hide();
    }
    else
    {
        if(is_waiting)
        {
            is_running=false;
            change_status_txt();

            run_timer->stop();
            execute_actions->stop();
            disconnect(run_timer, &QTimer::timeout, this, &Process::running);
            bar_execution->hide();

            connect(wait_timer, &QTimer::timeout, this, &Process::waiting);
            wait_counter = 100;
            bar_waitingTime->setRect(0,0,wait_counter,10);
            bar_waitingTime->setBrush(Qt::green);
            bar_waitingTime->show();
            wait_timer->start();
        }
        run_counter++;

        io_interrupt = QRandomGenerator::global()->bounded(-999,999);

        if(io_interrupt >=0 && io_interrupt <= 15)
        {
            is_running = false;
            is_waiting = true;
            needs_io = true;
            change_status_txt();

            int time = QRandomGenerator::global()->bounded(5000,8000);
            get_io->setInterval(time);
            connect(get_io, &QTimer::timeout, this, &Process::io);
            get_io->start();
            qInfo() << "io timer starts";

            run_timer->stop();
            disconnect(execute_actions, &QTimer::timeout, this, &Process::action);

            setBrush(Qt::yellow);
            neccessary_actions->setDefaultTextColor(Qt::blue);
            process_id->setDefaultTextColor(Qt::blue);
            process_state->setDefaultTextColor(Qt::blue);

            if(this == game->p1->slot1->process)
                emit slotIsFree(1);
            else if(this == game->p1->slot2->process)
                emit slotIsFree(2);
            else if(this == game->p1->slot3->process)
                emit slotIsFree(3);
            else if(this == game->p1->slot4->process)
                emit slotIsFree(4);


            game->InterruptedQueue->Add(this);

            if(io_interrupt >= 0 && io_interrupt <= 3)
            {
                qInfo() << "process needs keyboard input\n";
                emit notify_process_needs_io(ID,1);
            }
            else if(io_interrupt >= 4 && io_interrupt <= 7)
            {
                qInfo() << "process needs data from memory";
                emit notify_process_needs_io(ID,2);
            }
            else if(io_interrupt >= 8 && io_interrupt <= 11)
            {
                qInfo() << "process needs output from monitor\n";
                emit notify_process_needs_io(ID,3);
            }
            else if(io_interrupt >= 12 && io_interrupt <=15)
            {
                qInfo() << "process needs transfer data to pendrive\n";
                emit notify_process_needs_io(ID,4);
            }
            emit notify_process_interrupted(ID);
        }

        bar_execution ->setRect(0,0,10,run_counter);

        if(run_counter == 100 && finished==false)
        {


            game->p1->scoreCount++;
            game->p1->Pscore->setPlainText(QString("Score: %1").arg(game->p1->scoreCount));


            if(actions>=1)
            {
                if(game->p1->slot1->contains(game->p1->slot1->mapFromScene(this->pos())))
                {
                    qInfo() << " slot1 is now free!";
                    emit slotIsFree(1);
                }
                if(game->p1->slot2->contains(game->p1->slot2->mapFromScene(this->pos())))
                {
                    qInfo() << " slot2 is now free!";
                    emit slotIsFree(2);
                }
                if(game->p1->slot3->contains(game->p1->slot3->mapFromScene(this->pos())))
                {
                    qInfo() << " slot3 is now free!";
                    emit slotIsFree(3);
                }
                if(game->p1->slot4->contains(game->p1->slot4->mapFromScene(this->pos())))
                {
                    qInfo() << " slot4 is now free!";
                    emit slotIsFree(4);
                }

                game->waitingQueue->Add(this);
                is_waiting=true;
                is_running=false;
                wait_timer->start();
                run_timer->stop();
                setBrush(Qt::gray);
                run_timer->stop();
                running();
                neccessary_actions->setPlainText(QString("Actions: %1").arg(actions));

                game->scene->addItem(this);

            }
            else
            {
                run_timer->stop();
                is_running=false;
                finished=true;
                change_status_txt();
                bar_execution->hide();
            }
        }
    }
}

void Process::io()
{
    qInfo() << "\nio is ready!";
    actions+=QRandomGenerator::global()->bounded(1,5);
    neccessary_actions->setPlainText(QString("Actions: %1").arg(actions));
    needs_io=false;
    emit notify_io_ready(ID);
    get_io->stop();
    disconnect(get_io, &QTimer::timeout, this, &Process::io);
}

void Process::action()
{
    if(actions>0)
    {
        actions--;
        neccessary_actions->setPlainText(QString("Actions: %1").arg(actions));
    }
}
