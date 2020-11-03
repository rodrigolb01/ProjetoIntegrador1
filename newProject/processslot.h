#ifndef PROCESSSLOT_H
#define PROCESSSLOT_H

#include "process.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>


class ProcessSlot: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
   explicit ProcessSlot(QObject* parent=0);
    Process* process;

};

#endif // PROCESSSLOT_H
