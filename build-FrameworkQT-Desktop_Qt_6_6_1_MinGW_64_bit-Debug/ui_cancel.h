/********************************************************************************
** Form generated from reading UI file 'cancel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCEL_H
#define UI_CANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cancel
{
public:
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *cancel)
    {
        if (cancel->objectName().isEmpty())
            cancel->setObjectName("cancel");
        cancel->resize(86, 25);
        pushButtonCancel = new QPushButton(cancel);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(0, 0, 85, 24));

        retranslateUi(cancel);

        QMetaObject::connectSlotsByName(cancel);
    } // setupUi

    void retranslateUi(QWidget *cancel)
    {
        cancel->setWindowTitle(QCoreApplication::translate("cancel", "Form", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("cancel", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cancel: public Ui_cancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCEL_H
