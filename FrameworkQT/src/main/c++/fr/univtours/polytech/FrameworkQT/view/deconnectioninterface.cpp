#include "deconnectioninterface.h"
#include "ui_deconnectioninterface.h"

DeconnectionInterface::DeconnectionInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeconnectionInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonDeconnection, &QPushButton::clicked, this, &DeconnectionInterface::actionDeconnection);
}

DeconnectionInterface::~DeconnectionInterface()
{
    delete ui;
}

void DeconnectionInterface::actionDeconnection() {

}
