#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlDriver>

#include "mainmenu.h"
#include "accountcreation.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_clicked();
public slots:
    void closeMenu();
    void closeAccountCreation();
signals:
    void logged_player(QString username);

private:
    Ui::LoginScreen *ui;
    AccountCreation* c;
    mainMenu* m;
};

#endif // LOGINSCREEN_H
