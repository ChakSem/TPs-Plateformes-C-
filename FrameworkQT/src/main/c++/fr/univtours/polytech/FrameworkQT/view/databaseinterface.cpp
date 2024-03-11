#include "databaseinterface.h"
#include "ui_databaseinterface.h"

DatabaseInterface::DatabaseInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseInterface)
        connect(ui->pushButtonAdd, &QPushButton::clicked, this, &DatabaseInterface::actionAddDatabase);
{
    ui->setupUi(this);
}

DatabaseInterface::~DatabaseInterface()
{
    delete ui;
}
// /*Methode pour recuperer le path d'un fichier .db ou .sqlite*/
// QString getPathFile();
// void actionAddDatabase();

DatabaseInterface::getPathFile()
{
    try
    {
        QString path = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier .db (*.db);;Fichier .sqlite (*.sqlite)");
        if (path.isEmpty())
        {
            throw new Exception(ERREUR_FICHIER_NON_SELECTIONNE);
        }
        return path;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

DatabaseInterface::actionAddDatabase()
{
    try
    {
        QString path = getPathFile();
        //Controller::addDatabase(path); // Utiliser la methode associées QSQLDatabase::addDatabase qui existe de=eja 
        MainWindow::messageDialog("La base de données a bien été ajoutée", "Information", MESSAGEBOX_OK);
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}