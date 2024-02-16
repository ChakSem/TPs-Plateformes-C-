#include "profilesInterface.h"
#include "ui_profilesInterface.h"

comboBox::comboBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ComboBox)
{
    ui->setupUi(this);
}

comboBox::~comboBox()
{
    delete ui;
}
