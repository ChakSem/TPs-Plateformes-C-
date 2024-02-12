#include "indexhomeadmin.h"
#include "ui_indexhomeadmin.h"

indexHomeAdmin::indexHomeAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::indexHomeAdmin)
{
    ui->setupUi(this);
}

indexHomeAdmin::~indexHomeAdmin()
{
    delete ui;
}
