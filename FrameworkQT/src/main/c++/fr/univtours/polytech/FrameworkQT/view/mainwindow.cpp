#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID);
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);

    previousPage = MAINWIDGET_CONNECTION;
    
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
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VISIBLE); // On affiche le bouton deconnexion
}

void MainWindow::actionConnection(QString id, QString password) {
    unsigned int success = Controller::connection(id, password);
    if (success == SUCCESS_ADMIN) {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_ADMIN); // Access au Home Admin
        displayDeconnection();

        previousPage = MAINWIDGET_HOME_ADMIN; // On initialise pour le bouton de retour
    } else {
        if (success == SUCCESS_USER) {
            ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_USER); // Access au Home User
            displayDeconnection();

            previousPage = MAINWIDGET_HOME_USER; // On initialise pour le bouton de retour
        } else {

            // TODO : Gerer cas echec de la connexion
        }
    }
}

void MainWindow::actionDeconnection() {
    Controller::deconnection(); // On gere la deconnexion pour les donnees
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID); // On fait disparaitre le bouton deconnexion

    previousPage = MAINWIDGET_CONNECTION;
}

void MainWindow::openUsers() {
    ui->MainWidget->setCurrentIndex(1); // Access à la page de gestion des utilisateurs
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);
}

void MainWindow::openAccount() {
    // TODO : visualiser compte (optionnel)
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
}

void MainWindow::openProfiles() {
    // TODO : Gerer la recuperation de l'utilisateur dont on visione les profils
    ui->MainWidget->setCurrentIndex(MAINWIDGET_PROFILES); // Access à la page de gestion des profils
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    Controller::openUserProfilesForCurrentUser();
}

void MainWindow::openDatabases() {
    // TODO : partie 2
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
}

void MainWindow::returnOnPreviousView() {
    ui->MainWidget->setCurrentIndex(previousPage);

    switch(previousPage) {
    case 1:
        Controller::closeUserProfiles();
        // TODO : Gerer changer le retour sur HomeAdmin ou HomeUser, en fonction du type d'utilisateur connecte
        break;
    case 5:
    case 6:
        ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);
        Controller::closeUserProfiles();
        break;
    }
}

