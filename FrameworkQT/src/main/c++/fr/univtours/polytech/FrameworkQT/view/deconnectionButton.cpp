#include "deconnection.h"
#include "ui_deconnection.h"

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
