#include "usermanagementinterface.h"
#include "ui_usermanagementinterface.h"

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
