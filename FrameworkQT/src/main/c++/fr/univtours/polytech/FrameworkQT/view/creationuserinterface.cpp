#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "../view/mainwindow.h"

CreationUserInterface::CreationUserInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreationUserInterface)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &CreationUserInterface::actionAddUser);
}

CreationUserInterface::~CreationUserInterface()
{
    delete ui;
}

/**
 * Méthode pour ajouter un utilisateur ou un administrateur dans la base de données
 * Entrée :
 * Sortie :
 */
void CreationUserInterface::actionAddUser()
{
    try
    {
        /* Récupération des informations */
        QString nom = ui->lastNameUser->text();
        QString prenom = ui->firstNameUser->text();
        QString mdp = ui->passwordLogin->text();

        unsigned int roleValue = ui->radioButtonIsAdmin->isChecked() ? ROLE_ADMIN : ROLE_USER; // on récupère le role de l'utilisateur
        if (nom == "" || mdp == "")
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }

        /* On crée l'utilisateur dans la base de données */
        User *newUser = Controller::createUser(prenom, nom, mdp, roleValue);
        MainWindow::messageDialog("L'utilisateur a bien été créé", "Information", MESSAGEBOX_OK);
        MainWindow *mainWindow = MainWindow::accessToParent(this);

        /* S'il n'y a pas eu d'erreur */
        if (mainWindow != NULL)
        {
            /* On met à jour la table des utilisateurs */
            mainWindow->updateTableView(newUser);
            mainWindow->returnOnPreviousView(); // On ouvre l'interface des profils pour l'utilisateur connecté
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}
