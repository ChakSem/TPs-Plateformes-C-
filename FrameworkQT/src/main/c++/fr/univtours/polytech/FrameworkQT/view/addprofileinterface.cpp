#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"
#include "../utils/exception.h"
#include "../parseurJson/CparserJson.h"
#include "../model/data.h"
#include <QMessageBox>
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "mainwindow.h"


AddProfileInterface::AddProfileInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddProfileInterface)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionCreateProfile);
}

AddProfileInterface::~AddProfileInterface()
{
    delete ui;
}


void AddProfileInterface::actionCreateProfile() {
    try {
        QString name = ui->idLogin->text();
        QString profileRightsString = ui->radioButoonReadRight->isChecked() ? "Lecture" : ui->radioButoonReadUpdateRight->isChecked() ? "Lecture/Modification" : ""; // On recupere les droits du profil

        unsigned int profileRightsValue = ERROR;
        if (name == "") {
            throw new Exception(ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        if (profileRightsString == "Lecture") {
            profileRightsValue = DROIT_LECTURE;
        } else if (profileRightsString == "Lecture/Modification") {
            profileRightsValue = DROIT_LECTURE_MODIFICATION;
        } else {
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);
        }

        Controller::createProfile(name, profileRightsValue);

        Controller::closeUserProfiles();

        MainWindow *mainWindow = MainWindow::accessToParent(this);
        if (mainWindow != NULL) {
            mainWindow->returnOnPreviousView();
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
    
}
