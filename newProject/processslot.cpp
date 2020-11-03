#include "processslot.h"
#include <QDebug>
#include <game.h>
extern Game* game;

ProcessSlot::ProcessSlot(QObject* parent)
{
     Q_UNUSED(parent)
    setRect(0,0,100,100);
    setPen(QPen(Qt::PenStyle::DashLine));
    process = nullptr;
}



