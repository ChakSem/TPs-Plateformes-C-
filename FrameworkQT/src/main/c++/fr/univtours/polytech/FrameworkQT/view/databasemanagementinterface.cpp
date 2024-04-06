#include "databasemanagementinterface.h"
#include "ui_databasemanagementinterface.h"
#include "QFileDialog"
#include "QFileInfo"
#include "../utils/exception.h"
#include "../parserSqlite/parsersqlite.h"
#include "../controller/controller.h"
#include "../model/profile.h"
#include "mainwindow.h"

/**
 * Méthode pour initialiser la comboBox avec les tables de la base de données
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::initializeComboBox()
{
    ui->comboBoxTable->clear();

    parserSqlite* db = Controller::getOpenedDatabase();// On récupère la base de données ouverte

    for (QString tableName : db->getTablesNames()) {
        ui->comboBoxTable->addItem(tableName);
    }

    ui->comboBoxCommand->clear();

    ui->comboBoxCommand->addItem("SELECT");

    /* On ajoute les commandes en fonction des droits de l'utilisateur */
    if(Controller::getProfileDatabases()->getRight() != Rights::LECTURE)// Si l'utilisateur a les droits de modification
    {
        ui->comboBoxCommand->addItem("UPDATE");
        ui->comboBoxCommand->addItem("INSERT INTO");

        if(Controller::getProfileDatabases()->getRight() == Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION) //Si Admin
        {
            ui->comboBoxCommand->addItem("DELETE FROM");
        }
    }

}

/**
 * Constructeur de la classe DatabaseManagementInterface
 * Entrée :
 * Sortie :
 */
DatabaseManagementInterface::DatabaseManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseManagementInterface)

{
    ui->setupUi(this);
    /* Connexion des boutons aux méthodes(Redirecction vers les informations du compte, les bases de données, les profils et les utilisateurs) */
    connect(ui->pushButtonVisualization, &QPushButton::clicked, this, &DatabaseManagementInterface::actionVisualization);
    connect(ui->pushButtonExecute, &QPushButton::clicked, this, &DatabaseManagementInterface::actionExecute);
}

/**
 * Méthode pour visualiser les données de la table selectionnée
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::actionVisualization()
{
    MainWindow *mainWindow = MainWindow::accessToParent(this);
    QString tableNameSelected = ui->comboBoxTable->itemText(ui->comboBoxTable->currentIndex());

    try {
        if (tableNameSelected == "")
            throw new Exception(ERREUR_COMBOBOX_VIDE);

        mainWindow->openDatabaseVisualisation(tableNameSelected);
    } catch (Exception* e) {
        e->EXCAffichageErreur();

        delete e;
    }
}

/**
 * Méthode pour exécuter une requête SQL
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::actionExecute()
{
    QString typeDeRequete = ui->comboBoxCommand->currentText();

    if(typeDeRequete == "SELECT") {
        MainWindow *mainWindow = MainWindow::accessToParent(this);
        QString tableNameSelected = ui->comboBoxTable->itemText(ui->comboBoxTable->currentIndex());

        try {
            if (tableNameSelected == "")
                throw new Exception(ERREUR_COMBOBOX_VIDE);

            mainWindow->openDatabaseVisualisationForSelectQuery("Select " + ui->plainTextEdit->toPlainText());
        } catch (Exception* e) {
            e->EXCAffichageErreur();

            delete e;
        }
    }
    if(typeDeRequete == "UPDATE") {
        Controller::getOpenedDatabase()->processUpdateQuery("Update " + ui->plainTextEdit->toPlainText(), Controller::getProfileDatabases());
    }
    if(typeDeRequete == "INSERT INTO") {
        Controller::getOpenedDatabase()->processInsertQuery("Insert into " + ui->plainTextEdit->toPlainText(), Controller::getProfileDatabases());
    }
    if(typeDeRequete == "DELETE FROM") {
        Controller::getOpenedDatabase()->processUpdateQuery("Delete From " + ui->plainTextEdit->toPlainText(), Controller::getProfileDatabases());
    }
}

DatabaseManagementInterface::~DatabaseManagementInterface()
{
    delete ui;
}


