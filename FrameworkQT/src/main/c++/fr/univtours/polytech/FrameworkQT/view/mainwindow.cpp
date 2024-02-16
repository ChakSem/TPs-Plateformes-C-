#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainWidget->setCurrentIndex(0);
    ui->DeconnectionWidget->setCurrentIndex(1);
    
    qDebug() << "Stacked Widget Deconnection initialized with current index:" << ui->DeconnectionWidget->currentIndex();
}
QStackedWidget* MainWindow::getWidgetCenter() {
    return ui->MainWidget;
}

QStackedWidget* MainWindow::getWidgetDeconnection() {
    return ui->DeconnectionWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayDeconnection() {
    ui->DeconnectionWidget->setCurrentIndex(0); // On affiche le bouton deconnexion
}

