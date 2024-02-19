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
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->actionDeconnection();
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}
