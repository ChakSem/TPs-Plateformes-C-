/********************************************************************************
** Form generated from reading UI file 'indexbdd.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXBDD_H
#define UI_INDEXBDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_IndexBdd
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;

    void setupUi(QDialog *IndexBdd)
    {
        if (IndexBdd->objectName().isEmpty())
            IndexBdd->setObjectName("IndexBdd");
        IndexBdd->resize(400, 300);
        gridLayout = new QGridLayout(IndexBdd);
        gridLayout->setObjectName("gridLayout");
        comboBox = new QComboBox(IndexBdd);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        pushButton = new QPushButton(IndexBdd);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        tableView = new QTableView(IndexBdd);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 1, 0, 1, 2);

        pushButton_2 = new QPushButton(IndexBdd);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);


        retranslateUi(IndexBdd);

        QMetaObject::connectSlotsByName(IndexBdd);
    } // setupUi

    void retranslateUi(QDialog *IndexBdd)
    {
        IndexBdd->setWindowTitle(QCoreApplication::translate("IndexBdd", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("IndexBdd", "Ouvrir Base De Donnee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IndexBdd", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexBdd: public Ui_IndexBdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXBDD_H
