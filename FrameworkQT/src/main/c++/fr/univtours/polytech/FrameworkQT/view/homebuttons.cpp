#include "homebuttons.h"
#include "ui_homebuttons.h"

HomeButtons::HomeButtons(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeButtons)
{
    ui->setupUi(this);
}

HomeButtons::~HomeButtons()
{
    delete ui;
}
