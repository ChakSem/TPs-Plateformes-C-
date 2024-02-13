#include "tabledatausers.h"
#include "ui_tabledatausers.h"

indexTableDataUsers::indexTableDataUsers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::indexTableDataUsers)
{
    ui->setupUi(this);
}

indexTableDataUsers::~indexTableDataUsers()
{
    delete ui;
}
