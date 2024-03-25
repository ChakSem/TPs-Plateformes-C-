#include "databasevisualisationinterface.h"
#include "ui_databasevisualisationinterface.h"
#include "../utils/exception.h"
#include "../parseurSqlite/parsersqlite.h"
#include "../controller/controller.h"


void DatabaseVisualisationInterface::initializeTableWidget(QString tableName) {
    ui->tableWidget->clear();

    QList<QList<QString>> donneesTable = Controller::getOpenedDatabase()->parseDatabase(tableName);

    unsigned int lineNb = donneesTable.size();
    unsigned int columnNb = donneesTable[0].size();

    ui->tableWidget->setRowCount(lineNb);
    ui->tableWidget->setColumnCount(columnNb);

    for (unsigned int i = 0; i < lineNb; i ++) {
        for (unsigned int j = 0; j < columnNb; j ++) {
            QTableWidgetItem *item = new QTableWidgetItem(donneesTable[i][j]);
            ui->tableWidget->setItem(i, j, item);
        }
    }

    for (unsigned int j = 0; j < columnNb; j++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, j);
        if (item) {
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
        }
    }

    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setStyleSheet("font-weight: bold;");
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
