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
    QPushButton *databaseButton;
    QPushButton *usersButton;
    QPushButton *accountButton;
    QPushButton *profileButton;

    void setupUi(QWidget *HomeButtons)
    {
        if (HomeButtons->objectName().isEmpty())
            HomeButtons->setObjectName("HomeButtons");
        HomeButtons->resize(276, 89);
        gridLayoutWidget = new QWidget(HomeButtons);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 0, 261, 116));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        databaseButton = new QPushButton(gridLayoutWidget);
        databaseButton->setObjectName("databaseButton");

        gridLayout->addWidget(databaseButton, 4, 0, 1, 1);

        usersButton = new QPushButton(gridLayoutWidget);
        usersButton->setObjectName("usersButton");

        gridLayout->addWidget(usersButton, 3, 0, 1, 1);

        accountButton = new QPushButton(gridLayoutWidget);
        accountButton->setObjectName("accountButton");

        gridLayout->addWidget(accountButton, 2, 0, 1, 1);

        profileButton = new QPushButton(gridLayoutWidget);
        profileButton->setObjectName("profileButton");

        gridLayout->addWidget(profileButton, 1, 0, 1, 1);


        retranslateUi(HomeButtons);

        QMetaObject::connectSlotsByName(HomeButtons);
    } // setupUi

    void retranslateUi(QWidget *HomeButtons)
    {
        HomeButtons->setWindowTitle(QCoreApplication::translate("HomeButtons", "Form", nullptr));
        databaseButton->setText(QCoreApplication::translate("HomeButtons", "BDDs", nullptr));
        usersButton->setText(QCoreApplication::translate("HomeButtons", "Utilisateurs", nullptr));
        accountButton->setText(QCoreApplication::translate("HomeButtons", "Mon Compte", nullptr));
        profileButton->setText(QCoreApplication::translate("HomeButtons", "Profils", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeButtons: public Ui_HomeButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEBUTTONS_H
