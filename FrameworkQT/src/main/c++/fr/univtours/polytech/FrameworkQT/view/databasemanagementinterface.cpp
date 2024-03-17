#include "databasemanagementinterface.h"
#include "ui_databasemanagementinterface.h"
#include "QFileDialog"
#include "QFileInfo"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "../model/Profile.h"

void DatabaseManagementInterface::initializeComboBox() {
    QComboBox* combo =  ui->comboBoxTable;
    combo->clear();

    for(QString* databaseName : Controller::getProfileDatabases()->getDatabases().keys()) {
        combo->addItem(*databaseName);
    }
}


DatabaseManagementInterface::DatabaseManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseManagementInterface)

{
    ui->setupUi(this);
    /* Connexion des boutons aux méthodes(Redirecction vers les informations du compte, les bases de données, les profils et les utilisateurs) */
    connect(ui->pushButtonOpenFromFiles, &QPushButton::clicked, this, &DatabaseManagementInterface::actionOpenFromFiles);
    connect(ui->pushButtonVisualiza, &QPushButton::clicked, this, &DatabaseManagementInterface::actionVisualization);
    connect(ui->pushButtonExecute, &QPushButton::clicked, this, &DatabaseManagementInterface::actionExecute);
}

/**
 * Permet de rediriger vers la page de gestion des profils
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::actionOpenFromFiles()
{
    QString filePath  = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Fichiers (*.sqlite)"));

    if (!filePath.isEmpty()) {
        QString name = QFileInfo(filePath).baseName(); // Utilisez le nom de fichier sans extension comme nom de base de données

        Controller::getProfileDatabases()->addDataBase(name, filePath);

        ui->comboBoxTable->addItem(name);
    } else {

    }
}

/**
 * Permet de rediriger vers la page de gestion des profils
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::actionVisualization()
{
    // TODO
}

/**
 * Permet de rediriger vers la page de gestion des profils
 * Entrée :
 * Sortie :
 */
void DatabaseManagementInterface::actionExecute()
{
    // TODO
}

DatabaseManagementInterface::~DatabaseManagementInterface()
{
    delete ui;
}


