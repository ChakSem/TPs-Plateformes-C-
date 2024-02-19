#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"

AddProfileInterface::AddProfileInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddProfileInterface)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionCreateProfile);
}

AddProfileInterface::~AddProfileInterface()
{
    delete ui;
}

void AddProfileInterface::actionCreateProfile() {

}
