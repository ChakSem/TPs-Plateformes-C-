#include "indextabledatausers.h"
#include "ui_indextabledatausers.h"

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
