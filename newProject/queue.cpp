#include "queue.h"

Queue::Queue(QObject *parent) : QObject(parent)
{

}

QRectF Queue::boundingPolygon() const
{
    QRectF boundingR = QRectF(-30,-60,60,120);
    return boundingR;
}

void Queue::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingPolygon());
    painter->fillRect(boundingPolygon(), Qt::blue);
}
