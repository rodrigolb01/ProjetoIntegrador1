#ifndef PROCCESS_H
#define PROCCESS_H

#include <QObject>
#include <QRectF>
#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QTimer>
#include <QQueue>


class Proccess: public QObject
{
    Q_OBJECT
public:
    explicit Proccess(QObject* parent = nullptr);

private:

    QTimer* wait_time;
    QTimer* request_data;
    int actions_remaining;
    int priority;
    void requestData();

signals:


};

#endif // PROCCESS_H
