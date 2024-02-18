/********************************************************************************
** Form generated from reading UI file 'myaccountinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYACCOUNTINTERFACE_H
#define UI_MYACCOUNTINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyAccountInterface
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelConnection;
    QGridLayout *gridLayout;
    QLineEdit *passwordLogin_3;
    QLineEdit *passwordLogin;
    QLineEdit *passwordLogin_4;
    QLineEdit *passwordLogin_2;
    QLabel *labelId;
    QLabel *labelId_2;
    QLabel *labelId_3;
    QLabel *labelId_4;

    void setupUi(QWidget *MyAccountInterface)
    {
        if (MyAccountInterface->objectName().isEmpty())
            MyAccountInterface->setObjectName("MyAccountInterface");
        MyAccountInterface->resize(800, 500);
        gridLayout_2 = new QGridLayout(MyAccountInterface);
        gridLayout_2->setObjectName("gridLayout_2");
        labelConnection = new QLabel(MyAccountInterface);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setMaximumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);

        gridLayout_2->addWidget(labelConnection, 0, 0, 1, 1, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        passwordLogin_3 = new QLineEdit(MyAccountInterface);
        passwordLogin_3->setObjectName("passwordLogin_3");

        gridLayout->addWidget(passwordLogin_3, 2, 1, 1, 1);

        passwordLogin = new QLineEdit(MyAccountInterface);
        passwordLogin->setObjectName("passwordLogin");

        gridLayout->addWidget(passwordLogin, 0, 1, 1, 1);

        passwordLogin_4 = new QLineEdit(MyAccountInterface);
        passwordLogin_4->setObjectName("passwordLogin_4");

        gridLayout->addWidget(passwordLogin_4, 3, 1, 1, 1);

        passwordLogin_2 = new QLineEdit(MyAccountInterface);
        passwordLogin_2->setObjectName("passwordLogin_2");

        gridLayout->addWidget(passwordLogin_2, 1, 1, 1, 1);

        labelId = new QLabel(MyAccountInterface);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 0, 0, 1, 1);

        labelId_2 = new QLabel(MyAccountInterface);
        labelId_2->setObjectName("labelId_2");

        gridLayout->addWidget(labelId_2, 1, 0, 1, 1);

        labelId_3 = new QLabel(MyAccountInterface);
        labelId_3->setObjectName("labelId_3");

        gridLayout->addWidget(labelId_3, 2, 0, 1, 1);

        labelId_4 = new QLabel(MyAccountInterface);
        labelId_4->setObjectName("labelId_4");

        gridLayout->addWidget(labelId_4, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(MyAccountInterface);

        QMetaObject::connectSlotsByName(MyAccountInterface);
    } // setupUi

    void retranslateUi(QWidget *MyAccountInterface)
    {
        MyAccountInterface->setWindowTitle(QCoreApplication::translate("MyAccountInterface", "Form", nullptr));
        labelConnection->setText(QCoreApplication::translate("MyAccountInterface", "Mon Compte", nullptr));
        labelId->setText(QCoreApplication::translate("MyAccountInterface", "ID:", nullptr));
        labelId_2->setText(QCoreApplication::translate("MyAccountInterface", "R\303\264le/Statut", nullptr));
        labelId_3->setText(QCoreApplication::translate("MyAccountInterface", "Nom: ", nullptr));
        labelId_4->setText(QCoreApplication::translate("MyAccountInterface", "Mot de passe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyAccountInterface: public Ui_MyAccountInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYACCOUNTINTERFACE_H
