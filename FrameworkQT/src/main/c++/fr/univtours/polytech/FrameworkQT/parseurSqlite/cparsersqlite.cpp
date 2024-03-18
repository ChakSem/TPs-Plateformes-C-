#include "Cparsersqlite.h"
#include "../utils/Exception.h"

CparserSqlite::CparserSqlite() {}

/** Méthode pour ouvrir une connexion à une base de données
 * Entree : - filePath, const QString& (chemin du fichier de la base de données)
 * Sortie : - db, QSqlDatabase (base de données ouverte)
 */
QSqlDatabase CparserSqlite::openDatabase(const QString &filePath)
{
    try
    {
        if (filePath.isEmpty()) // Vérification si le chemin du fichier est vide
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", filePath);
        db.setDatabaseName(filePath); // Définition du nom de la base de données

        if (!db.open()) // Tentative d'ouverture de la base de données
        {
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);
        }
        else
        {
            return db;
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;

        return QSqlDatabase();
    }
}

void CparserSqlite::closeDatabase(const QString &databaseName)
{
    QSqlDatabase db = QSqlDatabase::database(databaseName);
    db.close();
    QSqlDatabase::removeDatabase(databaseName);
}

/** Méthode pour effectuer le parsing d'une base de données 
 * Entree : - database, QSqlDatabase& (base de données à parser)
 * Sortie : - tables, QMap<QString, QList<QString>> (tables et colonnes de la base de données)
 */

void CparserSqlite::parseDatabase(QSqlDatabase &database, QMap<QString, QList<QString>> &tables)
{
    try
    {
        if (!database.isOpen()) // Vérification si la base de données est ouverte
            throw new Exception(BASE_DE_DONNEE_NON_OUVERTE);

        QStringList tableNames = database.tables();
        for (const QString &tableName : tableNames)
        {
            QSqlRecord record = database.record(tableName);
            QList<QString> columns;
            for (int i = 0; i < record.count(); ++i)
            {
                columns.append(record.fieldName(i));
            }
            tables.insert(tableName, columns);
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}

// Méthode pour traiter les requêtes SELECT (tout en verifiant les droits de l'utilisateur)
// Entree : - query, const QString& (requête à traiter)
//          - user, User* (utilisateur effectuant la requête)
// Sortie : - result, QList<QList<QString>> (résultat de la requête)
QList<QList<QString>> CparserSqlite::processSelectQuery(const QString &query, Profile *profile)
{
    try
    {
        if (query.isEmpty()) // Vérification si la requête est vide
            throw new Exception(BASE_DE_DONNEE_NON_OUVERTE);


        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
                return QList<QList<QString>>(); // Renvoyer une liste vide
        }
        QList<QList<QString>> result;
        /* Récupération des résultats de la requête */
        while (myQuery.next())
        {
                QList<QString> row;

                for (int i = 0; i < myQuery.record().count(); ++i)
                {
                    row.append(myQuery.value(i).toString());
                }
                result.append(row);
        }

        return result;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
        return QList<QList<QString>>(); // Renvoyer une liste vide
    }
}

// Méthode pour traiter les requêtes UPDATE (tout en verifiant les droits de l'utilisateur)
// Entree : - query, const QString& (requête à traiter)
//          - user, User* (utilisateur effectuant la requête)
// Sortie : -result, bool (indique si la requête a été effectuée avec succès)
bool CparserSqlite::processUpdateQuery(const QString &query, Profile *profile)
{
    try
    {
     

        if (profile->getRight() != Rights::LECTURE_MODIFICATION && profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        /* Exécution de la requête */
        if (!myQuery.exec(query))
        {
            return false;
        }

        return true;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
        return false;
    }
}

// Méthode pour traiter les requêtes INSERT (tout en verifiant les droits de l'utilisateur)
// Entree : - query, const QString& (requête à traiter)
//          - user, User* (utilisateur effectuant la requête)
// Sortie : -result, bool (indique si la requête a été effectuée avec succès)
bool CparserSqlite::processInsertQuery(const QString &query, Profile *profile)
{
    try
    {
        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
            return false;
        }

        return true;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
        return false;
    }
}

// Méthode pour traiter les requêtes DELETE (tout en verifiant les droits de l'utilisateur)
// Entree : - query, const QString& (requête à traiter)
//          - user, User* (utilisateur effectuant la requête)
// Sortie : -result, bool (indique si la requête a été effectuée avec succès)
bool CparserSqlite::processDeleteQuery(const QString &query, Profile *profile)
{
    try
    {

        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
            return false;
        }

        return true;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
        return false;
    }
}

