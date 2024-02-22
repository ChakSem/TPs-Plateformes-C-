#include "connectioninterface.h"
#include "ui_connectioninterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

#include <QStackedWidget>

ConnectionInterface::ConnectionInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConnectionInterface)
{
    ui->setupUi(this);

    connect( ui->pushButton, &QPushButton::clicked, this, &ConnectionInterface::actionConnection);
}

ConnectionInterface::~ConnectionInterface()
{
    delete ui;
}

void ConnectionInterface::actionConnection() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    if (mainWindow != NULL) {
        mainWindow->actionConnection(ui->idLogin->text(), ui->passwordLogin->text()); // On appelle la methode de MainWindow qui gere la connexion
        ui->passwordLogin->setText(""); // On efface le mot de passe
    }
}
