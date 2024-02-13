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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "..\FrameworkQT\src\main\c++\fr\univtours\polytech\FrameworkQT\view\connection.h"
#include "..\FrameworkQT\src\main\c++\fr\univtours\polytech\FrameworkQT\view\deconnection.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidgetCenter;
    Connection *connection;
    QStackedWidget *stackedWidgetDeconnection;
    Deconnection *deconnection;
    QWidget *void_2;
    QPushButton *boutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidgetCenter = new QStackedWidget(centralwidget);
        stackedWidgetCenter->setObjectName("stackedWidgetCenter");
        stackedWidgetCenter->setGeometry(QRect(50, 50, 661, 491));
        connection = new Connection();
        connection->setObjectName("connection");
        stackedWidgetCenter->addWidget(connection);
        stackedWidgetDeconnection = new QStackedWidget(centralwidget);
        stackedWidgetDeconnection->setObjectName("stackedWidgetDeconnection");
        stackedWidgetDeconnection->setGeometry(QRect(670, 0, 131, 41));
        deconnection = new Deconnection();
        deconnection->setObjectName("deconnection");
        stackedWidgetDeconnection->addWidget(deconnection);
        void_2 = new QWidget();
        void_2->setObjectName("void_2");
        stackedWidgetDeconnection->addWidget(void_2);
        boutton = new QPushButton(centralwidget);
        boutton->setObjectName("boutton");
        boutton->setGeometry(QRect(0, 20, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        boutton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
