#include "firstuserinscription.h"
#include "ui_firstuserinscription.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "../view/mainwindow.h"

FirstUserInscription::FirstUserInscription(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstUserInscription)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &FirstUserInscription::actionAddUser);
}

FirstUserInscription::~FirstUserInscription()
{
    delete ui;
}

void FirstUserInscription::actionAddUser()
{
    try
    {
        QString nom = ui->lastNameUser->text();
        QString prenom = ui->firstNameUser->text();
        QString mdp = ui->passwordLogin->text();
        unsigned int roleValue = ROLE_USER;
        if (nom.isEmpty() || prenom.isEmpty() || mdp.isEmpty())
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        Controller::createUser(prenom, nom, mdp, roleValue);

        MainWindow *mainWindow = MainWindow::accessToParent(this);

        if (mainWindow != NULL) {
            mainWindow->openConnection();
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}
