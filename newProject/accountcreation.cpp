#include "accountcreation.h"
#include "ui_accountcreation.h"

AccountCreation::AccountCreation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountCreation)
{
    ui->setupUi(this);
}

AccountCreation::~AccountCreation()
{
    delete ui;
}

void AccountCreation::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_username->text() != "" && ui->lineEdit_password->text() != "" && ui->lineEdit_confirmpassword->text() != "")//if fields are not null
    {
        if(ui->lineEdit_password->text() == ui->lineEdit_confirmpassword->text())//if password is right
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
                QMessageBox::information(this, "connection", "connection sucessful!");
                QSqlQuery q(db);
                q.prepare(QString("INSERT INTO users(login,password,played_survival,played_campaign, Lv1_Clear, Lv2_Clear, Lv3_Clear, Lv4_Clear, Lv5_Clear, Lv6_Clear, Lv7_Clear, "
                                  "Lv8_Clear, Lv9_Clear, email) VALUES('%1','%2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '%3');"
                                  "INSERT INTO max_score(username, maxScore_Lv1,  maxScore_Lv2, maxScore_Lv3, maxScore_Lv4, maxScore_Lv5, maxScore_Lv6, maxScore_Lv7, maxScore_Lv8,"
                                  " maxScore_Lv9, maxScore_survival) VALUES('%1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);"
                                  "INSERT INTO losed(username, loseLv1, loseLv2, loseLv3, loseLv4, loseLv5, loseLv6, loseLv7, loseLv8, loseLv9) VALUES('%1', 0, 0, 0, 0, 0, 0, 0, 0, 0);"
                                  "insert into stats(sample_Mean, median, variance, standard_Deviation, Confidence_Interval, username, proportion) VALUES(0,0,0,0,'0%','%1','0%')")
                          .arg(ui->lineEdit_username->text(), ui->lineEdit_password->text(), ui->lineEdit_email->text()));
                if(q.exec())
                {
                    QMessageBox info;
                    info.setText("registration successful!");
                    db.commit();
                    db.close();
                    info.exec();
                    if(info.close())
                        emit closeAccountCreation();
                }
                else
                {
                    QMessageBox warning;
                    warning.setText("registration failed!");
                    warning.exec();
                }
            }
        }
        else
        {
            QMessageBox warning;
            warning.setText("passwords differ from each other!");
            warning.exec();
        }
    }
}

void AccountCreation::on_pushButton_back_clicked()
{
    emit closeAccountCreation();
}
