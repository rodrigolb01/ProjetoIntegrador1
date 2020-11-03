#ifndef NODE_H
#define NODE_H

#include "process.h"

class Node: public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject* parent=0);
    Process* process;
    Node* next;
};

#endif // NODE_H
