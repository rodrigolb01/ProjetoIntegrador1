#ifndef LVSELECTION_H
#define LVSELECTION_H

#include <QDialog>
#include "game.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlDriver>

namespace Ui {
class LvSelection;
}

class LvSelection : public QDialog
{
    Q_OBJECT

public:
    explicit LvSelection(QWidget *parent = nullptr);
    ~LvSelection();
    QString user_logged;
    bool Lv1Clear=false;
    bool Lv2Clear=false;
    bool Lv3Clear=false;
    bool Lv4Clear=false;
    bool Lv5Clear=false;
    bool Lv6Clear=false;
    bool Lv7Clear=false;
    bool Lv8Clear=false;
    bool lv9Clear=false;

    void SetUserData();

public slots:
    void update_userData();

private slots:
    void on_pushButton_Lv1_clicked();
    void on_pushButton_Lv2_clicked();
    void on_pushButton_Lv3_clicked();
    void on_pushButton_Lv4_clicked();
    void on_pushButton_Lv5_clicked();
    void on_pushButton_Lv6_clicked();
    void on_pushButton_Lv7_clicked();
    void on_pushButton_Lv8_clicked();
    void on_pushButton_Lv9_clicked();
    void on_pushButton_clicked();

private:
    Ui::LvSelection *ui;
signals:
    void closeLvSelection();
};

#endif // LVSELECTION_H
