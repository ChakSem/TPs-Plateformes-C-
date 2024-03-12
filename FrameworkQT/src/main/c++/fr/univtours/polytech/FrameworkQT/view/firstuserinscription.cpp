#include "firstuserinscription.h"
#include "ui_firstuserinscription.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "../model/user.h"
#include "../view/mainwindow.h"
#include <QMessageBox>

FirstUserInscription::FirstUserInscription(QWidget *parent)
    : QWidget(parent), ui(new Ui::FirstUserInscription)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &FirstUserInscription::actionAddUser);
}

FirstUserInscription::~FirstUserInscription()
{
    delete ui;
}

/**
 * Méthode pour ajouter un utilisateur
 * Entrée :
 * Sortie :
 */
void FirstUserInscription::actionAddUser()
{
    try
    {
        /* On récupère les informations */
        QString nom = ui->lastNameUser->text();
        QString prenom = ui->firstNameUser->text();
        QString mdp = ui->passwordLogin->text();
        User *User; // On crée un utilisateur
        unsigned int roleValue = ROLE_USER;
        if (nom.isEmpty() || prenom.isEmpty() || mdp.isEmpty())
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS); // on vérifie que tous les champs sont remplis
        }
        User = Controller::createUser(nom, prenom, mdp, roleValue); // On crée l'utilisateur dans la base de données
        MainWindow::messageDialog("Votre identifiant est : " + User->getId() + " \nVeuillez le conserver précieusement", "Information", MESSAGEBOX_OK);
        MainWindow *mainWindow = MainWindow::accessToParent(this);

        /* S'il n'y a pas eu d'erreur */
        if (mainWindow != NULL)
        {
            mainWindow->openConnection();
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}
