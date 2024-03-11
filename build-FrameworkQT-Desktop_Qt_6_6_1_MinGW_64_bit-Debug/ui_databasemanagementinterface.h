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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseManagementInterface
{
public:

    void setupUi(QWidget *DatabaseManagementInterface)
    {
        if (DatabaseManagementInterface->objectName().isEmpty())
            DatabaseManagementInterface->setObjectName("DatabaseManagementInterface");
        DatabaseManagementInterface->resize(400, 300);

        retranslateUi(DatabaseManagementInterface);

        QMetaObject::connectSlotsByName(DatabaseManagementInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabaseManagementInterface)
    {
        DatabaseManagementInterface->setWindowTitle(QCoreApplication::translate("DatabaseManagementInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseManagementInterface: public Ui_DatabaseManagementInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEMANAGEMENTINTERFACE_H
