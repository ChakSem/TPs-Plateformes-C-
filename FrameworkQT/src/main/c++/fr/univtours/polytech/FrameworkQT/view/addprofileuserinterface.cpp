#include "addprofileuserinterface.h"
#include "ui_addprofileuserinterface.h"

addProfileUserInterface::addProfileUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addProfileUserInterface)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionCreateUserProfile);
    
}

void addProfileAdminInterface::actionCreateAdminProfile() {
     try {
        QString name = ui->idLogin->text();
        QString profileRights = "LECTURE"; 
        if (id.isEmpty() ) {
            throw Exception(ERREUR_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS);
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
addProfileUserInterface::~addProfileUserInterface()
{
    delete ui;
}
