#include "indexprofil.h"
#include "ui_indexprofil.h"

IndexProfil::IndexProfil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IndexProfil)
{
    ui->setupUi(this);
}

IndexProfil::~IndexProfil()
{
    delete ui;
}
