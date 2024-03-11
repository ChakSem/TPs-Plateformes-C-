/********************************************************************************
** Form generated from reading UI file 'databasemanagementinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEMANAGEMENTINTERFACE_H
#define UI_DATABASEMANAGEMENTINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseManagementInterface
{
public:
    QLabel *labelDatabaseManagement;
    QPlainTextEdit *plainTextEdit;
    QLabel *labelRequest;
    QPushButton *pushButtonVisualiza;
    QPushButton *pushButtonExecute;
    QComboBox *comboBoxTables;
    QComboBox *comboBoxTables_2;

    void setupUi(QWidget *DatabaseManagementInterface)
    {
        if (DatabaseManagementInterface->objectName().isEmpty())
            DatabaseManagementInterface->setObjectName("DatabaseManagementInterface");
        DatabaseManagementInterface->resize(600, 400);
        labelDatabaseManagement = new QLabel(DatabaseManagementInterface);
        labelDatabaseManagement->setObjectName("labelDatabaseManagement");
        labelDatabaseManagement->setGeometry(QRect(150, 20, 351, 27));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelDatabaseManagement->sizePolicy().hasHeightForWidth());
        labelDatabaseManagement->setSizePolicy(sizePolicy);
        labelDatabaseManagement->setMinimumSize(QSize(0, 13));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelDatabaseManagement->setFont(font);
        plainTextEdit = new QPlainTextEdit(DatabaseManagementInterface);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(90, 180, 371, 191));
        labelRequest = new QLabel(DatabaseManagementInterface);
        labelRequest->setObjectName("labelRequest");
        labelRequest->setGeometry(QRect(60, 150, 311, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        labelRequest->setFont(font1);
        pushButtonVisualiza = new QPushButton(DatabaseManagementInterface);
        pushButtonVisualiza->setObjectName("pushButtonVisualiza");
        pushButtonVisualiza->setGeometry(QRect(350, 100, 80, 24));
        pushButtonExecute = new QPushButton(DatabaseManagementInterface);
        pushButtonExecute->setObjectName("pushButtonExecute");
        pushButtonExecute->setGeometry(QRect(460, 180, 80, 24));
        comboBoxTables = new QComboBox(DatabaseManagementInterface);
        comboBoxTables->setObjectName("comboBoxTables");
        comboBoxTables->setGeometry(QRect(50, 100, 300, 22));
        comboBoxTables_2 = new QComboBox(DatabaseManagementInterface);
        comboBoxTables_2->addItem(QString());
        comboBoxTables_2->setObjectName("comboBoxTables_2");
        comboBoxTables_2->setGeometry(QRect(30, 180, 61, 22));

        retranslateUi(DatabaseManagementInterface);

        QMetaObject::connectSlotsByName(DatabaseManagementInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabaseManagementInterface)
    {
        DatabaseManagementInterface->setWindowTitle(QCoreApplication::translate("DatabaseManagementInterface", "Form", nullptr));
        labelDatabaseManagement->setText(QCoreApplication::translate("DatabaseManagementInterface", "Table", nullptr));
        labelRequest->setText(QCoreApplication::translate("DatabaseManagementInterface", "Commandes", nullptr));
        pushButtonVisualiza->setText(QCoreApplication::translate("DatabaseManagementInterface", "Visualiser", nullptr));
        pushButtonExecute->setText(QCoreApplication::translate("DatabaseManagementInterface", "Executer", nullptr));
        comboBoxTables_2->setItemText(0, QCoreApplication::translate("DatabaseManagementInterface", "Select", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DatabaseManagementInterface: public Ui_DatabaseManagementInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEMANAGEMENTINTERFACE_H
