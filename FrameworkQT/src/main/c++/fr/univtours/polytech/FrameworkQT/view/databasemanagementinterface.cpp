#include "databasemanagementinterface.h"
#include "ui_databasemanagementinterface.h"

DatabaseManagementInterface::DatabaseManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseManagementInterface)
{
    ui->setupUi(this);
}

DatabaseManagementInterface::~DatabaseManagementInterface()
{
    delete ui;
}
