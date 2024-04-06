#include "databaseinterface.h"
#include "ui_databaseinterface.h"
#include "../utils/exception.h"
#include "../model/profile.h"

/**
 * Méthode pour initialiser le comboBox avec les bases de données
 * Entrée :
 * Sortie :
 */
void DatabaseInterface::initializeComboBox() {
    QComboBox* combo =  ui->comboBoxDatabases;
    combo->clear();

    /* On réinitialise par rapport aux données de Data */
    for(QString databaseName : Controller::getProfileDatabases()->getDatabases().keys()) {
        combo->addItem(databaseName);
    }
}

DatabaseInterface::DatabaseInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseInterface)

{
    ui->setupUi(this);
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &DatabaseInterface::actionAddDatabase);
    connect(ui->pushButtonManage, &QPushButton::clicked, this, &DatabaseInterface::actionManageDatabase);
    connect(ui->pushButtonRemove, &QPushButton::clicked, this, &DatabaseInterface::actionRemoveDatabase);
}


/**
 * Méthode pour ajouter une base de données selectionée dans l'explorateur de fichiers
 * Entrée :
 * Sortie :
 */
void DatabaseInterface::actionAddDatabase()
{
    try {
        QString filePath  = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Fichiers (*.sqlite)"));

        if (filePath.isEmpty()) {
            throw new Exception(ERREUR_CHEMIN_VIDE);
        }
        Profile* profileDatabases = Controller::getProfileDatabases();
        QString name = QFileInfo(filePath).baseName();// Utilisez le nom de fichier sans extension comme nom de base de données

        if (profileDatabases->addDataBase(name, filePath) == DATABASE_ADD_SUCCESS) {
            ui->comboBoxDatabases->addItem(name);
        }

    } catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}

/**
 * Méthode pour gérer la base de données selectionnée
 * Entrée :
 * Sortie :
 */
void DatabaseInterface::actionManageDatabase()
{
    MainWindow *mainWindow = MainWindow::accessToParent(this);
    QString databaseNameSelected = ui->comboBoxDatabases->itemText(ui->comboBoxDatabases->currentIndex()); // Récupère le nom de la base de données selectionnée

    try {
        if (databaseNameSelected == "")
            throw new Exception(ERREUR_COMBOBOX_VIDE);

        QString filePath = Controller::getProfileDatabases()->getDatabases()[databaseNameSelected]; // Récupère le chemin de la base de données selectionnée
        if (mainWindow != NULL) {
            mainWindow->openDatabaseManagement(filePath);
        }
    } catch (Exception* e) {
        e->EXCAffichageErreur();

        delete e;
    }
}

/**
 * Méthode pour supprimer la base de données selectionnée
 * Entrée :
 * Sortie :
 */
void DatabaseInterface::actionRemoveDatabase()
{
    if (Controller::removeDataBase(ui->comboBoxDatabases->itemText(ui->comboBoxDatabases->currentIndex())) == TROUVE) {
        ui->comboBoxDatabases->removeItem(ui->comboBoxDatabases->currentIndex());
    }
}

 DatabaseInterface::~DatabaseInterface()
{
    delete ui;
}
