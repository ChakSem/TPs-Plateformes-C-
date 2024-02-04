/********************************************************************************
** Form generated from reading UI file 'mainconnection.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONNECTION_H
#define UI_MAINCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainConnection
{
public:
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *passwordLogin;
    QLabel *labelMdp;
    QLabel *labelId;
    QLineEdit *idLogin;
    QLabel *labelConnection;

    void setupUi(QDialog *MainConnection)
    {
        if (MainConnection->objectName().isEmpty())
            MainConnection->setObjectName("MainConnection");
        MainConnection->resize(400, 300);
        pushButton = new QPushButton(MainConnection);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 180, 80, 24));
        gridLayoutWidget = new QWidget(MainConnection);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(130, 102, 138, 66));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordLogin = new QLineEdit(gridLayoutWidget);
        passwordLogin->setObjectName("passwordLogin");

        gridLayout->addWidget(passwordLogin, 3, 1, 1, 1);

        labelMdp = new QLabel(gridLayoutWidget);
        labelMdp->setObjectName("labelMdp");

        gridLayout->addWidget(labelMdp, 3, 0, 1, 1);

        labelId = new QLabel(gridLayoutWidget);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 2, 0, 1, 1);

        idLogin = new QLineEdit(gridLayoutWidget);
        idLogin->setObjectName("idLogin");
        idLogin->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout->addWidget(idLogin, 2, 1, 1, 1);

        labelConnection = new QLabel(MainConnection);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(160, 80, 71, 19));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);

        retranslateUi(MainConnection);

        QMetaObject::connectSlotsByName(MainConnection);
    } // setupUi

    void retranslateUi(QDialog *MainConnection)
    {
        MainConnection->setWindowTitle(QCoreApplication::translate("MainConnection", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("MainConnection", "Connexion", nullptr));
        labelMdp->setText(QCoreApplication::translate("MainConnection", "Mot de Passe :", nullptr));
        labelId->setText(QCoreApplication::translate("MainConnection", "Identifiant :", nullptr));
        labelConnection->setText(QCoreApplication::translate("MainConnection", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainConnection: public Ui_MainConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONNECTION_H
