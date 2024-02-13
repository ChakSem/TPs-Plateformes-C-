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

    qDebug() << "Stacked Widget Deconnection initialized with current index:" << ui->stackedWidgetDeconnection->currentIndex();
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
    ui->stackedWidgetDeconnection->setCurrentIndex(0); // On affiche le bouton deconnexion
}

