#include "game.h"
#include "QLayout"

Game::Game(QWidget* parent, int total_processes, int priority_low, int priority_high, QString username, int gamemode, int lv): QGraphicsView()
{
    //set parameters for the game
    Q_UNUSED(parent)
    GAMEMODE = gamemode;
    LV = lv;
    user_name = username;
    if(GAMEMODE==0)
        totalProcesses = 999;
    else
        totalProcesses = total_processes;
    prior_low = priority_low;
    prior_high = priority_high;

    //set scene;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1400,700);
    setScene(scene);

    //set cursor;
    cursor = new QGraphicsRectItem();
    cursor->setRect(0,0,100,100);
    cursor->setBrush(Qt::blue);
    scene->addItem(cursor);
    cursor->hide();
    setMouseTracking(true);
    dragging = false;
    dragging_process = nullptr;
    slot_the_process_is_going_to = nullptr;
    slot_the_process_is_coming_from = nullptr;

    //set window
    setFixedSize(1400,700);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //making the core(player)
    p1 = new CpuCore(this,1);
    p1->blocker->setZValue(10);
    p1->setZValue(1);
    scene->addItem(p1);
    scene->addItem(p1->slot1);
    scene->addItem(p1->slot2);
    scene->addItem(p1->slot3);
    scene->addItem(p1->slot4);
    p1->slot1->setPos(605,345);
    p1->slot2->setPos(710,345);
    p1->slot3->setPos(605,450);
    p1->slot4->setPos(710,450);
    p1->setPos(600,340);


    //monitor
    monitor = new displayScreen();
    monitor->setPos(QPointF(150,350));
    scene->addItem(monitor);

    //create queues
    InterruptedQueue = new ProcessQueue(this);
    InterruptedQueue->label->setPlainText("Interrupted processes");
    scene->addItem(InterruptedQueue);
    InterruptedQueue->setPos(QPointF(x()+95,y()+75));

    waitingQueue = new ProcessQueue(this);
    connect(waitingQueue, &ProcessQueue::populate_queue, this, &Game::fill_waiting_queue);
    waitingQueue->label->setPlainText("Waiting");
    scene->addItem(waitingQueue);
    waitingQueue->setPos(QPointF(95,235));

    fill_waiting_queue();


    //add the pause button
    pause = new PauseButton(this);
    scene->addItem(pause);
    pause->setZValue(10);

    //add area for interruptProcess
    interruptArea = new InterruptProcess(this);
    interruptArea->setPos(850,350);
    scene->addItem(interruptArea);

    //add area for finishProcess
    finishArea = new FinishProcess(this);
    finishArea->setPos(850,450);
    scene->addItem(finishArea);

    //add the HP bar
    hp_count=200;
    hp_bar = new QGraphicsRectItem();
    hp_bar->setRect(0,0,hp_count,20);
    hp_bar->setBrush(Qt::green);
    hp_bar->setPos(450,30);
    scene->addItem(hp_bar);
    hp_bar_border = new QGraphicsRectItem(0,0,204,24);
    hp_bar_border->setPos(448,28);
    hp_bar->setPen(Qt::PenStyle::SolidLine);
    scene->addItem(hp_bar_border);

    //set data for scoreBoard
    gameTime = new QTimer(this);
    gameTime->setInterval(1000);
    connect(gameTime, &QTimer::timeout, this, &Game::set_time);
    gameTime->start();
}


void Game::mouseMoveEvent(QMouseEvent *event){
    //makes the cursor moves
    if (cursor)
        cursor->setPos(event->pos());
}

void Game::interruptProcess(Process *p, ProcessSlot* slot_the_process_is_coming_from)
{
    p->is_running = false;
    p->is_waiting = false;
    p->is_interrupted = true;
    p->change_status_txt();

    p->run_timer->stop();
    disconnect(p->execute_actions, &QTimer::timeout, p, &Process::action);

    p->setBrush(Qt::yellow);
    p->neccessary_actions->setDefaultTextColor(Qt::blue);
    p->process_id->setDefaultTextColor(Qt::blue);
    p->process_state->setDefaultTextColor(Qt::blue);

    if(slot_the_process_is_coming_from == p1->slot1)
        p->emit slotIsFree(1);
    else if(slot_the_process_is_coming_from == p1->slot2)
        p->emit slotIsFree(2);
    else if(slot_the_process_is_coming_from == p1->slot3)
        p->emit slotIsFree(3);
    else if(slot_the_process_is_coming_from == p1->slot4)
        p->emit slotIsFree(4);

    p->emit notify_process_interrupted(p->ID);

    InterruptedQueue->Add(p);
}

