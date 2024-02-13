/********************************************************************************
** Form generated from reading UI file 'indextabledatausers.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXTABLEDATAUSERS_H
#define UI_INDEXTABLEDATAUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexTableDataUsers
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *indexTableDataUsers)
    {
        if (indexTableDataUsers->objectName().isEmpty())
            indexTableDataUsers->setObjectName("indexTableDataUsers");
        indexTableDataUsers->resize(208, 284);
        tableWidget = new QTableWidget(indexTableDataUsers);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 201, 281));

        retranslateUi(indexTableDataUsers);

        QMetaObject::connectSlotsByName(indexTableDataUsers);
    } // setupUi

    void retranslateUi(QWidget *indexTableDataUsers)
    {
        indexTableDataUsers->setWindowTitle(QCoreApplication::translate("indexTableDataUsers", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexTableDataUsers: public Ui_indexTableDataUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXTABLEDATAUSERS_H
