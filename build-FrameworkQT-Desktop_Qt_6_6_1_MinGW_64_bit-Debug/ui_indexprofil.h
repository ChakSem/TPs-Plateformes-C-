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

    void setupUi(QDialog *IndexProfil)
    {
        if (IndexProfil->objectName().isEmpty())
            IndexProfil->setObjectName("IndexProfil");
        IndexProfil->resize(400, 300);
        comboBox = new QComboBox(IndexProfil);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(50, 120, 211, 24));
        labelConnection = new QLabel(IndexProfil);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(140, 20, 111, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);
        pushButton = new QPushButton(IndexProfil);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 210, 80, 24));
        pushButton_2 = new QPushButton(IndexProfil);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 210, 80, 24));

        retranslateUi(IndexProfil);

        QMetaObject::connectSlotsByName(IndexProfil);
    } // setupUi

    void retranslateUi(QDialog *IndexProfil)
    {
        IndexProfil->setWindowTitle(QCoreApplication::translate("IndexProfil", "Dialog", nullptr));
        labelConnection->setText(QCoreApplication::translate("IndexProfil", "Choix Profile", nullptr));
        pushButton->setText(QCoreApplication::translate("IndexProfil", "Charger Profile", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IndexProfil", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexProfil: public Ui_IndexProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXPROFIL_H
