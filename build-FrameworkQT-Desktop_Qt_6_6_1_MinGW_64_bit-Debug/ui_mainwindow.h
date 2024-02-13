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
        stackedWidgetCenter = new QStackedWidget(centralwidget);
        stackedWidgetCenter->setObjectName("stackedWidgetCenter");
        stackedWidgetCenter->setGeometry(QRect(0, 50, 800, 500));
        connection = new Connection();
        connection->setObjectName("connection");
        stackedWidgetCenter->addWidget(connection);
        stackedWidgetDeconnection = new QStackedWidget(centralwidget);
        stackedWidgetDeconnection->setObjectName("stackedWidgetDeconnection");
        stackedWidgetDeconnection->setGeometry(QRect(700, 0, 101, 41));
        deconnection = new Deconnection();
        deconnection->setObjectName("deconnection");
        stackedWidgetDeconnection->addWidget(deconnection);
        void_2 = new QWidget();
        void_2->setObjectName("void_2");
        stackedWidgetDeconnection->addWidget(void_2);
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
