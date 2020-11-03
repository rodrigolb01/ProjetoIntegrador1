#ifndef INTERRUPTPROCESS_H
#define INTERRUPTPROCESS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsTextItem>
#include <QFont>


class InterruptProcess : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    InterruptProcess(QObject* parent);
    QGraphicsTextItem* txt;
};

#endif // INTERRUPTPROCESS_H
