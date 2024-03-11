#include "databaseinterface.h"
#include "ui_databaseinterface.h"

DatabaseInterface::DatabaseInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseInterface)

{
    ui->setupUi(this);
     connect(ui->pushButtonAdd, &QPushButton::clicked, this, &DatabaseInterface::actionAddDatabase);
}

DatabaseInterface::~DatabaseInterface()
{
    delete ui;
}
// /*Methode pour recuperer le path d'un fichier .db ou .sqlite*/
// QString getPathFile();
// void actionAddDatabase();

QString DatabaseInterface::getPathFile()
{
    try
    {
        QString path = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier .db (*.db);;Fichier .sqlite (*.sqlite)");
        if (path.isEmpty())
        {
           // throw new Exception(ERREUR_FICHIER_NON_SELECTIONNE);
        }
        return path;
    }
    catch ( Exception *e)
    {
        e->EXCAffichageErreur();
        return NULL;
    }
}

void DatabaseInterface::actionAddDatabase()
{
    try
    {
        QString path = getPathFile();
        // Utiliser la methode associées QSQLDatabase::addDatabase qui existe deja 
        MainWindow::messageDialog("La base de données a bien été ajoutée", "Information", MESSAGEBOX_OK);

    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}
