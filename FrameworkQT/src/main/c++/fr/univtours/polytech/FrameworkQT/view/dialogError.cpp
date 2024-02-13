#include "dialogpopupok.h"
#include "ui_dialogpopupok.h"

DialogPopUpOk::DialogPopUpOk(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPopUpOk)
{
    ui->setupUi(this);
}

DialogPopUpOk::~DialogPopUpOk()
{
    delete ui;
}
