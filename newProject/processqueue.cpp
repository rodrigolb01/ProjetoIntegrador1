#include "processqueue.h"
#include "QDebug"
#include "game.h"

extern Game* game;

ProcessQueue::ProcessQueue(QObject* parent)
{
    Q_UNUSED(parent)
    front = back = NULL;
    size=0;
    d=0;

    bounding_rect = new QGraphicsRectItem(this);
    bounding_rect->setRect(QRectF(0,0,1200,100));
    bounding_rect->setPos(pos());
    bounding_rect->setPen(Qt::PenStyle::DashLine);

    label = new QGraphicsTextItem(this);
    label->setPos(x(),y()-50);
}

int ProcessQueue::Add(Process* p)
{
    //insert in the back of the queue
    Node* n = new Node(this);
    if(n)
    {
        n->process = p;
        n->next = NULL;

        if(front==NULL)
        {
            front = n;
        }
        else
        {
            back->next = n;
        }

        back = n;
        size++;

        //set position
        if(size ==0)
        {
            p->setPos(QPointF(x()+10,y()+5));
        }
        else
        {
            d=0;
            for(int i=0; i<size; i++)
            {
                d +=95;
            }
            p->setPos(QPointF(d,y()+5));
            d=0;
        }
        return 1;
    }
    return 0;
}

Process* ProcessQueue::Remov(Process* pro)
{
    //remove process from a position of the list
    if(!IsEmpty())
    {
        Node* i = front;
        Node* prev;
        Node* next;

        while(i != NULL && i->process != pro)
        {
            prev = i;
            if(i->next)
            {
                i = i->next;
                next = i->next;
            }
            else
                next = NULL;
        }
        Process* p = new Process(i->process->parent(), i->process->priority, i->process->ID);
        //move all processes after it

        Node* n;
        for(n=i; n!=NULL; n=n->next)
        {
            n->process->setPos(QPointF(n->process->x()-95, n->process->y()));
        }

        if(i != NULL)
        {
            if(i != front)
                prev->next = i ->next;
            else
                front = i->next;

            if(i == back)
                back = prev;
            size--;
            if(size < 12 && game->totalProcesses>0)
                emit populate_queue();
        }
        return p;
        return NULL;
    }
    return NULL;
}

Process *ProcessQueue::processAt(int i)
{
    Node* n;
    int count=0;
    for(n=front; n!= NULL; n=n->next, count++)
        if(count == i)
            return n->process;
    return NULL;
}



int ProcessQueue::Size()
{
    return  size;
}

int ProcessQueue::IsEmpty()
{
    return size==0;
}


void ProcessQueue::remove_process()
{
    qInfo() << "process was removed from the queue";

    Node* n;//find the process that sent the signal and remove it
    for(n=front; n!= NULL; n=n->next)
    {
        if(n->process == sender())
        {
            Process* removed = Remov(n->process);
        }
    }
    qInfo() << "queue:" << Size();
}





