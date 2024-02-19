#include "usermanagementinterface.h"
#include "ui_usermanagementinterface.h"

UserManagementInterface::UserManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserManagementInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &UserManagementInterface::actionAddUser);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &UserManagementInterface::actionDeleteUser);
    connect( ui->pushButtonUpdate, &QPushButton::clicked, this, &UserManagementInterface::actionUpdateUser);
}

UserManagementInterface::~UserManagementInterface()
{
    delete ui;
}

void UserManagementInterface::actionAddUser() {

}

void UserManagementInterface::actionDeleteUser() {

}

void UserManagementInterface::actionUpdateUser() {

}


