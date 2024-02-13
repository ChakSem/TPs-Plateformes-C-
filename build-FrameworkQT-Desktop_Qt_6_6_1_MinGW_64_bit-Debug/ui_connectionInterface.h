/********************************************************************************
** Form generated from reading UI file 'connectionInterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONINTERFACE_H
#define UI_CONNECTIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *passwordLogin;
    QLabel *labelMdp;
    QLineEdit *idLogin;
    QLabel *labelId;
    QPushButton *pushButton;
    QLabel *labelConnection;

    void setupUi(QWidget *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName("Connection");
        Connection->resize(400, 300);
        gridLayoutWidget = new QWidget(Connection);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(110, 100, 181, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordLogin = new QLineEdit(gridLayoutWidget);
        passwordLogin->setObjectName("passwordLogin");

        gridLayout->addWidget(passwordLogin, 3, 1, 1, 1);

        labelMdp = new QLabel(gridLayoutWidget);
        labelMdp->setObjectName("labelMdp");

        gridLayout->addWidget(labelMdp, 3, 0, 1, 1);

        idLogin = new QLineEdit(gridLayoutWidget);
        idLogin->setObjectName("idLogin");
        idLogin->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout->addWidget(idLogin, 2, 1, 1, 1);

        labelId = new QLabel(gridLayoutWidget);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 2, 0, 1, 1);

        pushButton = new QPushButton(Connection);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 210, 80, 24));
        labelConnection = new QLabel(Connection);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(150, 70, 121, 19));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QWidget *Connection)
    {
        Connection->setWindowTitle(QCoreApplication::translate("Connection", "Form", nullptr));
        labelMdp->setText(QCoreApplication::translate("Connection", "Mot de Passe :", nullptr));
        labelId->setText(QCoreApplication::translate("Connection", "Identifiant :", nullptr));
        pushButton->setText(QCoreApplication::translate("Connection", "Connexion", nullptr));
        labelConnection->setText(QCoreApplication::translate("Connection", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONINTERFACE_H
