#include "connection.h"
#include "mainwindow.h"
#include "ui_connection.h"

#include <QStackedWidget>



Connection::Connection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connection)
{
    ui->setupUi(this);

    connect( ui->pushButton, SIGNAL( clicked() ), this, SLOT (MainWindow::getInstance().displayDeconnection() ));
}

Connection::~Connection()
{
    delete ui;
}

