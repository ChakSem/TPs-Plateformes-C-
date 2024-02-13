/********************************************************************************
** Form generated from reading UI file 'createupdatedeleteButtons.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUPDATEDELETEBUTTONS_H
#define UI_CREATEUPDATEDELETEBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexCreateUpdateDelete
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonAdd;

    void setupUi(QWidget *indexCreateUpdateDelete)
    {
        if (indexCreateUpdateDelete->objectName().isEmpty())
            indexCreateUpdateDelete->setObjectName("indexCreateUpdateDelete");
        indexCreateUpdateDelete->resize(161, 88);
        gridLayoutWidget = new QWidget(indexCreateUpdateDelete);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 160, 86));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonDelete = new QPushButton(gridLayoutWidget);
        pushButtonDelete->setObjectName("pushButtonDelete");

        gridLayout->addWidget(pushButtonDelete, 2, 0, 1, 1);

        pushButtonUpdate = new QPushButton(gridLayoutWidget);
        pushButtonUpdate->setObjectName("pushButtonUpdate");

        gridLayout->addWidget(pushButtonUpdate, 3, 0, 1, 1);

        pushButtonAdd = new QPushButton(gridLayoutWidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout->addWidget(pushButtonAdd, 1, 0, 1, 1);


        retranslateUi(indexCreateUpdateDelete);

        QMetaObject::connectSlotsByName(indexCreateUpdateDelete);
    } // setupUi

    void retranslateUi(QWidget *indexCreateUpdateDelete)
    {
        indexCreateUpdateDelete->setWindowTitle(QCoreApplication::translate("indexCreateUpdateDelete", "Form", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("indexCreateUpdateDelete", "Supprimer", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("indexCreateUpdateDelete", "Modifier", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("indexCreateUpdateDelete", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexCreateUpdateDelete: public Ui_indexCreateUpdateDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUPDATEDELETEBUTTONS_H
