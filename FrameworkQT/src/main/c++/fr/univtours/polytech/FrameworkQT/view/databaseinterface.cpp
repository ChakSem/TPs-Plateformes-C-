#include "databaseinterface.h"
#include "ui_databaseinterface.h"
#include "../utils/exception.h"
#include "../model/profile.h"

void DatabaseInterface::initializeComboBox() {
    QComboBox* combo =  ui->comboBoxDatabases;
    combo->clear();

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

void DatabaseInterface::actionManageDatabase()
{
    MainWindow *mainWindow = MainWindow::accessToParent(this);
    QString databaseNameSelected = ui->comboBoxDatabases->itemText(ui->comboBoxDatabases->currentIndex());

    try {
        if (databaseNameSelected == "")
            throw new Exception(ERREUR_COMBOBOX_VIDE);

        QString filePath = Controller::getProfileDatabases()->getDatabases()[databaseNameSelected];
        if (mainWindow != NULL) {
            mainWindow->openDatabaseManagement(filePath);
        }
    } catch (Exception* e) {
        e->EXCAffichageErreur();

        delete e;
    }

}

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
