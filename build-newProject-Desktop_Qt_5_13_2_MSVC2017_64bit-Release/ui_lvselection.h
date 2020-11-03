/********************************************************************************
** Form generated from reading UI file 'lvselection.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LVSELECTION_H
#define UI_LVSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LvSelection
{
public:
    QPushButton *pushButton_Lv1;
    QPushButton *pushButton_Lv2;
    QPushButton *pushButton_Lv3;
    QPushButton *pushButton_Lv4;
    QPushButton *pushButton_Lv5;
    QPushButton *pushButton_Lv6;
    QPushButton *pushButton_Lv7;
    QPushButton *pushButton_Lv9;
    QPushButton *pushButton_Lv8;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *LvSelection)
    {
        if (LvSelection->objectName().isEmpty())
            LvSelection->setObjectName(QString::fromUtf8("LvSelection"));
        LvSelection->resize(600, 400);
        pushButton_Lv1 = new QPushButton(LvSelection);
        pushButton_Lv1->setObjectName(QString::fromUtf8("pushButton_Lv1"));
        pushButton_Lv1->setGeometry(QRect(190, 60, 71, 71));
        pushButton_Lv2 = new QPushButton(LvSelection);
        pushButton_Lv2->setObjectName(QString::fromUtf8("pushButton_Lv2"));
        pushButton_Lv2->setGeometry(QRect(270, 60, 71, 71));
        pushButton_Lv3 = new QPushButton(LvSelection);
        pushButton_Lv3->setObjectName(QString::fromUtf8("pushButton_Lv3"));
        pushButton_Lv3->setGeometry(QRect(350, 60, 71, 71));
        pushButton_Lv4 = new QPushButton(LvSelection);
        pushButton_Lv4->setObjectName(QString::fromUtf8("pushButton_Lv4"));
        pushButton_Lv4->setGeometry(QRect(190, 140, 71, 71));
        pushButton_Lv5 = new QPushButton(LvSelection);
        pushButton_Lv5->setObjectName(QString::fromUtf8("pushButton_Lv5"));
        pushButton_Lv5->setGeometry(QRect(270, 140, 71, 71));
        pushButton_Lv6 = new QPushButton(LvSelection);
        pushButton_Lv6->setObjectName(QString::fromUtf8("pushButton_Lv6"));
        pushButton_Lv6->setGeometry(QRect(350, 140, 71, 71));
        pushButton_Lv7 = new QPushButton(LvSelection);
        pushButton_Lv7->setObjectName(QString::fromUtf8("pushButton_Lv7"));
        pushButton_Lv7->setGeometry(QRect(190, 220, 71, 71));
        pushButton_Lv9 = new QPushButton(LvSelection);
        pushButton_Lv9->setObjectName(QString::fromUtf8("pushButton_Lv9"));
        pushButton_Lv9->setGeometry(QRect(350, 220, 71, 71));
        pushButton_Lv8 = new QPushButton(LvSelection);
        pushButton_Lv8->setObjectName(QString::fromUtf8("pushButton_Lv8"));
        pushButton_Lv8->setGeometry(QRect(270, 220, 71, 71));
        label = new QLabel(LvSelection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 20, 91, 16));
        pushButton = new QPushButton(LvSelection);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 340, 80, 21));

        retranslateUi(LvSelection);

        QMetaObject::connectSlotsByName(LvSelection);
    } // setupUi

    void retranslateUi(QDialog *LvSelection)
    {
        LvSelection->setWindowTitle(QCoreApplication::translate("LvSelection", "Dialog", nullptr));
        pushButton_Lv1->setText(QCoreApplication::translate("LvSelection", "Lv1", nullptr));
        pushButton_Lv2->setText(QCoreApplication::translate("LvSelection", "Lv2", nullptr));
        pushButton_Lv3->setText(QCoreApplication::translate("LvSelection", "Lv3", nullptr));
        pushButton_Lv4->setText(QCoreApplication::translate("LvSelection", "Lv4", nullptr));
        pushButton_Lv5->setText(QCoreApplication::translate("LvSelection", "Lv5", nullptr));
        pushButton_Lv6->setText(QCoreApplication::translate("LvSelection", "Lv6", nullptr));
        pushButton_Lv7->setText(QCoreApplication::translate("LvSelection", "Lv7", nullptr));
        pushButton_Lv9->setText(QCoreApplication::translate("LvSelection", "Lv9", nullptr));
        pushButton_Lv8->setText(QCoreApplication::translate("LvSelection", "Lv8", nullptr));
        label->setText(QCoreApplication::translate("LvSelection", "Stage Selection", nullptr));
        pushButton->setText(QCoreApplication::translate("LvSelection", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LvSelection: public Ui_LvSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LVSELECTION_H
