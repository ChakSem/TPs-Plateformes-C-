#include "homeadmininterface.h"
#include "ui_homeadmininterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

HomeAdminInterface::HomeAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeAdminInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeAdminInterface::actionAccount);
    connect( ui->pushButtonDatabase, &QPushButton::clicked, this, &HomeAdminInterface::actionDatabase);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeAdminInterface::actionProfile);
    connect( ui->pushButtonUser, &QPushButton::clicked, this, &HomeAdminInterface::actionUser);
}

HomeAdminInterface::~HomeAdminInterface()
{
    delete ui;
}

void HomeAdminInterface::actionAccount() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openAccount(); // On ouvre l'interface de visionage du compte
    }
}

void HomeAdminInterface::actionDatabase() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {

        mainWindow->openDatabases(); // On ouvre l'interface pour les base de données
    }
}

void HomeAdminInterface::actionProfile() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openMyProfiles(); // On ouvre l'interface des profils pour l'utilisateur connecté
    }
}

void HomeAdminInterface::actionUser() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openUsers(); // On ouvre l'interface de gestion des utilisateurs
    }
}
