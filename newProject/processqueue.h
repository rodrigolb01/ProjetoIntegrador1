#ifndef PROCESSQUEUE_H
#define PROCESSQUEUE_H


#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include "process.h"
#include "node.h"


class ProcessQueue: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
   explicit ProcessQueue(QObject* parent=0);

    int Add(Process* p);
    Process* Remov(Process* pro);
    int Size();
    int IsEmpty();

    int d;//distance between processes
    Process *processAt(int pos);


    QGraphicsRectItem* bounding_rect;
    QGraphicsTextItem* label;
    Node* front;
    Node* back;
    int size;

    void remove_process();

signals:
    void populate_queue();
};

#endif // PROCESSQUEUE_H
