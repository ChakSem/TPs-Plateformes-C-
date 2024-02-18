/********************************************************************************
** Form generated from reading UI file 'profilesinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILESINTERFACE_H
#define UI_PROFILESINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profilesInterface
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonAdd;
    QComboBox *comboBoxProfiles;
    QLabel *labelConnection_2;
    QLabel *labelConnection;

    void setupUi(QWidget *profilesInterface)
    {
        if (profilesInterface->objectName().isEmpty())
            profilesInterface->setObjectName("profilesInterface");
        profilesInterface->resize(800, 500);
        gridLayoutWidget = new QWidget(profilesInterface);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 501));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonDelete = new QPushButton(gridLayoutWidget);
        pushButtonDelete->setObjectName("pushButtonDelete");

        gridLayout->addWidget(pushButtonDelete, 4, 0, 1, 1);

        pushButtonUpdate = new QPushButton(gridLayoutWidget);
        pushButtonUpdate->setObjectName("pushButtonUpdate");

        gridLayout->addWidget(pushButtonUpdate, 5, 0, 1, 1);

        pushButtonAdd = new QPushButton(gridLayoutWidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout->addWidget(pushButtonAdd, 3, 0, 1, 1);

        comboBoxProfiles = new QComboBox(gridLayoutWidget);
        comboBoxProfiles->setObjectName("comboBoxProfiles");

        gridLayout->addWidget(comboBoxProfiles, 2, 0, 1, 1);

        labelConnection_2 = new QLabel(gridLayoutWidget);
        labelConnection_2->setObjectName("labelConnection_2");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelConnection_2->sizePolicy().hasHeightForWidth());
        labelConnection_2->setSizePolicy(sizePolicy);
        labelConnection_2->setMinimumSize(QSize(0, 13));
        labelConnection_2->setMaximumSize(QSize(16777215, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        labelConnection_2->setFont(font);

        gridLayout->addWidget(labelConnection_2, 1, 0, 1, 1);

        labelConnection = new QLabel(gridLayoutWidget);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setEnabled(true);
        sizePolicy.setHeightForWidth(labelConnection->sizePolicy().hasHeightForWidth());
        labelConnection->setSizePolicy(sizePolicy);
        labelConnection->setMinimumSize(QSize(0, 13));
        labelConnection->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        labelConnection->setFont(font1);

        gridLayout->addWidget(labelConnection, 0, 0, 1, 1);


        retranslateUi(profilesInterface);

        QMetaObject::connectSlotsByName(profilesInterface);
    } // setupUi

    void retranslateUi(QWidget *profilesInterface)
    {
        profilesInterface->setWindowTitle(QCoreApplication::translate("profilesInterface", "Form", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("profilesInterface", "Supprimer", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("profilesInterface", "Modifier", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("profilesInterface", "Ajouter", nullptr));
        labelConnection_2->setText(QCoreApplication::translate("profilesInterface", "Veuillez selectionner un profil : ", nullptr));
        labelConnection->setText(QCoreApplication::translate("profilesInterface", "Page Profils", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profilesInterface: public Ui_profilesInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILESINTERFACE_H
