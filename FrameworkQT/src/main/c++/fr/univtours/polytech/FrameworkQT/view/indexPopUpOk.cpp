#include "indexPopUpOk.h"
#include "ui_indexPopUpOk.h"

indexPopUpOk::indexPopUpOk(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::indexPopUpOk)
{
    ui->setupUi(this);
}

indexPopUpOk::~indexPopUpOk()
{
    delete ui;
}


    // void static setText(QString text);
void indexPopUpOk::setText(QString text)
{
    ui->label->setText(text);
}






void indexPopUpOk::show()
{
    this->exec();
}
