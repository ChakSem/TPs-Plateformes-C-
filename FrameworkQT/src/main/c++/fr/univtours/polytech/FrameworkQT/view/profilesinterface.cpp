#include "profilesinterface.h"
#include "ui_profilesinterface.h"

ProfilesInterface::ProfilesInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &ProfilesInterface::actionAddInterface);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &ProfilesInterface::actionDeleteInterface);
    connect( ui->pushButtonManage, &QPushButton::clicked, this, &ProfilesInterface::actionManageInterface);
    connect( ui->pushButtonUpdate, &QPushButton::clicked, this, &ProfilesInterface::actionUpdateInterface);
}

ProfilesInterface::~ProfilesInterface()
{
    delete ui;
}

void ProfilesInterface::actionAddInterface() {

}

void ProfilesInterface::actionDeleteInterface() {

}

void ProfilesInterface::actionManageInterface() {

}

void ProfilesInterface::actionUpdateInterface() {

}

