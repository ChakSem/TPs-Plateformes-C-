/********************************************************************************
** Form generated from reading UI file 'databassevisualisationinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASSEVISUALISATIONINTERFACE_H
#define UI_DATABASSEVISUALISATIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasseVisualisationInterface
{
public:

    void setupUi(QWidget *DatabasseVisualisationInterface)
    {
        if (DatabasseVisualisationInterface->objectName().isEmpty())
            DatabasseVisualisationInterface->setObjectName("DatabasseVisualisationInterface");
        DatabasseVisualisationInterface->resize(400, 300);

        retranslateUi(DatabasseVisualisationInterface);

        QMetaObject::connectSlotsByName(DatabasseVisualisationInterface);
    } // setupUi

    void retranslateUi(QWidget *DatabasseVisualisationInterface)
    {
        DatabasseVisualisationInterface->setWindowTitle(QCoreApplication::translate("DatabasseVisualisationInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabasseVisualisationInterface: public Ui_DatabasseVisualisationInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASSEVISUALISATIONINTERFACE_H
