#include "homeuserinterface.h"
#include "ui_homeuserinterface.h"

HomeUserInterface::HomeUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeUserInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeUserInterface::actionAccount);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeUserInterface::actionProfile);
}

HomeUserInterface::~HomeUserInterface()
{
    delete ui;
}

void HomeUserInterface::actionAccount() {

}
void HomeUserInterface::actionProfile() {

}
