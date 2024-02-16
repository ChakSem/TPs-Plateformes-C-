#include "deconnectionButton.h"
#include "ui_deconnectionButton.h"

Deconnection::Deconnection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Deconnection)
{
    ui->setupUi(this);

    connect( ui->pushButtonDeconnection, &QPushButton::clicked, this, &Deconnection::actionDeconnection);
}


void Deconnection::actionDeconnection() {

}

Deconnection::~Deconnection()
{
    delete ui;
}
