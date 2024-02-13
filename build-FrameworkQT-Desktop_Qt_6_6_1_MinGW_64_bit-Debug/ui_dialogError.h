/********************************************************************************
** Form generated from reading UI file 'dialogError.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERROR_H
#define UI_DIALOGERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPopUpOk
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonOk;

    void setupUi(QDialog *DialogPopUpOk)
    {
        if (DialogPopUpOk->objectName().isEmpty())
            DialogPopUpOk->setObjectName("DialogPopUpOk");
        DialogPopUpOk->resize(205, 103);
        plainTextEdit = new QPlainTextEdit(DialogPopUpOk);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 10, 191, 61));
        pushButtonOk = new QPushButton(DialogPopUpOk);
        pushButtonOk->setObjectName("pushButtonOk");
        pushButtonOk->setGeometry(QRect(60, 80, 80, 18));

        retranslateUi(DialogPopUpOk);

        QMetaObject::connectSlotsByName(DialogPopUpOk);
    } // setupUi

    void retranslateUi(QDialog *DialogPopUpOk)
    {
        DialogPopUpOk->setWindowTitle(QCoreApplication::translate("DialogPopUpOk", "Dialog", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("DialogPopUpOk", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPopUpOk: public Ui_DialogPopUpOk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERROR_H
