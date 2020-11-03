#include "processicon.h"

extern Game * game;

ProcessIcon::ProcessIcon(QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,100,100);
    setBrush(Qt::green);
}

void ProcessIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //when player clicks the process icon, creates a process
    if (game->dragging == false){
        game->dragging = true;

        //change cursor when dragging it
        game->setCursor();
    }
}
