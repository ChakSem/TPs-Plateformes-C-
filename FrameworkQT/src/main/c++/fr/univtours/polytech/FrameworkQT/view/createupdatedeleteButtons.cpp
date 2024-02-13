#include "createupdatedeleteButtons.h"
#include "ui_createupdatedeleteButtons.h"

indexCreateUpdateDelete::indexCreateUpdateDelete(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::indexCreateUpdateDelete)
{
    ui->setupUi(this);
}

indexCreateUpdateDelete::~indexCreateUpdateDelete()
{
    delete ui;
}
