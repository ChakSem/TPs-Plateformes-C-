/********************************************************************************
** Form generated from reading UI file 'indexpopupvalidation.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXPOPUPVALIDATION_H
#define UI_INDEXPOPUPVALIDATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexPopUpValidation
{
public:
    QTextEdit *textEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Oui;
    QPushButton *Non;

    void setupUi(QDialog *indexPopUpValidation)
    {
        if (indexPopUpValidation->objectName().isEmpty())
            indexPopUpValidation->setObjectName("indexPopUpValidation");
        indexPopUpValidation->resize(400, 300);
        textEdit = new QTextEdit(indexPopUpValidation);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(90, 70, 221, 131));
        gridLayoutWidget = new QWidget(indexPopUpValidation);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(110, 210, 166, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Oui = new QPushButton(gridLayoutWidget);
        Oui->setObjectName("Oui");

        gridLayout->addWidget(Oui, 0, 0, 1, 1);

        Non = new QPushButton(gridLayoutWidget);
        Non->setObjectName("Non");

        gridLayout->addWidget(Non, 0, 1, 1, 1);


        retranslateUi(indexPopUpValidation);

        QMetaObject::connectSlotsByName(indexPopUpValidation);
    } // setupUi

    void retranslateUi(QDialog *indexPopUpValidation)
    {
        indexPopUpValidation->setWindowTitle(QCoreApplication::translate("indexPopUpValidation", "Dialog", nullptr));
        Oui->setText(QCoreApplication::translate("indexPopUpValidation", "Ok", nullptr));
        Non->setText(QCoreApplication::translate("indexPopUpValidation", "Non", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexPopUpValidation: public Ui_indexPopUpValidation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXPOPUPVALIDATION_H
