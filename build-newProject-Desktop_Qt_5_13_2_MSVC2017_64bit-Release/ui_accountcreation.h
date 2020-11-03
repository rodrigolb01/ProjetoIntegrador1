/********************************************************************************
** Form generated from reading UI file 'accountcreation.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTCREATION_H
#define UI_ACCOUNTCREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccountCreation
{
public:
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_confirmpassword;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_back;
    QLineEdit *lineEdit_email;
    QLabel *label_5;

    void setupUi(QDialog *AccountCreation)
    {
        if (AccountCreation->objectName().isEmpty())
            AccountCreation->setObjectName(QString::fromUtf8("AccountCreation"));
        AccountCreation->resize(400, 300);
        pushButton_ok = new QPushButton(AccountCreation);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(210, 220, 80, 21));
        lineEdit_username = new QLineEdit(AccountCreation);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(150, 120, 113, 21));
        lineEdit_password = new QLineEdit(AccountCreation);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(150, 150, 113, 21));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_confirmpassword = new QLineEdit(AccountCreation);
        lineEdit_confirmpassword->setObjectName(QString::fromUtf8("lineEdit_confirmpassword"));
        lineEdit_confirmpassword->setGeometry(QRect(150, 180, 113, 21));
        lineEdit_confirmpassword->setEchoMode(QLineEdit::Password);
        label = new QLabel(AccountCreation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 120, 61, 16));
        label_2 = new QLabel(AccountCreation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 150, 51, 20));
        label_3 = new QLabel(AccountCreation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 180, 91, 20));
        label_4 = new QLabel(AccountCreation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 60, 91, 16));
        pushButton_back = new QPushButton(AccountCreation);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(120, 220, 80, 21));
        lineEdit_email = new QLineEdit(AccountCreation);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(150, 90, 113, 21));
        label_5 = new QLabel(AccountCreation);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 90, 47, 13));

        retranslateUi(AccountCreation);

        QMetaObject::connectSlotsByName(AccountCreation);
    } // setupUi

    void retranslateUi(QDialog *AccountCreation)
    {
        AccountCreation->setWindowTitle(QCoreApplication::translate("AccountCreation", "Dialog", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("AccountCreation", "Ok", nullptr));
        label->setText(QCoreApplication::translate("AccountCreation", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("AccountCreation", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("AccountCreation", "Confirm Password:", nullptr));
        label_4->setText(QCoreApplication::translate("AccountCreation", "New Account", nullptr));
        pushButton_back->setText(QCoreApplication::translate("AccountCreation", "back", nullptr));
        label_5->setText(QCoreApplication::translate("AccountCreation", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountCreation: public Ui_AccountCreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTCREATION_H
