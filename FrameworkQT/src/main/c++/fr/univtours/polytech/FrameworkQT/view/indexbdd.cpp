#include "indexbdd.h"
#include "ui_indexbdd.h"

IndexBdd::IndexBdd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IndexBdd)
{
    ui->setupUi(this);
}

IndexBdd::~IndexBdd()
{
    delete ui;
}
