#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QBrush>
#include <QFont>

class displayScreen: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    displayScreen(QObject* parent=0);
    QString infoString;
    QGraphicsTextItem* info_logs;
public slots:
   void notify_process_interrupted(int process_id);
   void notify_process_execution(int process_id);
   void notify_process_needs_io(int process_id, int io);
   void notify_io_ready(int process_id);
};

#endif // DISPLAYSCREEN_H
