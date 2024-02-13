#include "combobox.h"
#include "ui_combobox.h"

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
