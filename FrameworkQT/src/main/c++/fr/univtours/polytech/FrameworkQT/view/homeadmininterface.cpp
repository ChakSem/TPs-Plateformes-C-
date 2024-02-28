#include "homeadmininterface.h"
#include "ui_homeadmininterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

HomeAdminInterface::HomeAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeAdminInterface)
{
    ui->setupUi(this);
    /* Connexion des boutons aux méthodes(Redirecction vers les informations du compte, les bases de données, les profils et les utilisateurs) */
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeAdminInterface::actionAccount);
    connect( ui->pushButtonDatabase, &QPushButton::clicked, this, &HomeAdminInterface::actionDatabase);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeAdminInterface::actionProfile);
    connect( ui->pushButtonUser, &QPushButton::clicked, this, &HomeAdminInterface::actionUser);
}

HomeAdminInterface::~HomeAdminInterface()
{
    delete ui;
}

/**
 * Permet de rediriger vers la page de gestion du compte
 * Entrée :
 * Sortie :
 */
void HomeAdminInterface::actionAccount() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openAccount(); // On ouvre l'interface de visionage du compte
    }
}

/**
 * Permet de rediriger vers la page de gestion des bases de données
 * Entrée :
 * Sortie :
 */
void HomeAdminInterface::actionDatabase() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {

        mainWindow->openDatabases(); // On ouvre l'interface pour les base de données
    }
}

/**
 * Permet de rediriger  vers la page de gestion des profils
 * Entrée :
 * Sortie :
 */
void HomeAdminInterface::actionProfile() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openMyProfiles(); // On ouvre l'interface des profils pour l'utilisateur connecté
    }
}

/**
 * Permet de rediriger vers la page de gestion des utilisateurs
 * Entrée :
 * Sortie :
 */
void HomeAdminInterface::actionUser() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openUsers(); // On ouvre l'interface de gestion des utilisateurs
    }
}
