#include "accountinformationsinterface.h"
#include "ui_accountinformationsinterface.h"
#include "../model/data.h"
#include "../utils/exception.h"
#include "../controller/controller.h"

#include "../parseurJson/parserJson.h"
#include "../utils/Exception.h"
#include <QDebug>

/**
 * Méthode pour mettre à jour les labels avec les informations de l'utilisateur connecté
 * Entrée : widget, QWidget* : le QWidget qui appelle cette méthode
 * Sortie : MainWindow*
 */
void AccountInformationsInterface::setAccountInformations()
{
    Data &data = Data::getInstance();
    User *user = data.getUserConnected();

    /*On rend les champs non modifiables*/
    ui->myId->setReadOnly(true);
    ui->myRole->setReadOnly(true);
    ui->myLastName->setReadOnly(true);
    ui->myFirstName->setReadOnly(true);

    ui->myId->setText(user->getId());

    /*On regarde si l'utilisateur est un admin en vérifiant si son id est dans la liste des administrateurs*/
    if (data.getAdministrators().contains(user->getId()))
    {
        ui->myRole->setText("admin");
    }
    else
    {
        ui->myRole->setText("user");
    }
    ui->myLastName->setText(user->getLastname());
    ui->myFirstName->setText(user->getFirstname());
}
AccountInformationsInterface::AccountInformationsInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::AccountInformationsInterface)
{

    ui->setupUi(this);
}

AccountInformationsInterface::~AccountInformationsInterface()
{
    delete ui;
}
