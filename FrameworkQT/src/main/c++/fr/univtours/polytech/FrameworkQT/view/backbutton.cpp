#include "backbutton.h"
#include "ui_backbutton.h"

BackButton::BackButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackButton)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &BackButton::backButtonClicked);
}
void BackButton::backButtonClicked()
{
    
}



BackButton::~BackButton()
{
    delete ui;
}
