#include "backbutton.h"
#include "ui_backbutton.h"

BackButton::BackButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackButton)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &BackButton::actionBack);
}

BackButton::~BackButton()
{
    delete ui;
}

void BackButton::actionBack()
{

}
