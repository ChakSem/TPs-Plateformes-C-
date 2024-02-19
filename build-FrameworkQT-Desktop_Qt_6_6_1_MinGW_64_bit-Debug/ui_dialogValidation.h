/********************************************************************************
** Form generated from reading UI file 'dialogvalidation.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGVALIDATION_H
#define UI_DIALOGVALIDATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogValidation
{
public:
    QPushButton *pushButtonValidate;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *DialogValidation)
    {
        if (DialogValidation->objectName().isEmpty())
            DialogValidation->setObjectName("DialogValidation");
        DialogValidation->resize(400, 300);
        pushButtonValidate = new QPushButton(DialogValidation);
        pushButtonValidate->setObjectName("pushButtonValidate");
        pushButtonValidate->setGeometry(QRect(10, 80, 80, 18));
        plainTextEdit = new QPlainTextEdit(DialogValidation);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 10, 191, 61));
        pushButtonCancel = new QPushButton(DialogValidation);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(120, 80, 80, 18));

        retranslateUi(DialogValidation);

        QMetaObject::connectSlotsByName(DialogValidation);
    } // setupUi

    void retranslateUi(QWidget *DialogValidation)
    {
        DialogValidation->setWindowTitle(QCoreApplication::translate("DialogValidation", "Form", nullptr));
        pushButtonValidate->setText(QCoreApplication::translate("DialogValidation", "Confirmer", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("DialogValidation", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogValidation: public Ui_DialogValidation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGVALIDATION_H
