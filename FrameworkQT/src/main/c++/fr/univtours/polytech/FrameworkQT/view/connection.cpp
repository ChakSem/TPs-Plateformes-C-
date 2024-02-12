#include "connection.h"
#include "mainwindow.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connection)
{
    ui->setupUi(this);

    connect( ui->pushButton, SIGNAL( clicked() ), this, SLOT( pushButtonClicked() ) );
}

Connection::~Connection()
{
    delete ui;
}

void pushButtonClicked() {
    MainWindow::getInstance().getUi()->stackedWidgetCenter;
}
