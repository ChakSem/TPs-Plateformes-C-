/********************************************************************************
** Form generated from reading UI file 'indexprofil.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXPROFIL_H
#define UI_INDEXPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IndexProfil
{
public:
    QComboBox *comboBox;
    QLabel *labelConnection;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *IndexProfil)
    {
        if (IndexProfil->objectName().isEmpty())
            IndexProfil->setObjectName("IndexProfil");
        IndexProfil->resize(400, 300);
        comboBox = new QComboBox(IndexProfil);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 100, 211, 24));
        labelConnection = new QLabel(IndexProfil);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(140, 20, 81, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);
        pushButton = new QPushButton(IndexProfil);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 40, 80, 24));
        pushButton_2 = new QPushButton(IndexProfil);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 80, 80, 24));
        pushButton_3 = new QPushButton(IndexProfil);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 120, 80, 24));
        pushButton_4 = new QPushButton(IndexProfil);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(300, 160, 80, 24));

        retranslateUi(IndexProfil);

        QMetaObject::connectSlotsByName(IndexProfil);
    } // setupUi

    void retranslateUi(QDialog *IndexProfil)
    {
        IndexProfil->setWindowTitle(QCoreApplication::translate("IndexProfil", "Dialog", nullptr));
        labelConnection->setText(QCoreApplication::translate("IndexProfil", "Choix Profil", nullptr));
        pushButton->setText(QCoreApplication::translate("IndexProfil", "G\303\251rer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IndexProfil", "Supprimer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("IndexProfil", "Ajouter un Profil", nullptr));
        pushButton_4->setText(QCoreApplication::translate("IndexProfil", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexProfil: public Ui_IndexProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXPROFIL_H
