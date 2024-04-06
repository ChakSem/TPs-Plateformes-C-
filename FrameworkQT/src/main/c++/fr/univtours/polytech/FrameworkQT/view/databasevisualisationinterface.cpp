#include "databasevisualisationinterface.h"
#include "ui_databasevisualisationinterface.h"
#include "../utils/exception.h"
#include "../parserSqlite/parsersqlite.h"
#include "../controller/controller.h"
#include "mainwindow.h"

/**
 * Méthode pour initialiser le tableau (tableWidget) avec les données de la table (tableName) de la base de données
 * Entrée : tableName, QString : le nom de la table à afficher
 * Sortie :
 */
void DatabaseVisualisationInterface::initializeTableWidget(QString tableName) {
    ui->tableWidget->clear();

    QList<QList<QString>> donneesTable = Controller::getOpenedDatabase()->parseDatabase(tableName); // On récupère les données de la table

    unsigned int lineNb = donneesTable.size();
    unsigned int columnNb = donneesTable[0].size();

    ui->tableWidget->setRowCount(lineNb);
    ui->tableWidget->setColumnCount(columnNb);

    /* On remplit le tableau avec les données de donneesTable */
    for (unsigned int i = 0; i < lineNb; i ++) {
        for (unsigned int j = 0; j < columnNb; j ++) {
            QTableWidgetItem *item = new QTableWidgetItem(donneesTable[i][j]);
            ui->tableWidget->setItem(i, j, item);
        }
    }
    /* On affiche en gras la première ligne */
    for (unsigned int j = 0; j < columnNb; j++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, j);
        if (item) {
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
        }
    }
    /* On empêche la sélection et la modification des cellules */
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setStyleSheet("font-weight: bold;");
}

/**
 * Méthode afin d'exécuter une requête SQL et d'initialiser le tableau (tableWidget) avec les données de la requête
 * Entrée : requete, QString : la requête SELECT à éxecuter
 * Sortie :
 */
void DatabaseVisualisationInterface::initializeTableWidgetForSelectQuery(QString requete) {
    ui->tableWidget->clear();

    QList<QList<QString>> donneesTable = Controller::getOpenedDatabase()->processSelectQuery(requete); // On récupère les données de la requête

    unsigned int lineNb = donneesTable.size();

    /* Si la selection n'a pas echouee (donneesTable non vide) */
    if(lineNb > 0) {
        unsigned int columnNb = donneesTable[0].size();

        ui->tableWidget->setRowCount(lineNb);
        ui->tableWidget->setColumnCount(columnNb);

        /* On remplit le tableau avec les données de la requête */
        for (unsigned int i = 0; i < lineNb; i ++) {
            for (unsigned int j = 0; j < columnNb; j ++) {
                QTableWidgetItem *item = new QTableWidgetItem(donneesTable[i][j]);
                ui->tableWidget->setItem(i, j, item);
            }
        }
        /* On met en gras la première ligne */
        for (unsigned int j = 0; j < columnNb; j++) {
            QTableWidgetItem *item = ui->tableWidget->item(0, j);
            if (item) {
                QFont font = item->font();
                font.setBold(true);
                item->setFont(font);
            }
        }
        /* On empêche la sélection et la modification des cellules */
        ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->verticalHeader()->setStyleSheet("font-weight: bold;");
    }
    /* Sinon on affiche un message d'erreur */
    else {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);

        MainWindow::messageDialog("La Requete a echouee", "Echec", MESSAGEBOX_OK);
    }
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
