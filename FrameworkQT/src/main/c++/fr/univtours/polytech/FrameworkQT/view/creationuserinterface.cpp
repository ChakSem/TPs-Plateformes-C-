#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"
#include "../controller/controller.h"
#include "../utils/exception.h"

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

void CreationUserInterface::actionAddUser()
{
    try
    {
        QString nom = ui->lastNameUser->text();
        QString prenom = ui->firstNameUser->text();
        QString mdp = ui->passwordLogin->text();
        unsigned int roleValue = ui->radioButtonIsAdmin->isChecked() ? ROLE_ADMIN : ROLE_USER;
        if (nom == "" || mdp == "")
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        Controller::createUser(prenom, nom, mdp, roleValue);
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}
