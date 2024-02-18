/********************************************************************************
** Form generated from reading UI file 'accountinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTINTERFACE_H
#define UI_ACCOUNTINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountInterface
{
public:

    void setupUi(QWidget *accountInterface)
    {
        if (accountInterface->objectName().isEmpty())
            accountInterface->setObjectName("accountInterface");
        accountInterface->resize(800, 500);

        retranslateUi(accountInterface);

        QMetaObject::connectSlotsByName(accountInterface);
    } // setupUi

    void retranslateUi(QWidget *accountInterface)
    {
        accountInterface->setWindowTitle(QCoreApplication::translate("accountInterface", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountInterface: public Ui_accountInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTINTERFACE_H
