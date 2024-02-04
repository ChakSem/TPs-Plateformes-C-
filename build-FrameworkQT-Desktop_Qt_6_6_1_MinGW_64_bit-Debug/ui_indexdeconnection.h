/********************************************************************************
** Form generated from reading UI file 'indexdeconnection.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXDECONNECTION_H
#define UI_INDEXDECONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IndexDeconnection
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButtonDeconnection;

    void setupUi(QDialog *IndexDeconnection)
    {
        if (IndexDeconnection->objectName().isEmpty())
            IndexDeconnection->setObjectName("IndexDeconnection");
        IndexDeconnection->resize(103, 44);
        gridLayout = new QGridLayout(IndexDeconnection);
        gridLayout->setObjectName("gridLayout");
        pushButtonDeconnection = new QPushButton(IndexDeconnection);
        pushButtonDeconnection->setObjectName("pushButtonDeconnection");

        gridLayout->addWidget(pushButtonDeconnection, 0, 0, 1, 1);


        retranslateUi(IndexDeconnection);

        QMetaObject::connectSlotsByName(IndexDeconnection);
    } // setupUi

    void retranslateUi(QDialog *IndexDeconnection)
    {
        IndexDeconnection->setWindowTitle(QCoreApplication::translate("IndexDeconnection", "Dialog", nullptr));
        pushButtonDeconnection->setText(QCoreApplication::translate("IndexDeconnection", "Deconnection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexDeconnection: public Ui_IndexDeconnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXDECONNECTION_H
