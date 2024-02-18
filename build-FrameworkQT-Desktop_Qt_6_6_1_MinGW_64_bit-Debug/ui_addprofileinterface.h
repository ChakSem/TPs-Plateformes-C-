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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelConnection_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lableNewNameProfile;
    QLabel *labelId;
    QLabel *labelConnection_2;
    QPushButton *pushButtonValidation;
    QLabel *labelConnection;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButoonReadUpdateRight;
    QRadioButton *radioButoonReadRight;

    void setupUi(QWidget *addProfileInterface)
    {
        if (addProfileInterface->objectName().isEmpty())
            addProfileInterface->setObjectName("addProfileInterface");
        addProfileInterface->resize(800, 500);
        gridLayoutWidget = new QWidget(addProfileInterface);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 501));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelConnection_3 = new QLabel(gridLayoutWidget);
        labelConnection_3->setObjectName("labelConnection_3");
        labelConnection_3->setMaximumSize(QSize(100, 10));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        labelConnection_3->setFont(font);

        gridLayout->addWidget(labelConnection_3, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        lableNewNameProfile = new QLineEdit(gridLayoutWidget);
        lableNewNameProfile->setObjectName("lableNewNameProfile");
        lableNewNameProfile->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout_3->addWidget(lableNewNameProfile, 0, 1, 1, 1);

        labelId = new QLabel(gridLayoutWidget);
        labelId->setObjectName("labelId");

        gridLayout_3->addWidget(labelId, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 2, 0, 1, 1);

        labelConnection_2 = new QLabel(gridLayoutWidget);
        labelConnection_2->setObjectName("labelConnection_2");
        labelConnection_2->setMaximumSize(QSize(200, 10));
        labelConnection_2->setFont(font);

        gridLayout->addWidget(labelConnection_2, 1, 0, 1, 1);

        pushButtonValidation = new QPushButton(gridLayoutWidget);
        pushButtonValidation->setObjectName("pushButtonValidation");

        gridLayout->addWidget(pushButtonValidation, 5, 0, 1, 1);

        labelConnection = new QLabel(gridLayoutWidget);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setMaximumSize(QSize(100, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        labelConnection->setFont(font1);

        gridLayout->addWidget(labelConnection, 0, 0, 1, 1, Qt::AlignHCenter);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        radioButoonReadUpdateRight = new QRadioButton(gridLayoutWidget);
        radioButoonReadUpdateRight->setObjectName("radioButoonReadUpdateRight");

        gridLayout_2->addWidget(radioButoonReadUpdateRight, 2, 0, 1, 1);

        radioButoonReadRight = new QRadioButton(gridLayoutWidget);
        radioButoonReadRight->setObjectName("radioButoonReadRight");

        gridLayout_2->addWidget(radioButoonReadRight, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 0, 1, 1);


        retranslateUi(addProfileInterface);

        QMetaObject::connectSlotsByName(addProfileInterface);
    } // setupUi

    void retranslateUi(QWidget *addProfileInterface)
    {
        addProfileInterface->setWindowTitle(QCoreApplication::translate("addProfileInterface", "Form", nullptr));
        labelConnection_3->setText(QCoreApplication::translate("addProfileInterface", "Avec quelles droits ?", nullptr));
        labelId->setText(QCoreApplication::translate("addProfileInterface", "Nom:", nullptr));
        labelConnection_2->setText(QCoreApplication::translate("addProfileInterface", "Comment souhaitez vous appeler le profil ?", nullptr));
        pushButtonValidation->setText(QCoreApplication::translate("addProfileInterface", "Valider", nullptr));
        labelConnection->setText(QCoreApplication::translate("addProfileInterface", "Nouveau Profil", nullptr));
        radioButoonReadUpdateRight->setText(QCoreApplication::translate("addProfileInterface", "Lecture/Modifcation", nullptr));
        radioButoonReadRight->setText(QCoreApplication::translate("addProfileInterface", "Lecture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addProfileInterface: public Ui_addProfileInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROFILEINTERFACE_H
