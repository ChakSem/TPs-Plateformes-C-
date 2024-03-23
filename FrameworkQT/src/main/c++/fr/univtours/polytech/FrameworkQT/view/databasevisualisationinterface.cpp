#include "databasevisualisationinterface.h"
#include "ui_databasevisualisationinterface.h"
#include "../utils/exception.h"
#include "../parseurSqlite/cparsersqlite.h"
#include "../controller/controller.h"


void DatabaseVisualisationInterface::initializeTableWidget(QString tableName) {
    ui->tableWidget->clear();

    QList<QString>* liste = Controller::getOpenedDatabase()->parseDatabase(tableName);
    for (int i = 0; i < liste->size(); i ++)
        ui->tableWidget->setItem(1, 1, new QTableWidgetItem((*liste)[i]));

    delete liste;
}

DatabaseVisualisationInterface::DatabaseVisualisationInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseVisualisationInterface)
{
    ui->setupUi(this);
}

DatabaseVisualisationInterface::~DatabaseVisualisationInterface()
{
    delete ui;
}
