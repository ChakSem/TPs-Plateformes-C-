#include "databasemanagementinterface.h"
#include "ui_databasemanagementinterface.h"
#include "QFileDialog"
#include "QFileInfo"
#include "../utils/exception.h"
#include "../parserSqlite/parsersqlite.h"
#include "../controller/controller.h"
#include "../model/profile.h"
#include "mainwindow.h"


void DatabaseManagementInterface::initializeComboBox()
{
    ui->comboBoxTable->clear();

    parserSqlite* db = Controller::getOpenedDatabase();

    for (QString tableName : db->getTablesNames()) {
        ui->comboBoxTable->addItem(tableName);
    }

    ui->comboBoxCommand->clear();

    ui->comboBoxCommand->addItem("SELECT");

    if(Controller::getProfileDatabases()->getRight() != Rights::LECTURE) {
        ui->comboBoxCommand->addItem("UPDATE");
        ui->comboBoxCommand->addItem("INSERT INTO");

        if(Controller::getProfileDatabases()->getRight() == Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION) {
            ui->comboBoxCommand->addItem("DELETE FROM");
        }
    }

}

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
 * Permet de rediriger vers la page de gestion des profils
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
 * Permet de rediriger vers la page de gestion des profils
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


