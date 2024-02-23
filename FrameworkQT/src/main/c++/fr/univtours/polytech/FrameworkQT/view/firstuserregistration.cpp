#include "firstuserregistration.h"
#include "ui_firstuserregistration.h"

firstUserRegistration::firstUserRegistration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::firstUserRegistration)
{
    ui->setupUi(this);
}

firstUserRegistration::~firstUserRegistration()
{
    delete ui;
}
