#include "homeadmininterface.h"
#include "ui_homeadmininterface.h"

homeAdminInterface::homeAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::homeAdminInterface)
{
    ui->setupUi(this);
}

homeAdminInterface::~homeAdminInterface()
{
    delete ui;
}
