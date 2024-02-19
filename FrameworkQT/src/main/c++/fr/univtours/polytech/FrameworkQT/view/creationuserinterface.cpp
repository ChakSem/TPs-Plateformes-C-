#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"

CreationUserInterface::CreationUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationUserInterface)
{
    ui->setupUi(this);
}

CreationUserInterface::~CreationUserInterface()
{
    delete ui;
}
