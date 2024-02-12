/********************************************************************************
** Form generated from reading UI file 'indexhomeadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXHOMEADMIN_H
#define UI_INDEXHOMEADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexHomeAdmin
{
public:
    QLabel *labelConnection;
    QPushButton *pushButton_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;

    void setupUi(QDialog *indexHomeAdmin)
    {
        if (indexHomeAdmin->objectName().isEmpty())
            indexHomeAdmin->setObjectName("indexHomeAdmin");
        indexHomeAdmin->resize(400, 300);
        labelConnection = new QLabel(indexHomeAdmin);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(160, 50, 81, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);
        pushButton_4 = new QPushButton(indexHomeAdmin);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(310, 20, 80, 18));
        gridLayoutWidget = new QWidget(indexHomeAdmin);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 110, 261, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);


        retranslateUi(indexHomeAdmin);

        QMetaObject::connectSlotsByName(indexHomeAdmin);
    } // setupUi

    void retranslateUi(QDialog *indexHomeAdmin)
    {
        indexHomeAdmin->setWindowTitle(QCoreApplication::translate("indexHomeAdmin", "Dialog", nullptr));
        labelConnection->setText(QCoreApplication::translate("indexHomeAdmin", "PROJET QT", nullptr));
        pushButton_4->setText(QCoreApplication::translate("indexHomeAdmin", "Deconnection", nullptr));
        pushButton_2->setText(QCoreApplication::translate("indexHomeAdmin", "Mon Compte", nullptr));
        pushButton->setText(QCoreApplication::translate("indexHomeAdmin", "Profils", nullptr));
        pushButton_5->setText(QCoreApplication::translate("indexHomeAdmin", "Utilisateurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexHomeAdmin: public Ui_indexHomeAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXHOMEADMIN_H
