#include "finishprocess.h"

FinishProcess::FinishProcess(QObject* parent)
{
    Q_UNUSED(parent)
    setRect(QRectF(0,0,100,100));
    setPen(Qt::PenStyle::DashLine);
    setBrush(Qt::green);
    setOpacity(0.5);

    txt = new QGraphicsTextItem(this);
    txt->setPlainText("Finish");
    txt->setFont(QFont("times",10));
    txt->setDefaultTextColor(Qt::black);
    txt->setPos(x()+15,y()+35);
}
