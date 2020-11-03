#ifndef QUEUE_H
#define QUEUE_H

#include <QObject>
#include <QRectF>
#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QTimer>
#include "proccess.h"


class Queue : public QObject , public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Queue(QObject *parent = nullptr);
     Proccess* queue[2];
     QRectF boundingPolygon() const ;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

signals:

};

#endif // QUEUE_H
