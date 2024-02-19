#include "creationuserinterface_2.h"
#include "ui_creationuserinterface_2.h"

creationuserinterface::creationuserinterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::creationuserinterface)
{
    ui->setupUi(this);
}

creationuserinterface::~creationuserinterface()
{
    delete ui;
}
