/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Bouton_OuvertureExplorateurFichier;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_Longueur;
    QSpinBox *spinBox_Y;
    QSpinBox *spinBox_Hauteur;
    QLabel *label;
    QSpinBox *spinBox_X;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_Enregistrer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Bouton_OuvertureExplorateurFichier = new QPushButton(centralwidget);
        Bouton_OuvertureExplorateurFichier->setObjectName("Bouton_OuvertureExplorateurFichier");
        Bouton_OuvertureExplorateurFichier->setGeometry(QRect(340, 440, 91, 21));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 450, 251, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_Longueur = new QSpinBox(gridLayoutWidget);
        spinBox_Longueur->setObjectName("spinBox_Longueur");

        gridLayout->addWidget(spinBox_Longueur, 1, 3, 1, 1);

        spinBox_Y = new QSpinBox(gridLayoutWidget);
        spinBox_Y->setObjectName("spinBox_Y");

        gridLayout->addWidget(spinBox_Y, 1, 1, 1, 1);

        spinBox_Hauteur = new QSpinBox(gridLayoutWidget);
        spinBox_Hauteur->setObjectName("spinBox_Hauteur");

        gridLayout->addWidget(spinBox_Hauteur, 0, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        spinBox_X = new QSpinBox(gridLayoutWidget);
        spinBox_X->setObjectName("spinBox_X");

        gridLayout->addWidget(spinBox_X, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        pushButton_Enregistrer = new QPushButton(centralwidget);
        pushButton_Enregistrer->setObjectName("pushButton_Enregistrer");
        pushButton_Enregistrer->setGeometry(QRect(340, 480, 81, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Bouton_OuvertureExplorateurFichier->setText(QCoreApplication::translate("MainWindow", "Ouvrir", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hauteur", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Longueur", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        pushButton_Enregistrer->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
