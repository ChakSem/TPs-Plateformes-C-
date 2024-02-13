#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"

addProfileInterface::addProfileInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addProfileInterface)
{
    ui->setupUi(this);
}

addProfileInterface::~addProfileInterface()
{
    delete ui;
}
