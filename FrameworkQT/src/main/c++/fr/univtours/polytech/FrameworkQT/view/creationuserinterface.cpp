#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"

creationUserInterface::creationUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::creationUserInterface)
{
    ui->setupUi(this);
}

creationUserInterface::~creationUserInterface()
{
    delete ui;
}
