#include "homebuttons.h"
#include "ui_homebuttons.h"

HomeButtons::HomeButtons(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeButtons)
{
    ui->setupUi(this);

    connect( ui->profileButton, &QPushButton::clicked, this, &HomeButtons::actionProfiles);
    connect( ui->accountButton, &QPushButton::clicked, this, &HomeButtons::actionAccount);
    connect( ui->usersButton, &QPushButton::clicked, this, &HomeButtons::actionUsersManagement);
}


void HomeButtons::actionProfiles() {

}
void HomeButtons::actionAccount() {

}
void HomeButtons::actionUsersManagement() {

}

HomeButtons::~HomeButtons()
{
    delete ui;
}
