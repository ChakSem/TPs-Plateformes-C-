#include "dialogError.h"
#include "ui_dialogError.h"

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
