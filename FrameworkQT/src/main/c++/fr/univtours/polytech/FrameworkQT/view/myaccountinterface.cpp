#include "myaccountinterface.h"
#include "ui_myaccountinterface.h"

MyAccountInterface::MyAccountInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyAccountInterface)
{
    ui->setupUi(this);
}

MyAccountInterface::~MyAccountInterface()
{
    delete ui;
}
