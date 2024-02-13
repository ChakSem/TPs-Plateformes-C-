#include "indexcreateupdatedelete.h"
#include "ui_indexcreateupdatedelete.h"

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
