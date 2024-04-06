/********************************************************************************
** Form generated from reading UI file 'databasemanagementinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
    QPushButton *pushButtonVisualization;
    QPushButton *pushButtonExecute;
    QComboBox *comboBoxTable;
    QComboBox *comboBoxCommand;

    void setupUi(QWidget *DatabaseManagementInterface)
    {
        if (DatabaseManagementInterface->objectName().isEmpty())
            DatabaseManagementInterface->setObjectName("DatabaseManagementInterface");
        DatabaseManagementInterface->resize(600, 400);
        labelDatabaseManagement = new QLabel(DatabaseManagementInterface);
        labelDatabaseManagement->setObjectName("labelDatabaseManagement");
        labelDatabaseManagement->setGeometry(QRect(220, 20, 351, 27));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
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
        plainTextEdit->setGeometry(QRect(120, 180, 341, 191));
        labelRequest = new QLabel(DatabaseManagementInterface);
        labelRequest->setObjectName("labelRequest");
        labelRequest->setGeometry(QRect(10, 160, 311, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        labelRequest->setFont(font1);
        pushButtonVisualization = new QPushButton(DatabaseManagementInterface);
        pushButtonVisualization->setObjectName("pushButtonVisualization");
        pushButtonVisualization->setGeometry(QRect(460, 100, 80, 24));
        pushButtonExecute = new QPushButton(DatabaseManagementInterface);
        pushButtonExecute->setObjectName("pushButtonExecute");
        pushButtonExecute->setGeometry(QRect(460, 180, 80, 24));
        comboBoxTable = new QComboBox(DatabaseManagementInterface);
        comboBoxTable->setObjectName("comboBoxTable");
        comboBoxTable->setGeometry(QRect(120, 100, 341, 22));
        comboBoxCommand = new QComboBox(DatabaseManagementInterface);
        comboBoxCommand->setObjectName("comboBoxCommand");
        comboBoxCommand->setGeometry(QRect(10, 180, 111, 22));

        retranslateUi(DatabaseManagementInterface);

        QMetaObject::connectSlotsByName(DatabaseManagementInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabaseManagementInterface)
    {
        DatabaseManagementInterface->setWindowTitle(QCoreApplication::translate("DatabaseManagementInterface", "Form", nullptr));
        labelDatabaseManagement->setText(QCoreApplication::translate("DatabaseManagementInterface", "Interface BDD", nullptr));
        labelRequest->setText(QCoreApplication::translate("DatabaseManagementInterface", "Commandes", nullptr));
        pushButtonVisualization->setText(QCoreApplication::translate("DatabaseManagementInterface", "Visualiser", nullptr));
        pushButtonExecute->setText(QCoreApplication::translate("DatabaseManagementInterface", "Executer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseManagementInterface: public Ui_DatabaseManagementInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEMANAGEMENTINTERFACE_H
