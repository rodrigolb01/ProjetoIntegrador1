#include "stats.h"
#include "ui_stats.h"
#include "QDebug"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
}

Stats::~Stats()
{
    delete ui;
}

void Stats::on_pushButton_back_clicked()
{
    emit closeStatsWindow();
}

void Stats::setData(QString username)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","conn");
    db.setHostName("localhost");
    db.setDatabaseName("ProjetoIntegrador");
    db.setUserName("root");
    db.setPassword("M4a10121");
    bool ok = db.open();

    if(!ok)
    {
        QMessageBox::warning(this, "connection", "can not open connection!");
    }
    else
    {
        QSqlQuery q(db);
        q.prepare(QString("SELECT * FROM users WHERE login = '%1'").arg(username));
        if(q.exec())
        {
            while(q.next())
            {
                Lv1Clear = q.value(4).toBool();
                Lv2Clear = q.value(5).toBool();
                Lv3Clear = q.value(6).toBool();
                Lv4Clear = q.value(7).toBool();
                Lv5Clear = q.value(8).toBool();
                Lv6Clear = q.value(9).toBool();
                Lv7Clear = q.value(10).toBool();
                Lv8Clear = q.value(11).toBool();
                Lv9Clear = q.value(12).toBool();
            }
        }
        else
        {
            QMessageBox::warning(this,"setting bools","query failed!");
        }

        q.prepare(QString("SELECT login, played_survival, played_campaign, email FROM users WHERE login = '%1'").arg(username));

        if(q.exec())
        {
            while(q.next())
            {
                ui->label_username->setText(q.value(0).toString());
                ui->played_survival->setText(q.value(1).toString());
                ui->played_campaign->setText(q.value(2).toString());
                ui->label_email->setText(q.value(3).toString());
            }
        }
        else
        {
            QMessageBox::warning(this,"basic userData","query failed!");
        }

        q.prepare(QString("SELECT * from max_score WHERE username = '%1';").arg(username));
        if(q.exec())
        {
            while(q.next())
            {
                ui->label_maxSc->setText(q.value(1).toString());
                ui->label_maxSc_2->setText(q.value(2).toString());
                ui->label_maxSc_3->setText(q.value(3).toString());
                ui->label_maxSc_4->setText(q.value(4).toString());
                ui->label_maxSc_5->setText(q.value(5).toString());
                ui->label_maxSc_6->setText(q.value(6).toString());
                ui->label_maxSc_7->setText(q.value(7).toString());
                ui->label_maxSc_8->setText(q.value(8).toString());
                ui->label_maxSc_9->setText(q.value(9).toString());
                ui->label_maxSc_10->setText(q.value(10).toString());
            }
        }
        else
        {
            QMessageBox::warning(this,"maxScore","query failed!");
        }
        q.prepare(QString("SELECT * from losed WHERE username = '%1'").arg(username));
        if(q.exec())
        {
            while(q.next())
            {
                ui->label_lose_lv->setText(q.value(1).toString());
                ui->label_lose_lv_2->setText(q.value(2).toString());
                ui->label_lose_lv_3->setText(q.value(3).toString());
                ui->label_lose_lv_4->setText(q.value(4).toString());
                ui->label_lose_lv_5->setText(q.value(5).toString());
                ui->label_lose_lv_6->setText(q.value(6).toString());
                ui->label_lose_lv_7->setText(q.value(7).toString());
                ui->label_lose_lv_8->setText(q.value(8).toString());
                ui->label_lose_lv_9->setText(q.value(9).toString());
            }
        }
        else
        {
            QMessageBox::warning(this,"losed","query failed!");
        }
        q.prepare(QString("SELECT * FROM max_score WHERE username = '%1'").arg(username));
        if(q.exec())
        {
            QList<float> scores;
            int size=0;
            while(q.next())
            {
                if(Lv1Clear)
                {
                    scores << q.value(1).toFloat();
                    qInfo() << q.value(1).toFloat();
                    size++;
                }
                if(Lv2Clear)
                {
                    scores << q.value(2).toFloat();
                    qInfo() << q.value(2).toFloat();
                    size++;
                }
                if(Lv3Clear)
                {
                    scores << q.value(3).toFloat();
                    qInfo() << q.value(3).toFloat();
                    size++;
                }
                if(Lv4Clear)
                {
                    scores << q.value(4).toFloat();
                    qInfo() << q.value(4).toFloat();
                    size++;
                }
                if(Lv5Clear)
                {
                    scores << q.value(5).toFloat();
                    qInfo() << q.value(5).toFloat();
                    size++;
                }
                if(Lv6Clear)
                {
                    scores << q.value(6).toFloat();
                    qInfo() << q.value(6).toFloat();
                    size++;
                }
                if(Lv7Clear)
                {
                    scores << q.value(7).toFloat();
                    qInfo() << q.value(7).toFloat();
                    size++;
                }
                if(Lv8Clear)
                {
                    scores << q.value(8).toFloat();
                    qInfo() << q.value(8).toFloat();
                    size++;
                }
                if(Lv9Clear)
                {
                    scores << q.value(9).toFloat();
                    qInfo() << q.value(9).toFloat();
                    size++;
                }
            }
            if(size>1)
            {
                float stdDev = standard_deviation(size, scores);
                ui->label_stdDev->setText(QString("%1").arg(stdDev));
                q.prepare(QString("UPDATE stats SET standard_Deviation = '%1' WHERE username = '%2';").arg(stdDev).arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update stdDev","query failed!");
                    qInfo() << q.lastError();
                }
                float var = variance(size,scores);
                ui->label_variance->setText(QString("%1").arg(var));
                q.prepare(QString("UPDATE stats SET variance = '%1' WHERE username = '%2';").arg(var).arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update variance","query failed!");
                    qInfo() << q.lastError();
                }
                float median = calc_median(size, scores);
                ui->label_median->setText(QString("%1").arg(median));
                q.prepare(QString("UPDATE stats SET median = '%1' WHERE username = '%2';").arg(median).arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update median","query failed!");
                    qInfo() << q.lastError();
                }
                float mean = sample_mean(size,scores);
                ui->label_mean->setText(QString("%1").arg(mean));
                q.prepare(QString("UPDATE stats SET sample_Mean = '%1' WHERE username = '%2';").arg(mean).arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update sampleMean","query failed!");
                    qInfo() << q.lastError();
                }

                ui->label_confidence->setText(QString("100%"));
                q.prepare(QString("UPDATE stats SET Confidence_interval = '100%' WHERE username = '%1';").arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update confiabilty","query failed!");
                    qInfo() << q.lastError();
                }
                ui->label_proportion->setText(QString("100%"));
                q.prepare(QString("UPDATE stats SET proportion = '100%' WHERE username = '%1';").arg(username));
                if(q.exec())
                    db.commit();
                else
                {
                    QMessageBox::warning(this,"update proportion","query failed!");
                    qInfo() << q.lastError();
                }
            }

        }
        else
        {
            QMessageBox::warning(this,"stdDev calc","query failed!");
        }

        db.close();
    }
}

float Stats::standard_deviation(int size, QList<float> values)
{
    float sum = 0.0, mean, variance = 0.0, stdDeviation;
    int i;
    for(i=0; i< size; ++i)
        sum += values[i];
    mean = sum/size;
    for(i=0; i< size; ++i)
        variance +=pow(values[i] - mean, 2);
    variance = variance/size;
    stdDeviation = sqrt(variance);
    std::cout << "The data values are: ";
    for(i=0; i<size; ++i)
        std::cout<< values[i] << " ";
    std::cout << std::endl;
    std::cout << "the standard deviation of these values is: " <<stdDeviation << std::endl;
    return stdDeviation;
}

float Stats::variance(int size, QList<float> values)
{
    return pow(standard_deviation(size, values),2);
}

float Stats::calc_median(int size, QList<float> values)
{
    bool odd=false;
    if(size%2)
    {
        odd = true;
    }
    if(odd)
    {
       return(values[(size/2)]);
    }
    else
    {
        return (values[size/2] + values[(size/2)-1])/2;
    }
    return 0;
}

float Stats::sample_mean(int size, QList<float> values)
{
    int sum=0;
    for(int i=0; i<size; i++)
    {
        sum += values[i];
    }
    return sum/size;
}


