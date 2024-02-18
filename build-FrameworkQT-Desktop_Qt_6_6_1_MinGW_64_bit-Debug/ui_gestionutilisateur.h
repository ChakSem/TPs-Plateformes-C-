/********************************************************************************
** Form generated from reading UI file 'gestionutilisateur.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONUTILISATEUR_H
#define UI_GESTIONUTILISATEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionUtilisateur
{
public:
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonAdd;
    QTableView *tableView;

    void setupUi(QWidget *GestionUtilisateur)
    {
        if (GestionUtilisateur->objectName().isEmpty())
            GestionUtilisateur->setObjectName("GestionUtilisateur");
        GestionUtilisateur->resize(593, 333);
        pushButtonUpdate = new QPushButton(GestionUtilisateur);
        pushButtonUpdate->setObjectName("pushButtonUpdate");
        pushButtonUpdate->setGeometry(QRect(380, 180, 158, 24));
        pushButtonDelete = new QPushButton(GestionUtilisateur);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(380, 150, 158, 24));
        pushButtonAdd = new QPushButton(GestionUtilisateur);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(380, 120, 158, 24));
        tableView = new QTableView(GestionUtilisateur);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 80, 256, 192));

        retranslateUi(GestionUtilisateur);

        QMetaObject::connectSlotsByName(GestionUtilisateur);
    } // setupUi

    void retranslateUi(QWidget *GestionUtilisateur)
    {
        GestionUtilisateur->setWindowTitle(QCoreApplication::translate("GestionUtilisateur", "Form", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("GestionUtilisateur", "Modifier", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("GestionUtilisateur", "Supprimer", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("GestionUtilisateur", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionUtilisateur: public Ui_GestionUtilisateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONUTILISATEUR_H
