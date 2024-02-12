/********************************************************************************
** Form generated from reading UI file 'indexPopUpOk.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXPOPUPOK_H
#define UI_INDEXPOPUPOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_indexPopUpChampsManquants
{
public:
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *indexPopUpChampsManquants)
    {
        if (indexPopUpChampsManquants->objectName().isEmpty())
            indexPopUpChampsManquants->setObjectName("indexPopUpChampsManquants");
        indexPopUpChampsManquants->resize(400, 300);
        pushButton = new QPushButton(indexPopUpChampsManquants);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 220, 80, 18));
        plainTextEdit = new QPlainTextEdit(indexPopUpChampsManquants);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(110, 90, 191, 121));

        retranslateUi(indexPopUpChampsManquants);

        QMetaObject::connectSlotsByName(indexPopUpChampsManquants);
    } // setupUi

    void retranslateUi(QDialog *indexPopUpChampsManquants)
    {
        indexPopUpChampsManquants->setWindowTitle(QCoreApplication::translate("indexPopUpChampsManquants", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("indexPopUpChampsManquants", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexPopUpChampsManquants: public Ui_indexPopUpChampsManquants {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXPOPUPOK_H
