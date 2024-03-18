#include "databassevisualisationinterface.h"
#include "ui_databassevisualisationinterface.h"


void DatabasseVisualisationInterface::initializeTableWidget() {

}

DatabasseVisualisationInterface::DatabasseVisualisationInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabasseVisualisationInterface)
{
    ui->setupUi(this);
}

DatabasseVisualisationInterface::~DatabasseVisualisationInterface()
{
    delete ui;
}
