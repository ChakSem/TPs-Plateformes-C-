#include "databaseinterface.h"
#include "ui_databaseinterface.h"

void DatabaseInterface::initializeComboBox() {
    QComboBox* combo =  ui->comboBoxDatabases;
    combo->clear();

    for(QString* databaseName : Controller::getProfileDatabases()->getDatabases().keys()) {
        combo->addItem(*databaseName);
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

void DatabaseInterface::actionAddDatabase()
{
    QString filePath  = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir::homePath(), tr("Fichiers (*.sqlite)"));

    if (!filePath.isEmpty()) {
        QString name = QFileInfo(filePath).baseName(); // Utilisez le nom de fichier sans extension comme nom de base de données

        Controller::getProfileDatabases()->addDataBase(name, filePath);

        ui->comboBoxDatabases->addItem(name);
    } else {

    }
}

void DatabaseInterface::actionManageDatabase()
{
    // TODO : ouvrir la vue databasemanagement
}

void DatabaseInterface::actionRemoveDatabase()
{
    // TODO : suppr
}

 DatabaseInterface::~DatabaseInterface()
{
    delete ui;
}
