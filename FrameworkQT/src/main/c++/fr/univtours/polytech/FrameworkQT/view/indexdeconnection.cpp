#include "indexdeconnection.h"
#include "ui_indexdeconnection.h"

IndexDeconnection::IndexDeconnection(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IndexDeconnection)
{
    ui->setupUi(this);
}

IndexDeconnection::~IndexDeconnection()
{
    delete ui;
}
