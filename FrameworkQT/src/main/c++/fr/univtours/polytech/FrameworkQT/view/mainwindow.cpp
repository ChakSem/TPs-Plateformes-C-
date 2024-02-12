#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidgetCenter->setCurrentIndex(1);
    ui->stackedWidgetDeconnection->setCurrentIndex(1);

    connect(ui->boutton, &QPushButton::clicked, this, &MainWindow::displayDeconnection);
}
QStackedWidget* MainWindow::getWidgetCenter() {
    return ui->stackedWidgetCenter;
}

QStackedWidget* MainWindow::getWidgetDeconnection() {
    return ui->stackedWidgetDeconnection;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::displayDeconnection() {
    qDebug() << "ca marche";

    ui->stackedWidgetDeconnection->setCurrentIndex(2);
}
