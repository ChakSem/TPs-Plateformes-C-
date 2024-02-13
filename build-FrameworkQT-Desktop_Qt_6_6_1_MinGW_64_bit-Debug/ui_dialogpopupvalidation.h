/********************************************************************************
** Form generated from reading UI file 'dialogpopupvalidation.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOPUPVALIDATION_H
#define UI_DIALOGPOPUPVALIDATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPopUpValidation
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonValidation;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DialogPopUpValidation)
    {
        if (DialogPopUpValidation->objectName().isEmpty())
            DialogPopUpValidation->setObjectName("DialogPopUpValidation");
        DialogPopUpValidation->resize(216, 101);
        plainTextEdit = new QPlainTextEdit(DialogPopUpValidation);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 10, 191, 61));
        pushButtonValidation = new QPushButton(DialogPopUpValidation);
        pushButtonValidation->setObjectName("pushButtonValidation");
        pushButtonValidation->setGeometry(QRect(10, 80, 80, 18));
        pushButton_2 = new QPushButton(DialogPopUpValidation);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 80, 80, 18));

        retranslateUi(DialogPopUpValidation);

        QMetaObject::connectSlotsByName(DialogPopUpValidation);
    } // setupUi

    void retranslateUi(QDialog *DialogPopUpValidation)
    {
        DialogPopUpValidation->setWindowTitle(QCoreApplication::translate("DialogPopUpValidation", "Dialog", nullptr));
        pushButtonValidation->setText(QCoreApplication::translate("DialogPopUpValidation", "Confirmer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogPopUpValidation", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPopUpValidation: public Ui_DialogPopUpValidation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOPUPVALIDATION_H
