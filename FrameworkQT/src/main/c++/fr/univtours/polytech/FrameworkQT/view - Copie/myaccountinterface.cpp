#include "myaccountinterface.h"
#include "ui_myaccountinterface.h"

myaccountinterface::myaccountinterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myaccountinterface)
{
    ui->setupUi(this);
}

myaccountinterface::~myaccountinterface()
{
    delete ui;
}
