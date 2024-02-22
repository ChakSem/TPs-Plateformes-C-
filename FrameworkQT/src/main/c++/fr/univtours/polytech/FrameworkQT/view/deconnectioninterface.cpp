#include "deconnectioninterface.h"
#include "ui_deconnectioninterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

DeconnectionInterface::DeconnectionInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeconnectionInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonDeconnection, &QPushButton::clicked, this, &DeconnectionInterface::actionDeconnection);
}

DeconnectionInterface::~DeconnectionInterface()
{
    delete ui;
}

void DeconnectionInterface::actionDeconnection() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    if (mainWindow != NULL) {
            mainWindow->actionDeconnection();
    }
}
