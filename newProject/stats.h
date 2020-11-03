#ifndef STATS_H
#define STATS_H

#include <cmath>
#include <iostream>

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlDriver>

namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    ~Stats();
    void setData(QString username);
    float standard_deviation(int size, QList<float> values);
    float variance(int size, QList<float> values);
    float calc_median(int size, QList<float> values);
    float sample_mean(int size, QList<float> values);


    bool Lv1Clear=false;
    bool Lv2Clear=false;
    bool Lv3Clear=false;
    bool Lv4Clear=false;
    bool Lv5Clear=false;
    bool Lv6Clear=false;
    bool Lv7Clear=false;
    bool Lv8Clear=false;
    bool Lv9Clear=false;

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Stats *ui;
signals:
    void closeStatsWindow();
};

#endif // STATS_H
