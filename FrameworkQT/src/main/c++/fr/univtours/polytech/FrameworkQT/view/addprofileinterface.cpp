#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"
#include "../utils/exception.h"
#include "../utils/parserjson.h"
#include "../model/data.h"
#include <QMessageBox>




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
        QString profileRights = ui->radioButoonReadRight->isChecked() ? "Lecture" : ui->radioButoonReadUpdateRight->isChecked() ? "Lecture/Modification" : ""; // On recupere les droits du profil
        if (id.isEmpty() || profileRights.isEmpty()) {
            throw Exception(ERREUR_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
        }
        if (profileRights == "Lecture") {
            profileRights = "LECTURE";
        } else if (profileRights == "Lecture/Modification") {
            profileRights = "LECTURE_MODIFICATION";
        } else {
            throw Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);
        }
        Data data;
        CparserJson::saveData(data);
        Profile profile(id, profileRights);
        data.addProfile(profile);
        CparserJson::updateData(data);
        QMessageBox::information(this, "Succes", "Profil cree avec succes");
    }
    catch (Exception e) {
        e.EXCAffichageErreur();
    }
    
}
