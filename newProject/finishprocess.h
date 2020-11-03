#ifndef FINISHPROCESS_H
#define FINISHPROCESS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsTextItem>
#include <QFont>


class FinishProcess : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    FinishProcess(QObject* parent);
    QGraphicsTextItem* txt;
};

#endif // FINISHPROCESS_H
