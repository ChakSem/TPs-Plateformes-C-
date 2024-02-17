#include "gestionutilisateur.h"
#include "ui_gestionutilisateur.h"

GestionUtilisateur::GestionUtilisateur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GestionUtilisateur)
{
    ui->setupUi(this);
}

GestionUtilisateur::~GestionUtilisateur()
{
    delete ui;
}
