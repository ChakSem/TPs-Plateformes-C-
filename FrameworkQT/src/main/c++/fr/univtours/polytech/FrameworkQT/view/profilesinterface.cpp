#include "profilesinterface.h"
#include "ui_profilesinterface.h"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "../model/profile.h"
#include "mainwindow.h"
#include <QMessageBox>

/**
 * Methode qui permet d'initialiser le comboBox avec les profils de l'utilisateur
 * Entrée :
 * Sortie :
 */
void ProfilesInterface::initializeComboBox() {
    ui->comboBoxProfiles->clear(); // On vide le comboBox

    /* On réinitialise par rapport aux données de Data */
    for(Profile* profile : Controller::getUserProfiles()->getProfiles()) {
            ui->comboBoxProfiles->addItem(profile->getTitle());
        }
}

ProfilesInterface::ProfilesInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesInterface)
{
    ui->setupUi(this);
    /*On connecte les boutons aux méthodes (ajout, suppression, gestion)*/
    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &ProfilesInterface::actionAddInterface);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &ProfilesInterface::actionDeleteInterface);
    connect( ui->pushButtonManage, &QPushButton::clicked, this, &ProfilesInterface::actionManageInterface);
}

ProfilesInterface::~ProfilesInterface()
{
    delete ui;
}

/**
 *  Methode qui permet de rediriger vers l'interface d'ajout de profil
 *  Entrée :
 *  Sortie :
 */
void ProfilesInterface::actionAddInterface() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openAddProfiles();
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}

/**
 * Methode qui permet de supprimer un profil
 * Entrée :
 * Sortie :
 */
void ProfilesInterface::actionDeleteInterface() {
    try {
        /*On récupère le profil selectionné*/
        QString profileTitle = ui->comboBoxProfiles->currentText();
        Profile* profile = Controller::getProfileByTitle(profileTitle);
        if (profile != NULL) {
                /*On demande confirmation de la suppression*/
                if (MainWindow::messageDialog("Voulez-vous vraiment supprimer le profil " + profileTitle + " ?", "Confirmation", MESSAGEBOX_REPLY)) {
                    Controller::deleteProfile(Controller::getUserProfiles()->getId(), profileTitle);
                    initializeComboBox();
                }
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}

         

/**
 * Methode qui permet de rediriger vers l'interface de gestion de profil (ou l'on va gerer les connexions avec les BDDs)
 * Entrée :
 * Sortie :
 */
void ProfilesInterface::actionManageInterface() {
    QString profileTitle = ui->comboBoxProfiles->currentText();
    Profile* profile = Controller::getProfileByTitle(profileTitle);
    
    if (profile != NULL) {
        MainWindow *mainWindow = MainWindow::accessToParent(this);

        if (mainWindow != NULL) {
            mainWindow->openDatabaseInterface(profile);
        }
    }
}
