/********************************************************************************
** Form generated from reading UI file 'backbutton.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKBUTTON_H
#define UI_BACKBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cancelButton
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *cancelButton)
    {
        if (cancelButton->objectName().isEmpty())
            cancelButton->setObjectName("cancelButton");
        cancelButton->resize(96, 19);
        pushButton = new QPushButton(cancelButton);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 0, 80, 18));

        retranslateUi(cancelButton);

        QMetaObject::connectSlotsByName(cancelButton);
    } // setupUi

    void retranslateUi(QWidget *cancelButton)
    {
        cancelButton->setWindowTitle(QCoreApplication::translate("cancelButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("cancelButton", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cancelButton: public Ui_cancelButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKBUTTON_H
