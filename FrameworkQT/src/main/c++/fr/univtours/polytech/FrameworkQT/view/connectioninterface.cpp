#include "connectioninterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"
#include "ui_connectioninterface.h"

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

// Dans la fonction slot handleButtonClick() de la classe Connection
void ConnectionInterface::actionConnection() {

    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->actionConnection(ui->idLogin->text(), ui->passwordLogin->text()); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }

}
