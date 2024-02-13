/********************************************************************************
** Form generated from reading UI file 'homebuttons.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEBUTTONS_H
#define UI_HOMEBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeButtons
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *HomeButtons)
    {
        if (HomeButtons->objectName().isEmpty())
            HomeButtons->setObjectName("HomeButtons");
        HomeButtons->resize(276, 90);
        gridLayoutWidget = new QWidget(HomeButtons);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 0, 261, 86));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(HomeButtons);

        QMetaObject::connectSlotsByName(HomeButtons);
    } // setupUi

    void retranslateUi(QWidget *HomeButtons)
    {
        HomeButtons->setWindowTitle(QCoreApplication::translate("HomeButtons", "Form", nullptr));
        pushButton_6->setText(QCoreApplication::translate("HomeButtons", "BDDs", nullptr));
        pushButton_5->setText(QCoreApplication::translate("HomeButtons", "Utilisateurs", nullptr));
        pushButton_2->setText(QCoreApplication::translate("HomeButtons", "Mon Compte", nullptr));
        pushButton->setText(QCoreApplication::translate("HomeButtons", "Profils", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeButtons: public Ui_HomeButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEBUTTONS_H
