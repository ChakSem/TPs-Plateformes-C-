#include "deconnectioninterface.h"
#include "ui_deconnectioninterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

DeconnectionInterface::DeconnectionInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::DeconnectionInterface)
{
    ui->setupUi(this);
    /* Connexion du bouton de déconnection à la méthode de déconnection */
    connect(ui->pushButtonDeconnection, &QPushButton::clicked, this, &DeconnectionInterface::actionDeconnection);
}

DeconnectionInterface::~DeconnectionInterface()
{
    delete ui;
}
/**
 * Méthode pour se déconnecter (ça redirige vers la méthode de déconnection de MainWindow)
 * Entrée :
 * Sortie :
 */
void DeconnectionInterface::actionDeconnection()
{
    MainWindow::messageDialog("Voulez-vous vraiment vous déconnecter ?", "Confirmation", MESSAGEBOX_REPLY);
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    if (mainWindow != NULL)
    {
        mainWindow->actionDeconnection();
    }
}
