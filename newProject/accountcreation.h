#ifndef ACCOUNTCREATION_H
#define ACCOUNTCREATION_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlDriver>

namespace Ui {
class AccountCreation;
}

class AccountCreation : public QDialog
{
    Q_OBJECT

public:
    explicit AccountCreation(QWidget *parent = nullptr);
    ~AccountCreation();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::AccountCreation *ui;
signals:
    void closeAccountCreation();
};

#endif // ACCOUNTCREATION_H
