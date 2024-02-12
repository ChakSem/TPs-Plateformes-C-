#include "indexPopUpOk.h"
#include "ui_indexPopUpOk.h"

indexPopUpChampsManquants::indexPopUpChampsManquants(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::indexPopUpChampsManquants)
{
    ui->setupUi(this);
}

indexPopUpChampsManquants::~indexPopUpChampsManquants()
{
    delete ui;
}
