#include "ui_mainconnection.h"
#include "mainconnection.h"
#include <QMainWindow>>

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
