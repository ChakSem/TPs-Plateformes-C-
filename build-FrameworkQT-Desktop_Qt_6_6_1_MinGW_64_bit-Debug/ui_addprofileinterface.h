/********************************************************************************
** Form generated from reading UI file 'addprofileinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROFILEINTERFACE_H
#define UI_ADDPROFILEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addProfileInterface
{
public:
    QPushButton *pushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *labelId;
    QLineEdit *idLogin;
    QLabel *labelConnection;
    QLabel *labelConnection_2;
    QLabel *labelConnection_3;

    void setupUi(QWidget *addProfileInterface)
    {
        if (addProfileInterface->objectName().isEmpty())
            addProfileInterface->setObjectName("addProfileInterface");
        addProfileInterface->resize(204, 184);
        pushButton = new QPushButton(addProfileInterface);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 160, 80, 18));
        gridLayoutWidget_2 = new QWidget(addProfileInterface);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 110, 161, 52));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(gridLayoutWidget_2);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout_2->addWidget(radioButton_2, 2, 0, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget_2);
        radioButton->setObjectName("radioButton");

        gridLayout_2->addWidget(radioButton, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(addProfileInterface);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 60, 201, 31));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelId = new QLabel(gridLayoutWidget_3);
        labelId->setObjectName("labelId");

        gridLayout_3->addWidget(labelId, 0, 0, 1, 1);

        idLogin = new QLineEdit(gridLayoutWidget_3);
        idLogin->setObjectName("idLogin");
        idLogin->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout_3->addWidget(idLogin, 0, 1, 1, 1);

        labelConnection = new QLabel(addProfileInterface);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(40, 10, 141, 19));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);
        labelConnection_2 = new QLabel(addProfileInterface);
        labelConnection_2->setObjectName("labelConnection_2");
        labelConnection_2->setGeometry(QRect(20, 40, 171, 19));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        labelConnection_2->setFont(font1);
        labelConnection_3 = new QLabel(addProfileInterface);
        labelConnection_3->setObjectName("labelConnection_3");
        labelConnection_3->setGeometry(QRect(50, 90, 91, 19));
        labelConnection_3->setFont(font1);

        retranslateUi(addProfileInterface);

        QMetaObject::connectSlotsByName(addProfileInterface);
    } // setupUi

    void retranslateUi(QWidget *addProfileInterface)
    {
        addProfileInterface->setWindowTitle(QCoreApplication::translate("addProfileInterface", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("addProfileInterface", "Valider", nullptr));
        radioButton_2->setText(QCoreApplication::translate("addProfileInterface", "Lecture/Modifcation", nullptr));
        radioButton->setText(QCoreApplication::translate("addProfileInterface", "Lecture", nullptr));
        labelId->setText(QCoreApplication::translate("addProfileInterface", "Nom:", nullptr));
        labelConnection->setText(QCoreApplication::translate("addProfileInterface", "Nouveau Profil", nullptr));
        labelConnection_2->setText(QCoreApplication::translate("addProfileInterface", "Comment souhaitez vous appeler le profil ?", nullptr));
        labelConnection_3->setText(QCoreApplication::translate("addProfileInterface", "Avec quelles droits ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addProfileInterface: public Ui_addProfileInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROFILEINTERFACE_H
