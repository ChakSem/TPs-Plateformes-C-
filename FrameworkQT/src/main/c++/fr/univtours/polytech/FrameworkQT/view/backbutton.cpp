#include "backbutton.h"
#include "ui_backbutton.h"

cancelButton::cancelButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cancelButton)
{
    ui->setupUi(this);
}

cancelButton::~cancelButton()
{
    delete ui;
}
