#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class PauseButton: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit PauseButton(QObject* parent=0);
    QGraphicsTextItem* txt;
    QGraphicsTextItem* paused;

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void stop_start_allTimers();
    bool stopped = false;
};

#endif // PAUSEBUTTON_H
