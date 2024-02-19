#include "dialogValidation.h"
#include "ui_dialogValidation.h"

DialogPopUpValidation::DialogPopUpValidation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPopUpValidation)
{
    ui->setupUi(this);
}

DialogPopUpValidation::~DialogPopUpValidation()
{
    delete ui;
}
