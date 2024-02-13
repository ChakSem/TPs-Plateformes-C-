#include "dialogpopupvalidation.h"
#include "ui_dialogpopupvalidation.h"

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