int Game::countProcesses()
{
    int count=0;
    count+=waitingQueue->size;
    count+=InterruptedQueue->size;
    if(p1->slot1Occupied)
        count++;
    if(p1->slot2Occupied)
        count++;
    if(p1->slot3Occupied)
        count++;
    if(p1->slot4Occupied)
        count++;

    if(count==0)
    {
        game_over();
    }
    return count;
}

void Game::set_time()
{
    time_count++;
}

void Game::fill_waiting_queue()
{
    for(int i=waitingQueue->Size() ;i<13; i++)
    {
        int priority = QRandomGenerator::global()->bounded(prior_low,prior_high);
        int actions = QRandomGenerator::global()->bounded(15,30);
        int id = QRandomGenerator::global()->bounded(0,99);
        Process* p = new Process(waitingQueue, priority, id, actions);
        scene->addItem(p);
        p->setZValue(2);
        connect(p, &Process::gameOver, this, &Game::game_over);
        connect(p, &Process::starved, waitingQueue, &ProcessQueue::remove_process);
        connect(p, &Process::slotIsOccupied, p1, &CpuCore::slotIsOccupied);
        connect(p, &Process::slotIsFree, p1, &CpuCore::slotIsFree);
        connect(p, &Process::process_was_terminated, p1, &CpuCore::process_was_terminated);
        connect(p, &Process::process_starved, p1, &CpuCore::process_starved);
        connect(p, &Process::notify_process_interrupted, monitor, &displayScreen::notify_process_interrupted);
        connect(p, &Process::notify_process_execution, monitor, &displayScreen::notify_process_execution);
        connect(p, &Process::notify_process_needs_io, monitor, &displayScreen::notify_process_needs_io);
        connect(p, &Process::notify_io_ready, monitor, &displayScreen::notify_io_ready);
        connect(p->execute_actions, &QTimer::timeout, p, &Process::action);
        p->wait_timer->start();
        waitingQueue->Add(p);
    }
}

