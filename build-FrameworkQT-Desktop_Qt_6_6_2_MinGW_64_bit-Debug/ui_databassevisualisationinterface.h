/********************************************************************************
** Form generated from reading UI file 'databassevisualisationinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASSEVISUALISATIONINTERFACE_H
#define UI_DATABASSEVISUALISATIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasseVisualisationInterface
{
public:
    QLabel *labelConnection;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DatabasseVisualisationInterface)
    {
        if (DatabasseVisualisationInterface->objectName().isEmpty())
            DatabasseVisualisationInterface->setObjectName("DatabasseVisualisationInterface");
        DatabasseVisualisationInterface->resize(600, 400);
        labelConnection = new QLabel(DatabasseVisualisationInterface);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(120, 20, 351, 27));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelConnection->sizePolicy().hasHeightForWidth());
        labelConnection->setSizePolicy(sizePolicy);
        labelConnection->setMinimumSize(QSize(0, 13));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelConnection->setFont(font);
        tableWidget = new QTableWidget(DatabasseVisualisationInterface);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 60, 561, 331));

        retranslateUi(DatabasseVisualisationInterface);

        QMetaObject::connectSlotsByName(DatabasseVisualisationInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabasseVisualisationInterface)
    {
        DatabasseVisualisationInterface->setWindowTitle(QCoreApplication::translate("DatabasseVisualisationInterface", "Form", nullptr));
        labelConnection->setText(QCoreApplication::translate("DatabasseVisualisationInterface", "Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabasseVisualisationInterface: public Ui_DatabasseVisualisationInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASSEVISUALISATIONINTERFACE_H
