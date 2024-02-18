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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/view/connectioninterface.h"
#include "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/view/deconnectionButton.h"
#include "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/view/homebuttons.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *MainWidget;
    Connection *connection;
    HomeButtons *home;
    QStackedWidget *DeconnectionWidget;
    Deconnection *deconnection;
    QWidget *void_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 550);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QLineEdit {\n"
"	background : transparent;\n"
"	border : none;\n"
"    color :  white;\n"
"	border-bottom : 1px solid #717072;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"background : grey;\n"
"border-radius:15px;\n"
"\n"
"color : white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWidget = new QStackedWidget(centralwidget);
        MainWidget->setObjectName("MainWidget");
        MainWidget->setGeometry(QRect(0, 50, 800, 500));
        MainWidget->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background : #333;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background : transparent;\n"
"	border : none;\n"
"    color :  #710702;\n"
"border-bottom : 1px solid #717072;\n"
"}\n"
"QPushButton {\n"
"background : grey;\n"
"border-radius:15px;\n"
"\n"
"color : white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"}"));
        connection = new Connection();
        connection->setObjectName("connection");
        MainWidget->addWidget(connection);
        home = new HomeButtons();
        home->setObjectName("home");
        MainWidget->addWidget(home);
        DeconnectionWidget = new QStackedWidget(centralwidget);
        DeconnectionWidget->setObjectName("DeconnectionWidget");
        DeconnectionWidget->setGeometry(QRect(700, 0, 101, 41));
        DeconnectionWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background : grey;\n"
"border-radius:15px;\n"
"\n"
"color : white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"}"));
        deconnection = new Deconnection();
        deconnection->setObjectName("deconnection");
        DeconnectionWidget->addWidget(deconnection);
        void_2 = new QWidget();
        void_2->setObjectName("void_2");
        DeconnectionWidget->addWidget(void_2);
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
