#include "connectionInterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"
#include "ui_connectionInterface.h"

#include <QStackedWidget>



Connection::Connection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connection)
{
    ui->setupUi(this);

    connect( ui->pushButton, &QPushButton::clicked, this, &Connection::actionConnection);
}

// Dans la fonction slot handleButtonClick() de la classe Connection
void Connection::actionConnection() {

    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->displayDeconnection(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(1);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }

}

Connection::~Connection()
{
    delete ui;
}

