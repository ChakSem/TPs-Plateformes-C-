/********************************************************************************
** Form generated from reading UI file 'databasevisualisationinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEVISUALISATIONINTERFACE_H
#define UI_DATABASEVISUALISATIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseVisualisationInterface
{
public:
    QLabel *labelConnection;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DatabaseVisualisationInterface)
    {
        if (DatabaseVisualisationInterface->objectName().isEmpty())
            DatabaseVisualisationInterface->setObjectName("DatabaseVisualisationInterface");
        DatabaseVisualisationInterface->resize(600, 400);
        labelConnection = new QLabel(DatabaseVisualisationInterface);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(20, 20, 351, 27));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelConnection->sizePolicy().hasHeightForWidth());
        labelConnection->setSizePolicy(sizePolicy);
        labelConnection->setMinimumSize(QSize(0, 13));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelConnection->setFont(font);
        tableWidget = new QTableWidget(DatabaseVisualisationInterface);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 50, 561, 331));

        retranslateUi(DatabaseVisualisationInterface);

        QMetaObject::connectSlotsByName(DatabaseVisualisationInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabaseVisualisationInterface)
    {
        DatabaseVisualisationInterface->setWindowTitle(QCoreApplication::translate("DatabaseVisualisationInterface", "Form", nullptr));
        labelConnection->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DatabaseVisualisationInterface: public Ui_DatabaseVisualisationInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEVISUALISATIONINTERFACE_H
