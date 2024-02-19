#include "creationuserinterface.h"
#include "ui_creationuserinterface.h"

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
