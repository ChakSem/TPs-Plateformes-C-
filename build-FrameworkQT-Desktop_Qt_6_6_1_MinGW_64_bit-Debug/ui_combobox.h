/********************************************************************************
** Form generated from reading UI file 'combobox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBOBOX_H
#define UI_COMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComboBox
{
public:
    QComboBox *comboBoxProfiles;

    void setupUi(QWidget *ComboBox)
    {
        if (ComboBox->objectName().isEmpty())
            ComboBox->setObjectName("ComboBox");
        ComboBox->resize(223, 40);
        comboBoxProfiles = new QComboBox(ComboBox);
        comboBoxProfiles->setObjectName("comboBoxProfiles");
        comboBoxProfiles->setGeometry(QRect(10, 10, 211, 24));

        retranslateUi(ComboBox);

        QMetaObject::connectSlotsByName(ComboBox);
    } // setupUi

    void retranslateUi(QWidget *ComboBox)
    {
        ComboBox->setWindowTitle(QCoreApplication::translate("ComboBox", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboBox: public Ui_ComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOBOX_H
