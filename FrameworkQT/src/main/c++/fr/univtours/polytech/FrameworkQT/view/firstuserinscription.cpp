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


void FirstUserInscription::actionAddUser()
{
    try
    {
        QString nom = ui->lastNameUser->text();
        QString prenom = ui->firstNameUser->text();
        QString mdp = ui->passwordLogin->text();
        User *User ;
        unsigned int roleValue = ROLE_USER;
        if (nom.isEmpty() || prenom.isEmpty() || mdp.isEmpty())
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        User = Controller::createUser(nom, prenom, mdp, roleValue);
        QMessageBox::information(this, "Information", "Votre identifiant est : " + User->getId() + " \nVeuillez le conserver précieusement");

        MainWindow *mainWindow = MainWindow::accessToParent(this);

        if (mainWindow != NULL)
        {
            mainWindow->openConnection();
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }

}