void Game::game_over()
{
    qInfo() << "losed: " << losed;
    qInfo() << time_count;
    score_board = nullptr;
    score_board = new ScoreBoard(this,finished_processes,starved_processes,hp_count,time_count,p1->scoreCount, LV);
    score_board->setZValue(10);
    pause->stop_start_allTimers();

    qInfo() << "GAME FINISHED!";
    gameTime->stop();
    scene->addItem(score_board);
    scene->addWidget(score_board->back_to_menu);
    score_board->setPos(420,200);
    score_board->back_to_menu->move(420,600);
    int totalScore = score_board->getScore();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","conn");
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
        QString update;

        if(GAMEMODE==1)
        {
            switch (LV) {
            case 1: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv1 = CASE WHEN maxScore_Lv1 < %2 THEN %2 ELSE maxScore_Lv1 END WHERE username = '%1';").arg(user_name).arg(totalScore);break;
            case 2: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv2 = CASE WHEN maxScore_Lv2 < %2 THEN %2 ELSE maxScore_Lv2 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 3: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv3 = CASE WHEN maxScore_Lv3 < %2 THEN %2 ELSE maxScore_Lv3 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 4: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv4 = CASE WHEN maxScore_Lv4 < %2 THEN %2 ELSE maxScore_Lv4 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 5: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv5 = CASE WHEN maxScore_Lv5 < %2 THEN %2 ELSE maxScore_Lv5 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 6: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv6 = CASE WHEN maxScore_Lv6 < %2 THEN %2 ELSE maxScore_Lv6 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 7: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv7 = CASE WHEN maxScore_Lv7 < %2 THEN %2 ELSE maxScore_Lv7 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            case 8: update = QString("UPDATE users set played_campaign = played_campaign+1 WHERE login = '%1';"
                                     "UPDATE max_score SET maxScore_Lv8 = CASE WHEN maxScore_Lv8 < %2 THEN %2 ELSE maxScore_Lv8 END WHERE username = '%1';").arg(user_name).arg(totalScore); break;
            }
        }
        else
            update = QString("UPDATE users SET played_survival = played_survival+1 WHERE login = '%1';"
                             "UPDATE max_score SET maxScore_survival = CASE WHEN maxScore_survival < %2 THEN %2 ELSE maxScore_survival END WHERE username = '%1';").arg(user_name).arg(totalScore);

        q.prepare(update);
        if(q.exec())
        {
            if(losed==true)
            {
                switch (LV) {
                case 1:  update = QString("UPDATE losed SET loseLv1 = loseLv1+1 WHERE username = '%1';").arg(user_name); break;
                case 2:  update = QString("UPDATE losed SET loseLv2 = loseLv2+1 WHERE username = '%1';").arg(user_name); break;
                case 3:  update = QString("UPDATE losed SET loseLv3 = loseLv3+1 WHERE username = '%1';").arg(user_name); break;
                case 4:  update = QString("UPDATE losed SET loseLv4 = loseLv4+1 WHERE username = '%1';").arg(user_name); break;
                case 5:  update = QString("UPDATE losed SET loseLv5 = loseLv5+1 WHERE username = '%1';").arg(user_name); break;
                case 6:  update = QString("UPDATE losed SET loseLv6 = loseLv6+1 WHERE username = '%1';").arg(user_name); break;
                case 7:  update = QString("UPDATE losed SET loseLv7 = loseLv7+1 WHERE username = '%1';").arg(user_name); break;
                case 8:  update = QString("UPDATE losed SET loseLv8 = loseLv8+1 WHERE username = '%1';").arg(user_name); break;
                }
            }
            else
            {
                switch (LV) {
                case 1: update = QString("UPDATE users SET Lv1_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 2: update = QString("UPDATE users SET Lv2_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 3: update = QString("UPDATE users SET Lv3_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 4: update = QString("UPDATE users SET Lv4_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 5: update = QString("UPDATE users SET Lv5_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 6: update = QString("UPDATE users SET Lv6_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 7: update = QString("UPDATE users SET Lv7_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                case 8: update = QString("UPDATE users SET Lv8_Clear = '1' WHERE login = '%1';").arg(user_name); break;
                }
            }
            if(q.exec(update))
                db.commit();
            else
            {
                QMessageBox warning;
                warning.setText("queue failed!" "could not update data");
                warning.exec();
            }
            db.commit();
            emit update_userData();
        }
        else
        {
            QMessageBox warning;
            warning.setText("queue failed!" "could not update data");
            warning.exec();
        }
    }
    db.close();
}


void Game::mousePressEvent(QMouseEvent *event){
    /*select a process from somewhere and place it in somewhere else following the cases:
     *
     * 1* if process is inside the waiting queue , the process must go to a slot in the second click and start execute
     *
     * 2* if process is inside a slot:
     * * process can be interrupted during execution
     * * process can be placed back in the waiting queue
     * * process can be finished(but player only gets score if it's finished)
     *
     * 3* if process is inside the ready queue and is INTERRUPTED, it can go back to a slot and continue be execued
     *
     */
   if(dragging)// 2nd click (RELEASE AND RESET)
   {
      if(found_in_waiting||found_in_interrupted) // go to a slot
      {
          if(p1->slot1->contains(p1->slot1->mapFromScene(event->pos())))
          {
              if(!p1->slot1Occupied)
              {
                    p1->slot1->process = dragging_process;
                    slot_the_process_is_going_to = p1->slot1;
                    dragging_process->emit slotIsOccupied(1);

                    qInfo() << " you placed the process in the slot 1";
              }
              else
              {
                  pause->stop_start_allTimers();
                  QMessageBox warning;
                  warning.setText("this slot is occupied!");
                  warning.exec();
                  if(warning.Close)
                      pause->stop_start_allTimers();

                  dragging=false;
                  dragging_process->show();
                  cursor->hide();
                  dragging_process=nullptr;
              }
          }
          if(p1->slot2->contains(p1->slot2->mapFromScene(event->pos())))
          {
              if(!p1->slot2Occupied)
              {
                  p1->slot2->process = dragging_process;
                  slot_the_process_is_going_to = p1->slot2;
                  dragging_process->emit slotIsOccupied(2);
                  qInfo() << " you placed the process in the slot 2";
              }
              else
              {
                  pause->stop_start_allTimers();
                  QMessageBox warning;
                  warning.setText("this slot is occupied!");
                  warning.exec();
                  if(warning.Close)
                      pause->stop_start_allTimers();

                  dragging=false;
                  dragging_process->show();
                  cursor->hide();
                  dragging_process=nullptr;
              }
          }
          if(p1->slot3->contains(p1->slot3->mapFromScene(event->pos())))
          {
              if(!p1->slot3Occupied)
              {
                  p1->slot3->process = dragging_process;
                  slot_the_process_is_going_to = p1->slot3;
                  dragging_process->emit slotIsOccupied(3);
                  qInfo() << " you placed the process in the slot 3";
              }
              else
              {
                  pause->stop_start_allTimers();
                  QMessageBox warning;
                  warning.setText("this slot is occupied!");
                  warning.exec();
                  if(warning.Close)
                      pause->stop_start_allTimers();

                  dragging=false;
                  dragging_process->show();
                  cursor->hide();
                  dragging_process=nullptr;
              }
          }
          if(p1->slot4->contains(p1->slot4->mapFromScene(event->pos())))
          {
              if(!p1->slot4Occupied)
              {
                  p1->slot4->process = dragging_process;
                  slot_the_process_is_going_to = p1->slot4;
                  dragging_process->emit slotIsOccupied(4);
                  qInfo() << " you placed the process in the slot 4";
              }
              else
              {
                  pause->stop_start_allTimers();
                  QMessageBox warning;
                  warning.setText("this slot is occupied!");
                  warning.exec();
                  if(warning.Close)
                      pause->stop_start_allTimers();

                  dragging=false;
                  dragging_process->show();
                  cursor->hide();
                  dragging_process=nullptr;
              }
          }


          //if process is going to a slot, then start execution
          if(slot_the_process_is_going_to)
          {
              //run process
              dragging_process->is_waiting = false;
              dragging_process->is_running = true;
              dragging_process->change_status_txt();

              dragging_process->setPos(slot_the_process_is_going_to->x()+100, slot_the_process_is_going_to->y()+5);///
              if(found_in_waiting)
              {
                  waitingQueue->Remov(dragging_process);
                  slot_the_process_is_going_to = nullptr;
              }
              else if(found_in_interrupted)// if this process is interrupted, then run it again from where it stopped!
              {
                  dragging_process->is_interrupted=false;
                  dragging_process->is_running = true;
                  dragging_process->is_waiting=false;
                  dragging_process->change_status_txt();

                  dragging_process->setBrush(Qt::blue);
                  dragging_process->neccessary_actions->setDefaultTextColor(Qt::yellow);
                  dragging_process->process_id->setDefaultTextColor(Qt::yellow);
                  dragging_process->process_state->setDefaultTextColor(Qt::yellow);

                  dragging_process->run_timer->start();
                  connect(dragging_process->execute_actions, &QTimer::timeout, dragging_process, &Process::action);

                 Process *p = InterruptedQueue->Remov(dragging_process);
              }
          }
          else
          {
              QGraphicsView::mousePressEvent(event);
          }
          if(dragging_process)
          {
              dragging_process->show();
              dragging_process = nullptr;
          }
      }
      else if(foundInSlot)
      {
          //player clicked waiting queue
          if(waitingQueue->bounding_rect->contains(waitingQueue->bounding_rect->mapFromScene(event->pos())))
          {
              //add to waiting queue
              dragging_process->is_waiting = true;
              dragging_process->is_running = false;
              dragging_process->change_status_txt();

              waitingQueue->Add(dragging_process);

              //free slot
              if(slot_the_process_is_coming_from == p1->slot1)
                  dragging_process->emit slotIsFree(1);
              else if(slot_the_process_is_coming_from == p1->slot2)
                  dragging_process->emit slotIsFree(2);
              else if(slot_the_process_is_coming_from == p1->slot3)
                  dragging_process->emit slotIsFree(3);
              else if(slot_the_process_is_coming_from == p1->slot4)
                  dragging_process->emit slotIsFree(4);

              slot_the_process_is_coming_from->process = nullptr;
              dragging_process->show();
              //reset
              dragging_process = nullptr;
          }
          else if(interruptArea->contains(interruptArea->mapFromScene(event->pos())))// interrupt process
          {
              //interrupt this process
              interruptProcess(dragging_process , slot_the_process_is_coming_from);
              slot_the_process_is_coming_from->process = nullptr;
              dragging_process->show();
              dragging_process = nullptr;
          }
          else if(finishArea->contains(finishArea->mapFromScene(event->pos())))// finish process
          {
              if(dragging_process->finished)
              {
                      //finish this process
                  if(slot_the_process_is_coming_from == p1->slot1)
                      dragging_process->emit slotIsFree(1);
                  else if(slot_the_process_is_coming_from == p1->slot2)
                      dragging_process->emit slotIsFree(2);
                  else if(slot_the_process_is_coming_from == p1->slot3)
                      dragging_process->emit slotIsFree(3);
                  else if(slot_the_process_is_coming_from == p1->slot4)
                      dragging_process->emit slotIsFree(4);

                  slot_the_process_is_coming_from->process = nullptr;

                  scene->removeItem(dragging_process);
                  dragging_process = nullptr;

                  p1->scoreCount+=5;
                  qInfo() << "SCORE: " << p1->scoreCount;
                  p1->Pscore->setPlainText(QString("Score: %1").arg(p1->scoreCount));
                  totalProcesses--;
                  finished_processes++;
                  countProcesses();
              }
              else
              {
                  pause->stop_start_allTimers();
                  QMessageBox warning;
                  warning.setText("this process have not finished yet!");
                  warning.exec();
                  if(warning.Close)
                      pause->stop_start_allTimers();

                  dragging=false;
                  dragging_process->show();
                  cursor->hide();
                  dragging_process=nullptr;
              }
          }
          else
          {
              QGraphicsView::mousePressEvent(event);
              dragging_process->show();
              dragging_process = nullptr;
          }
      }
      dragging = false;
      foundInSlot=false;
      found_in_waiting=false;
      found_in_interrupted=false;
      cursor->hide();
   }

   else// 1st click (SELECT AND DRAG)
   {
       //look for the clicked process in the waiting queue
       Node* n;
       for(n = waitingQueue->front; n!= NULL; n=n->next)
       {
           if(n->process->contains(n->process->mapFromScene(event->pos())))
           {
               //found
               dragging_process = n->process;
               found_in_waiting = true;
           }
       }//<-is not waiting

       //look for the clicked process in the interrupted queue
       if(!found_in_waiting)
       {
           Node* n;
           for(n=InterruptedQueue->front; n != NULL; n=n->next)
           {
               if(n->process->contains(n->process->mapFromScene(event->pos())))
               {
                   if(!n->process->needs_io)
                   {
                       dragging_process = n->process;
                       found_in_interrupted=true;
                   }
                   else
                   {
                       QMessageBox warning;
                       warning.setText("this process is waiting for a i/o event!");
                       pause->stop_start_allTimers();
                       warning.exec();
                       if(warning.close())
                           pause->stop_start_allTimers();
                   }
               }
           }
       }//is not interrupted

       //look in the slots
       if(!found_in_interrupted && !found_in_waiting)
       {
           if(p1->slot1Occupied)
           {
               if(p1->slot1->process->contains(p1->slot1->process->mapFromScene(event->pos())))
               {
                   //found
                   qInfo() << "you selected the process from the slot 1";
                   dragging_process = p1->slot1->process;
                   foundInSlot = true;
                   slot_the_process_is_coming_from = p1->slot1;
               }//is not in the slot1
           }
           if(p1->slot2Occupied)
           {
               if(p1->slot2->process->contains(p1->slot2->process->mapFromScene(event->pos())))
               {
                   //found
                    qInfo() << "you selected the process from the slot 2";
                   dragging_process = p1->slot2->process;
                   foundInSlot = true;
                   slot_the_process_is_coming_from = p1->slot2;
               }//is not in the slot2
           }
           if(p1->slot3Occupied)
           {
               if(p1->slot3->process->contains(p1->slot3->process->mapFromScene(event->pos())))
               {
                   //found
                    qInfo() << "you selected the process from the slot 3";
                   dragging_process = p1->slot3->process;
                   foundInSlot = true;
                   slot_the_process_is_coming_from = p1->slot3;
               }//is not in the slot 3
           }
           if(p1->slot4Occupied)
           {
               if(p1->slot4->process->contains(p1->slot4->process->mapFromScene(event->pos())))
               {
                   //found
                    qInfo() << "you selected the process from the slot 4";
                   dragging_process = p1->slot4->process;
                   foundInSlot = true;
                   slot_the_process_is_coming_from = p1->slot4;
               }//is not in slot 4
           }
       }//player have not clicked in a process.

       //if player selected a process
       if(foundInSlot||found_in_waiting||found_in_interrupted)
       {
           dragging = true;
           cursor->show();
           dragging_process->hide();
       }
       else//pass the event down if no process was clicked
       {
           QGraphicsView::mousePressEvent(event);
       }
   }
}



