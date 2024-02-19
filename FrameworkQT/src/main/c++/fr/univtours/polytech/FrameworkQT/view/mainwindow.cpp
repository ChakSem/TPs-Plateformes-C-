#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
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

void MainWindow::actionConnection(QString id, QString password) {
    unsigned int success = Controller::connection(id, password);
    if (success == SUCCESS_ADMIN) {
        ui->MainWidget->setCurrentIndex(5); // Access au Home Admin
        displayDeconnection();
    } else {
        if (success == SUCCESS_USER) {
            ui->MainWidget->setCurrentIndex(6); // Access au Home User
            displayDeconnection();
        } else {

            // TODO : Gerer cas echec de la connexion
        }
    }
}

void MainWindow::actionDeconnection() {
    Controller::Deconnection();
    ui->MainWidget->setCurrentIndex(0);
    ui->DeconnectionWidget->setCurrentIndex(1); // On fait disparaitre le bouton deconnexion
}

