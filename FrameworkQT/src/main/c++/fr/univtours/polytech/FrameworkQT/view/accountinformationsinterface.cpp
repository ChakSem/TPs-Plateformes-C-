#include "accountinformationsinterface.h"
#include "ui_accountinformationsinterface.h"
#include "../model/data.h"
#include "../utils/exception.h"
#include "../controller/controller.h"

#include "../parseurJson/CparserJson.h"
#include "../utils/Exception.h"
#include <QDebug>

void AccountInformationsInterface::setAccountInformations()
{

    Data& data = Data::getInstance();
    User* user = data.getUserConnected();

    /*On rend les champs non modifiables*/
    ui->myId->setReadOnly(true);
    ui->myRole->setReadOnly(true);
    ui->myLastName->setReadOnly(true);
    ui->myFirstName->setReadOnly(true);

    /*On change la couleur des champs*/
    ui->myLastName->setPalette(Qt::gray);
    ui->myFirstName->setPalette(Qt::gray);
    ui->myRole->setPalette(Qt::gray);
    ui->myId->setPalette(Qt::gray);
    
    ui->myId->setText(user->getId());
    if(data.getAdministrators().contains(user->getId())) {
        ui->myRole->setText("admin");
    }
    else {
        ui->myRole->setText("user");
    }
    ui->myLastName->setText(user->getLastname());
    ui->myFirstName->setText(user->getFirstname());


}
AccountInformationsInterface::AccountInformationsInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountInformationsInterface)
{
    
    ui->setupUi(this);
    setAccountInformations();
}

AccountInformationsInterface::~AccountInformationsInterface()
{
    delete ui;
}

