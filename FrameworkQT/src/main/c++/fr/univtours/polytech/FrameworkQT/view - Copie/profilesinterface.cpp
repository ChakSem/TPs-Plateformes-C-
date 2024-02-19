#include "profilesInterface.h"
#include "ui_profilesInterface.h"

profilesInterface::profilesInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profilesInterface)
{
    ui->setupUi(this);
}

profilesInterface::~profilesInterface()
{
    delete ui;
}
