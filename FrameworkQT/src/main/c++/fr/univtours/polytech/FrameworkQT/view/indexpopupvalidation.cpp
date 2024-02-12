#include "indexpopupvalidation.h"
#include "ui_indexpopupvalidation.h"

indexPopUpValidation::indexPopUpValidation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::indexPopUpValidation)
{
    ui->setupUi(this);
}

indexPopUpValidation::~indexPopUpValidation()
{
    delete ui;
}
