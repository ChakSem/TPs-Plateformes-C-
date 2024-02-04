/********************************************************************************
** Form generated from reading UI file 'indexhome.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXHOME_H
#define UI_INDEXHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IndexHome
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelConnection;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButtonBack;

    void setupUi(QDialog *IndexHome)
    {
        if (IndexHome->objectName().isEmpty())
            IndexHome->setObjectName("IndexHome");
        IndexHome->resize(400, 300);
        verticalLayout = new QVBoxLayout(IndexHome);
        verticalLayout->setObjectName("verticalLayout");
        labelConnection = new QLabel(IndexHome);
        labelConnection->setObjectName("labelConnection");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelConnection->sizePolicy().hasHeightForWidth());
        labelConnection->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelConnection->setFont(font);

        verticalLayout->addWidget(labelConnection, 0, Qt::AlignHCenter);

        pushButton = new QPushButton(IndexHome);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(IndexHome);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(IndexHome);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(IndexHome);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(IndexHome);
        pushButton_5->setObjectName("pushButton_5");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_5);

        pushButtonBack = new QPushButton(IndexHome);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setMaximumSize(QSize(230, 16777215));

        verticalLayout->addWidget(pushButtonBack);


        retranslateUi(IndexHome);

        QMetaObject::connectSlotsByName(IndexHome);
    } // setupUi

    void retranslateUi(QDialog *IndexHome)
    {
        IndexHome->setWindowTitle(QCoreApplication::translate("IndexHome", "Dialog", nullptr));
        labelConnection->setText(QCoreApplication::translate("IndexHome", "Choix Action", nullptr));
        pushButton->setText(QCoreApplication::translate("IndexHome", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IndexHome", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("IndexHome", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("IndexHome", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("IndexHome", "PushButton", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("IndexHome", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexHome: public Ui_IndexHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXHOME_H
