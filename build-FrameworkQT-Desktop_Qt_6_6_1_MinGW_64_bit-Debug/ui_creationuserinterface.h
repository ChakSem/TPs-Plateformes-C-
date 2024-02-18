/********************************************************************************
** Form generated from reading UI file 'creationuserinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONUSERINTERFACE_H
#define UI_CREATIONUSERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creationUserInterface
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QLabel *labelConnection;
    QLabel *labelMdp;
    QLineEdit *passwordLogin;
    QLabel *labelId;
    QLineEdit *idLogin;
    QPushButton *pushButton;

    void setupUi(QWidget *creationUserInterface)
    {
        if (creationUserInterface->objectName().isEmpty())
            creationUserInterface->setObjectName("creationUserInterface");
        creationUserInterface->resize(800, 500);
        verticalLayout = new QVBoxLayout(creationUserInterface);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        radioButton = new QRadioButton(creationUserInterface);
        radioButton->setObjectName("radioButton");

        gridLayout->addWidget(radioButton, 3, 1, 1, 1);

        labelConnection = new QLabel(creationUserInterface);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);

        gridLayout->addWidget(labelConnection, 0, 1, 1, 1, Qt::AlignHCenter);

        labelMdp = new QLabel(creationUserInterface);
        labelMdp->setObjectName("labelMdp");

        gridLayout->addWidget(labelMdp, 2, 0, 1, 1);

        passwordLogin = new QLineEdit(creationUserInterface);
        passwordLogin->setObjectName("passwordLogin");

        gridLayout->addWidget(passwordLogin, 2, 1, 1, 1);

        labelId = new QLabel(creationUserInterface);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 1, 0, 1, 1);

        idLogin = new QLineEdit(creationUserInterface);
        idLogin->setObjectName("idLogin");
        idLogin->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout->addWidget(idLogin, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(creationUserInterface);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(creationUserInterface);

        QMetaObject::connectSlotsByName(creationUserInterface);
    } // setupUi

    void retranslateUi(QWidget *creationUserInterface)
    {
        creationUserInterface->setWindowTitle(QCoreApplication::translate("creationUserInterface", "Form", nullptr));
        radioButton->setText(QCoreApplication::translate("creationUserInterface", "Admin", nullptr));
        labelConnection->setText(QCoreApplication::translate("creationUserInterface", "Creation d'un compte", nullptr));
        labelMdp->setText(QCoreApplication::translate("creationUserInterface", "Mot de Passe :", nullptr));
        labelId->setText(QCoreApplication::translate("creationUserInterface", "Nom: ", nullptr));
        pushButton->setText(QCoreApplication::translate("creationUserInterface", "Cr\303\251er", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creationUserInterface: public Ui_creationUserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONUSERINTERFACE_H
