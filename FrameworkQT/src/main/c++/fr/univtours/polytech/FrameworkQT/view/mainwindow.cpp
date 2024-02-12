#include "mainwindow.h"
#include "connection.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidgetCenter->setCurrentIndex(1);
}

Ui::MainWindow* MainWindow::getUi() {
    return ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}
