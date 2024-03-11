#include "databaseinterface.h"
#include "ui_databaseinterface.h"

DatabaseInterface::DatabaseInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseInterface)
{
    ui->setupUi(this);
}

DatabaseInterface::~DatabaseInterface()
{
    delete ui;
}
