/********************************************************************************
** Form generated from reading UI file 'deconnectionButton.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECONNECTIONBUTTON_H
#define UI_DECONNECTIONBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deconnection
{
public:
    QPushButton *pushButtonDeconnection;

    void setupUi(QWidget *Deconnection)
    {
        if (Deconnection->objectName().isEmpty())
            Deconnection->setObjectName("Deconnection");
        Deconnection->resize(103, 32);
        pushButtonDeconnection = new QPushButton(Deconnection);
        pushButtonDeconnection->setObjectName("pushButtonDeconnection");
        pushButtonDeconnection->setGeometry(QRect(0, 0, 101, 31));
        pushButtonDeconnection->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background : grey;\n"
"border-radius:15px;\n"
"\n"
"color : white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"}"));

        retranslateUi(Deconnection);

        QMetaObject::connectSlotsByName(Deconnection);
    } // setupUi

    void retranslateUi(QWidget *Deconnection)
    {
        Deconnection->setWindowTitle(QCoreApplication::translate("Deconnection", "Form", nullptr));
        pushButtonDeconnection->setText(QCoreApplication::translate("Deconnection", "Se D\303\251connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deconnection: public Ui_Deconnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECONNECTIONBUTTON_H
