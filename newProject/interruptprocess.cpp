#include "interruptprocess.h"

InterruptProcess::InterruptProcess(QObject* parent)
{
    Q_UNUSED(parent)
    setRect(QRectF(0,0,100,100));
    setPen(Qt::PenStyle::DashLine);
    setBrush(Qt::red);
    setOpacity(0.5);

    txt = new QGraphicsTextItem(this);
    txt->setPlainText("Interrupt");
    txt->setFont(QFont("times",10));
    txt->setDefaultTextColor(Qt::red);
    txt->setPos(x()+15,y()+35);
}
