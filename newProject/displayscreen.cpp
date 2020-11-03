#include "displayscreen.h"
#include <QDebug>

displayScreen::displayScreen(QObject* parent)
{
    Q_UNUSED(parent)
    setRect(QRectF(0,0,380,300));
    setBrush(Qt::black);

    infoString = QString("Logs\n");

    info_logs = new QGraphicsTextItem(this);
    info_logs->setPlainText(infoString);
    info_logs->setFont(QFont("times",12));
    info_logs->setDefaultTextColor(Qt::green);
}

void displayScreen::notify_process_interrupted(int process_id)
{
    //remove first line
    if(infoString.count("\n")>=15)
    {
        QString temp;
        int i=0;
        while(infoString[i]!="\n")
            i++;
        for(i=i+1; i<infoString.length(); i++)
        {
            temp.append(infoString[i]);
        }
        infoString = temp;
    }

    infoString.append(QString("process %1 was interrupted\n").arg(process_id));
    info_logs->setPlainText(infoString);
}

void displayScreen::notify_process_execution(int process_id)
{
    //remove first line
    if(infoString.count("\n")>=13)
    {
        QString temp;
        int i=0;
        while(infoString[i]!="\n")
            i++;
        for(i=i+1; i<infoString.length(); i++)
        {
            temp.append(infoString[i]);
        }
        infoString = temp;
    }

    infoString.append(QString("process %1 is running\n").arg(process_id));
    info_logs->setPlainText(infoString);
}

void displayScreen::notify_process_needs_io(int process_id, int io)
{
    //remove first line
    if(infoString.count("\n")>=13)
    {
        QString temp;
        int i=0;
        while(infoString[i]!="\n")
            i++;
        for(i=i+1; i<infoString.length(); i++)
        {
            temp.append(infoString[i]);
        }
        infoString = temp;
    }

    switch (io) {
    case 1: infoString.append(QString("process %1 needs keyboard input\n").arg(process_id)); break;
    case 2: infoString.append(QString("process %1 needs data from memory\n").arg(process_id)); break;
    case 3: infoString.append(QString("process %1 needs output from monitor\n").arg(process_id)); break;
    case 4: infoString.append(QString("process %1 needs transfer data to pendrive\n").arg(process_id)); break;
    }
    info_logs->setPlainText(infoString);
}

void displayScreen::notify_io_ready(int process_id)
{
    qInfo() << "\nmonitor notified!";
    //remove first line
    if(infoString.count("\n")>=13)
    {
        QString temp;
        int i=0;
        while(infoString[i]!="\n")
            i++;
        for(i=i+1; i<infoString.length(); i++)
        {
            temp.append(infoString[i]);
        }
        infoString = temp;
    }

    infoString.append(QString("process %1 is ready to run!\n").arg(process_id));
    info_logs->setPlainText(infoString);
}
