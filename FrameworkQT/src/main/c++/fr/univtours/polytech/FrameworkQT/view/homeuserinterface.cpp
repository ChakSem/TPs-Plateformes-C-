#include "homeuserinterface.h"
#include "ui_homeuserinterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"


HomeUserInterface::HomeUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeUserInterface)
{
    ui->setupUi(this);
    /* Connexion des boutons aux méthodes(Redirecction vers les informations du compte et les profils) */
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeUserInterface::actionAccount);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeUserInterface::actionProfile);
}


HomeUserInterface::~HomeUserInterface()
{
    delete ui;
}

/**
 * Méthode pour rediriger vers les informations du compte
 * Entree :  
 * Sortie : 
 */
void HomeUserInterface::actionAccount() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openAccount(); // On ouvre l'interface de visionage du compte
    }
}
/**
 * Méthode pour rediriger vers les profils
 * Entree :  
 * Sortie : 
 */
void HomeUserInterface::actionProfile() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openMyProfiles(); // On ouvre l'interface des profils pour l'utilisateur connecté

    }
}
