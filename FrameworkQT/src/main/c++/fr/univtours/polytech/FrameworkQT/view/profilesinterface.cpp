#include "profilesinterface.h"
#include "ui_profilesinterface.h"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "../model/profile.h"
#include "mainwindow.h"

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

    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &ProfilesInterface::actionAddInterface);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &ProfilesInterface::actionDeleteInterface);
    connect( ui->pushButtonManage, &QPushButton::clicked, this, &ProfilesInterface::actionManageInterface);
}

ProfilesInterface::~ProfilesInterface()
{
    delete ui;
}

//Methode qui permet de rediriger vers l'interface d'ajout de profil
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
    }
}



//methode qui permet de supprimer directement un profil 
void ProfilesInterface::actionDeleteInterface() {
    try {
        QString profileTitle = ui->comboBoxProfiles->currentText();
        Profile* profile = Controller::getUserProfiles()->getProfileByTitle(profileTitle);
        if (profile != NULL) {
            // //on demande une confirmation
            // QMessageBox::StandardButton reply;
            // reply = QMessageBox::question(this, "Suppression de profil", "Etes-vous sûr de vouloir supprimer le profil " + profileTitle + " ?", QMessageBox::Yes|QMessageBox::No);
            // if (reply == QMessageBox::No) {
            //     return;
            // }
            Controller::deleteProfile(profile->getUser()->getId(), profileTitle);
            initializeComboBox();
        }
        else {
            throw new Exception(ERREUR_AUCUN_PROFIL_CORRESPONDANT);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }


}
//methode qui permet de rediriger vers l'interface de gestion de profil (ou l'on va gerer les connexions avec les BDDs)
void ProfilesInterface::actionManageInterface() {
    try {
        QString profileTitle = ui->comboBoxProfiles->currentText();
        Profile* profile = Controller::getUserProfiles()->getProfileByTitle(profileTitle);
        if (profile != NULL) {
            QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
            MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
            if (mainWindow) {
                mainWindow->openManageProfile(profile)
            } else {
                throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
            }
        }
        else {
            throw new Exception(ERREUR_AUCUN_PROFIL_CORRESPONDANT);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }

}
