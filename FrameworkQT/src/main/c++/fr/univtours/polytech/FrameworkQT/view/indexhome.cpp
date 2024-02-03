#include "indexhome.h"
#include "ui_indexhome.h"

IndexHome::IndexHome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IndexHome)
{
    ui->setupUi(this);
}

IndexHome::~IndexHome()
{
    delete ui;
}
