#include "databasemanagementinterface.h"
#include "ui_databasemanagementinterface.h"
#include "QFileDialog"
#include "QFileInfo"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "../model/Profile.h"




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


