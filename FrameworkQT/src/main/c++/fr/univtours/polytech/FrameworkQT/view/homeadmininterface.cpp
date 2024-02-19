#include "homeadmininterface.h"
#include "ui_homeadmininterface.h"

HomeAdminInterface::HomeAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeAdminInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeAdminInterface::actionAccount);
    connect( ui->pushButtonDatabase, &QPushButton::clicked, this, &HomeAdminInterface::actionDatabase);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeAdminInterface::actionProfile);
    connect( ui->pushButtonUser, &QPushButton::clicked, this, &HomeAdminInterface::actionUser);
}

HomeAdminInterface::~HomeAdminInterface()
{
    delete ui;
}

void HomeAdminInterface::actionAccount() {

}

void HomeAdminInterface::actionDatabase() {

}

void HomeAdminInterface::actionProfile() {

}

void HomeAdminInterface::actionUser() {

}
