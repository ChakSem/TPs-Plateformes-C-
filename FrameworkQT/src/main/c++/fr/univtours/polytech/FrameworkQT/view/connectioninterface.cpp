#include "connectioninterface.h"
#include "ui_connectioninterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

#include <QStackedWidget>

ConnectionInterface::ConnectionInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::ConnectionInterface)
{
    ui->setupUi(this);
    /*Connexion du bouton de connexion à la méthode de connexion*/
    connect(ui->pushButton, &QPushButton::clicked, this, &ConnectionInterface::actionConnection);
}

ConnectionInterface::~ConnectionInterface()
{
    delete ui;
}
/**
 * Méthode pour se connecter
 * Entrée :
 * Sortie :
 */
void ConnectionInterface::actionConnection()
{
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    if (mainWindow != NULL)
    {
        mainWindow->actionConnection(ui->idLogin->text(), ui->passwordLogin->text()); // On appelle la methode de MainWindow qui gere la connexion
        ui->passwordLogin->setText("");                                               // On efface le mot de passe
    }
}
