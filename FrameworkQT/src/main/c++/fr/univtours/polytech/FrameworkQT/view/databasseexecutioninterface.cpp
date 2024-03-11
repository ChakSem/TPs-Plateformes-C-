#include "databasseexecutioninterface.h"
#include "ui_databasseexecutioninterface.h"

DatabasseExecutionInterface::DatabasseExecutionInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabasseExecutionInterface)
{
    ui->setupUi(this);
}

DatabasseExecutionInterface::~DatabasseExecutionInterface()
{
    delete ui;
}
