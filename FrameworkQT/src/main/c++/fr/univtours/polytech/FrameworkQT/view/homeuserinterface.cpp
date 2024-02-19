#include "homeuserinterface.h"
#include "ui_homeuserinterface.h"

homeUserInterface::homeUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::homeUserInterface)
{
    ui->setupUi(this);
}

homeUserInterface::~homeUserInterface()
{
    delete ui;
}
