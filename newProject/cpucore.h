#ifndef CPUCORE_H
#define CPUCORE_H

#include <QObject>
#include "processslot.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>

class CpuCore: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CpuCore(QObject* parent=0, int playerNumber=0);

    ProcessSlot* slot1;
    ProcessSlot* slot2;
    ProcessSlot* slot3;
    ProcessSlot* slot4;

    bool slot1Occupied=false;
    bool slot2Occupied=false;
    bool slot3Occupied=false;
    bool slot4Occupied=false;

    int scoreCount;

    QGraphicsTextItem* info;
    QGraphicsTextItem* Pscore;
    QGraphicsTextItem* P;

    QGraphicsRectItem* border;
    QGraphicsRectItem* blocker;

    QTimer* fadeText_timer;
public slots:
    void slotIsOccupied(int slot);
    void slotIsFree(int slot);
    void fadeInfoText();
    void process_was_terminated(int process_id);
    void process_starved(int process_id);
    void decrease();
    void increase();


};

#endif // CPUCORE_H
