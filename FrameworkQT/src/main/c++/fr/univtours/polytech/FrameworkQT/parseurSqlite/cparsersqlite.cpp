#include "Cparsersqlite.h"
#include "../utils/Exception.h"

CparserSqlite::CparserSqlite() {}

/**
 * Méthode pour ouvrir une connexion à une base de données
 * Entree : - filePath, const QString& (chemin du fichier de la base de données)
 * Sortie : - db, QSqlDatabase (base de données ouverte)
 */
void CparserSqlite::openDatabase(const QString &filePath)
{
    try
    {
        if (filePath.isEmpty()) // Vérification si le chemin du fichier est vide
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);

        database = QSqlDatabase::addDatabase("QSQLITE", filePath);
        database.setDatabaseName(filePath); // Définition du nom de la base de données

        if (!database.open()) // Tentative d'ouverture de la base de données
        {
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}

void CparserSqlite::closeDatabase()
{
    database.close();
}

/**
 * Méthode pour effectuer le parsing d'une base de données
 * Entree : - database, QSqlDatabase& (base de données à parser)
 * Sortie : - tables, QMap<QString, QList<QString>> (tables et colonnes de la base de données)
 */

QList<QString>* CparserSqlite::parseDatabase(QString tableName)
{
    QList<QString>* content = new QList<QString>();
    try
    {
        if (!database.isOpen()) // Vérification si la base de données est ouverte
            throw new Exception(BASE_DE_DONNEE_NON_OUVERTE);


        QSqlRecord record = database.record(tableName);
        for (int i = 0; i < record.count(); ++i)
        {
            content->append(record.fieldName(i));
        }

        return content;
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;

        return NULL;
    }
}

/**
 * Méthode pour traiter les requêtes SELECT (tout en verifiant les droits de l'utilisateur)
 * Entree : - query, const QString& (requête à traiter)
 *          - user, User* (utilisateur effectuant la requête)
 * Sortie : - result, QList<QList<QString>> (résultat de la requête)
 **/
QList<QList<QString>> CparserSqlite::processSelectQuery(const QString &query, Profile *profile)
{
    try
    {
        if (query.isEmpty()) { // Vérification si la requête est vide
            throw new Exception(BASE_DE_DONNEE_NON_OUVERTE);
        }

        QSqlQuery myQuery(database);
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

/**
 * Méthode pour traiter les requêtes UPDATE (tout en verifiant les droits de l'utilisateur)
 * Entree : - query, const QString& (requête à traiter)
 *          - user, User* (utilisateur effectuant la requête)
 * Sortie : -result, bool (indique si la requête a été effectuée avec succès)
 */
bool CparserSqlite::processUpdateQuery(const QString &query, Profile *profile)
{
    try
    {
        if (profile->getRight() != Rights::LECTURE_MODIFICATION && profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlQuery myQuery(database);
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

/**
 * Méthode pour traiter les requêtes INSERT (tout en verifiant les droits de l'utilisateur)
 * Entree : - query, const QString& (requête à traiter)
 *          - user, User* (utilisateur effectuant la requête)
 * Sortie : -result, bool (indique si la requête a été effectuée avec succès)
 */
bool CparserSqlite::processInsertQuery(const QString &query, Profile *profile)
{
    try
    {
        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);


        QSqlQuery myQuery(database);
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

/**
 * Méthode pour traiter les requêtes DELETE (tout en verifiant les droits de l'utilisateur)
 * Entree : - query, const QString& (requête à traiter)
 *          - user, User* (utilisateur effectuant la requête)
 * Sortie : -result, bool (indique si la requête a été effectuée avec succès)
 */
bool CparserSqlite::processDeleteQuery(const QString &query, Profile *profile)
{
    try
    {
        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlQuery myQuery(database);
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

/**
 * Methode pour récupérer la liste des tables d'une base de données d'
 * Entree : - databaseName, const QString& (nom de la base de données)
 * Sortie : - tables, QList<QString> (liste des tables de la base de données)
 */
QList<QString> CparserSqlite::getTablesNames()
{
    return database.tables();
}

CparserSqlite::CparserSqlite(QString filePath) {
    openDatabase(filePath);
}

CparserSqlite::~CparserSqlite() {
    closeDatabase();
}
