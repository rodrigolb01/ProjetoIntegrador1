/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_campaign;
    QPushButton *pushButton_survival;
    QPushButton *pushButton;
    QPushButton *pushButton_logout;
    QLabel *label_7;

    void setupUi(QDialog *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->resize(400, 300);
        layoutWidget = new QWidget(mainMenu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 10, 258, 286));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_campaign = new QPushButton(layoutWidget);
        pushButton_campaign->setObjectName(QString::fromUtf8("pushButton_campaign"));

        verticalLayout_2->addWidget(pushButton_campaign);

        pushButton_survival = new QPushButton(layoutWidget);
        pushButton_survival->setObjectName(QString::fromUtf8("pushButton_survival"));

        verticalLayout_2->addWidget(pushButton_survival);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_logout = new QPushButton(layoutWidget);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));

        verticalLayout_2->addWidget(pushButton_logout);


        verticalLayout_3->addLayout(verticalLayout_2);

        label_7 = new QLabel(mainMenu);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 0, 47, 13));

        retranslateUi(mainMenu);

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QDialog *mainMenu)
    {
        mainMenu->setWindowTitle(QCoreApplication::translate("mainMenu", "Dialog", nullptr));
        pushButton_campaign->setText(QCoreApplication::translate("mainMenu", "Campaign", nullptr));
        pushButton_survival->setText(QCoreApplication::translate("mainMenu", "Survival", nullptr));
        pushButton->setText(QCoreApplication::translate("mainMenu", "Stats", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("mainMenu", "log out", nullptr));
        label_7->setText(QCoreApplication::translate("mainMenu", "MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
