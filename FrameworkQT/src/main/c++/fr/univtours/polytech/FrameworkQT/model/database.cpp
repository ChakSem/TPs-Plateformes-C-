#include "database.h"


Database::Database() {}

Database::Database(User* actualUser) : actualUser(actualUser) {}

bool Database::addDatabase(const QString& filePath)
{
    try{
    if (filePath.isEmpty()) // Vérification si le chemin du fichier est vide
        return false;
    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(filePath); // Définition du nom de la base de données

        if (!m_db.open()) // Tentative d'ouverture de la base de données
        {
            qDebug() << "Error: connection with database failed";
            //throw  Exception();
            return false;
        }
        else
        {
            qDebug() << "Database: connection successful";
            //throw  Exception();
            databases.append(filePath); // Ajout du nom de la base de données à la liste
            return true;
        }
    }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

bool Database::removeDatabase(const QString& databaseName)
{
    try{
    if (!databases.contains(databaseName)) // Vérification si la base de données existe
        //throw  Exception();//Base de donnee non trouvee
        return false;
    else
    {
        m_db.close(); // Fermeture de la connexion à la base de données
        QSqlDatabase::removeDatabase(databaseName); // Suppression de la base de données
        databases.removeOne(databaseName); // Suppression du nom de la base de données de la liste
        return true;
    }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

QList<QString> Database::getDatabases()
{
    return databases; 
}

QList<QString> Database::getTables(const QString& databaseName)
{
    // TO DO : Implémenter la méthode qui permet de récupérer les tables d'une base de données
}

bool Database::executeQuery(const QString& query)
{
    try {
    QSqlQuery myQuery;
    if (!myQuery.exec(query))
    {
        qDebug() << "Error: query failed";
       // qDebug() << myQuery.lastError();
        return false;
    }
    else
    {
        qDebug() << "Query: success";
        return true;
    }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

bool Database::viewContent(const QString& databaseName, const QString& tableName)
{
    // TO DO : Implémenter la méthode qui permet de visualiser le contenu d'une table // Faudra permetre a l'utilisateur de choisir les tables
}

bool Database::viewQuery(const QString& query)
{
    //TO DO : Implementer la methode qui permet de visualiser le resultat d'une requete
}

QList<QString> Database::getUserDatabases(User* user)
{
    // TO DO : Implementer la methode qui permet de recuperer les bases de donnees d'un utilisateur
}
