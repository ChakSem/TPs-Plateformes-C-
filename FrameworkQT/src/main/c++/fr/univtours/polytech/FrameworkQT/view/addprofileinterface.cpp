#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"
#include "../utils/exception.h"
#include "../parserJson/parserjson.h"
#include "../model/data.h"
#include <QMessageBox>
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "mainwindow.h"

AddProfileInterface::AddProfileInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddProfileInterface)
{
    ui->setupUi(this);
    /*On connecte le bouton de création de profil à la méthode actionCreateProfile*/
    connect(ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionCreateProfile);
}

AddProfileInterface::~AddProfileInterface()
{
    delete ui;
}

/**
 * Méthode pour créer un profil
 * Entree :
 * Sortie :
 */
void AddProfileInterface::actionCreateProfile()
{
    try
    {
        /*On récupère les informations du formulaire*/
        QString name = ui->idLogin->text();
        QString profileRightsString = ui->radioButoonReadRight->isChecked() ? "Lecture" : ui->radioButoonReadUpdateRight->isChecked() ? "Lecture/Modification"
                                                                                                                                      : ""; // On recupere les droits du profil
        unsigned int profileRightsValue = ERROR;
        /*On vérifie que tous les champs sont remplis*/
        if (name == "")
        {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        /*On verfie que les droits sont bien renseignés et correspondants a un droit existant*/
        if (profileRightsString == "Lecture")
        {
            profileRightsValue = DROIT_LECTURE;
        }
        else if (profileRightsString == "Lecture/Modification")
        {
            profileRightsValue = DROIT_LECTURE_MODIFICATION;
        }
        else
        {
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);
        }

        /*On crée le profil*/
        Controller::createProfile(name, profileRightsValue);
        MainWindow::messageDialog("Vous avez bien créé le profil", "Information", MESSAGEBOX_OK);

        MainWindow *mainWindow = MainWindow::accessToParent(this);
        if (mainWindow != NULL)
        {
            User *userProfiles = Controller::getUserProfiles();

            mainWindow->returnOnPreviousView();
            mainWindow->openProfiles(userProfiles);
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}
