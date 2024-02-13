#include "deconnectionButton.h"
#include "ui_deconnectionButton.h"

Deconnection::Deconnection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Deconnection)
{
    ui->setupUi(this);
}

Deconnection::~Deconnection()
{
    delete ui;
}
