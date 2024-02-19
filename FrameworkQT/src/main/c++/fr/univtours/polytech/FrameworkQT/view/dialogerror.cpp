#include "dialogerror.h"
#include "ui_dialogerror.h"

DialogError::DialogError(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogError)
{
    ui->setupUi(this);
    connect( ui->pushButtonOk, &QPushButton::clicked, this, &DialogError::actionError);

}

DialogError::~DialogError()
{
    delete ui;
}

void DialogError::actionError() {

}
