/********************************************************************************
** Form generated from reading UI file 'indexHomeUser.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXHOMEUSER_H
#define UI_INDEXHOMEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *labelConnection;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        labelConnection = new QLabel(Dialog);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(160, 50, 81, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 110, 261, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(310, 20, 80, 18));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        labelConnection->setText(QCoreApplication::translate("Dialog", "PROJET QT", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Profils", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Mon Compte", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "Deconnection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXHOMEUSER_H
