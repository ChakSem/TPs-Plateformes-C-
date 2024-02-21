#include "addprofileadmininterface.h"
#include "ui_addprofileadmininterface.h"

addProfileAdminInterface::addProfileAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addProfileAdminInterface)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionCreateAdminProfile);
}

void addProfileAdminInterface::actionCreateAdminProfile() {
     try {
        QString name = ui->idLogin->text();
        QString profileRights = "LECTURE_MODIFICATION_ECRITURE_SUPPRESSION"; 
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

addProfileAdminInterface::~addProfileAdminInterface()
{
    delete ui;
}
