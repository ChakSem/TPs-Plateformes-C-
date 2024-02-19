#include "dialogvalidation.h"
#include "ui_dialogvalidation.h"

DialogValidation::DialogValidation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogValidation)
{
    ui->setupUi(this);
    connect( ui->pushButtonCancel, &QPushButton::clicked, this, &DialogValidation::actionCancel);
    connect( ui->pushButtonValidate, &QPushButton::clicked, this, &DialogValidation::actionValidate);
}

DialogValidation::~DialogValidation()
{
    delete ui;
}

void DialogValidation::actionCancel() {

}

void DialogValidation::actionValidate() {

}
