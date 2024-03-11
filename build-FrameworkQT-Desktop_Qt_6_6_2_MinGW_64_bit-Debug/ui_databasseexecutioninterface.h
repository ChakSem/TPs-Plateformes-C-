/********************************************************************************
** Form generated from reading UI file 'databasseexecutioninterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASSEEXECUTIONINTERFACE_H
#define UI_DATABASSEEXECUTIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasseExecutionInterface
{
public:

    void setupUi(QWidget *DatabasseExecutionInterface)
    {
        if (DatabasseExecutionInterface->objectName().isEmpty())
            DatabasseExecutionInterface->setObjectName("DatabasseExecutionInterface");
        DatabasseExecutionInterface->resize(600, 400);

        retranslateUi(DatabasseExecutionInterface);

        QMetaObject::connectSlotsByName(DatabasseExecutionInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabasseExecutionInterface)
    {
        DatabasseExecutionInterface->setWindowTitle(QCoreApplication::translate("DatabasseExecutionInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabasseExecutionInterface: public Ui_DatabasseExecutionInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASSEEXECUTIONINTERFACE_H
