#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"

CreationUserInterface::CreationUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationUserInterface)
{
    ui->setupUi(this);
    connect( ui->pushButton, &QPushButton::clicked, this, &CreationUserInterface::actionAddUseer);
}

CreationUserInterface::~CreationUserInterface()
{
    delete ui;
}

void CreationUserInterface::actionAddUseer() {

}
