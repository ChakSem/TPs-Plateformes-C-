#include "mainconnection.h"
#include "ui_mainconnection.h"

MainConnection::MainConnection(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainConnection)
{
    ui->setupUi(this);
}

MainConnection::~MainConnection()
{
    delete ui;
}
