#include "parsersqlite.h"
#include "../utils/Exception.h"

parserSqlite::parserSqlite() {}

/**
 * Méthode pour ouvrir une connexion à une base de données
 * Entree : - filePath, const QString& (chemin du fichier de la base de données)
 * Sortie : - db, QSqlDatabase (base de données ouverte)
 */
void parserSqlite::openDatabase(const QString &filePath)
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

void parserSqlite::closeDatabase()
{
    database.close();
}

/**
 * Méthode pour effectuer le parsing d'une base de données
 * Entree : - tableName, QString le nom de la table dont l'on veut le contenu
 * Sortie : - content, QList<QList<QString>> le contenu de la table
 */
QList<QList<QString>> parserSqlite::parseDatabase(QString tableName)
{
    QList<QList<QString>> content;

    try
    {
        if (!database.isOpen()) // Vérification si la base de données est ouverte
            throw new Exception(BASE_DE_DONNEE_NON_OUVERTE);

        content.append(getFields(tableName));

        QSqlQuery query(database);
        QString queryString = QString("SELECT * FROM %1").arg(tableName);
        if (!query.exec(queryString))
            throw new Exception(ERREUR_REQUETE_SQL);

        while (query.next())
        {
            QList<QString> row;
            for (int i = 0; i < query.record().count(); ++i)
            {
                row.append(query.value(i).toString());
            }
            content.append(row);
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }

    return content;
}

/**
 * Méthode pour récuperer les champs d'une table
 * Entree : - tableName, QString le nom de la table dont l'on veut les champs
 * Sortie : - fields, QList<QString> la liste des champs de la table
 */
QList<QString> parserSqlite::getFields(QString tableName) {
    QList<QString> fields;

    QSqlRecord record = database.record(tableName);
    for (int i = 0; i < record.count(); ++i) {
        fields.append(record.fieldName(i));
    }

    return fields;
}

/**
 * Méthode pour traiter les requêtes SELECT (tout en verifiant les droits de l'utilisateur)
 * Entree : - query, const QString& (requête à traiter)
 *          - user, User* (utilisateur effectuant la requête)
 * Sortie : - result, QList<QList<QString>> (résultat de la requête)
 **/
QList<QList<QString>> parserSqlite::processSelectQuery(const QString &query, Profile *profile)
{
    try
    {
        qDebug() << "Execution de la requete : " + query;

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
        qDebug() << " => requete executee avec succes\n";

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
bool parserSqlite::processUpdateQuery(const QString &query, Profile *profile)
{
    try
    {
        qDebug() << "Execution de la requete : " + query;
        if (profile->getRight() != Rights::LECTURE_MODIFICATION && profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlQuery myQuery(database);
        /* Exécution de la requête */
        if (!myQuery.exec(query))
        {
            qDebug() << " => la requete a echouee\n";
            return false;
        }
        qDebug() << " => requete executee avec succes\n";

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
bool parserSqlite::processInsertQuery(const QString &query, Profile *profile)
{
    try
    {
        qDebug() << "Execution de la requete : " + query;
        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);


        QSqlQuery myQuery(database);
        if (!myQuery.exec(query))
        {
            qDebug() << " => la requete a echouee\n";
            return false;
        }
        qDebug() << " => requete executee avec succes\n";

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
bool parserSqlite::processDeleteQuery(const QString &query, Profile *profile)
{
    try
    {
        qDebug() << "Execution de la requete : " + query;
        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlQuery myQuery(database);
        if (!myQuery.exec(query))
        {
            qDebug() << " => la requete a echouee\n";
            return false;
        }
        qDebug() << " => requete executee avec succes\n";

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
QList<QString> parserSqlite::getTablesNames()
{
    return database.tables();
}

parserSqlite::parserSqlite(QString filePath) {
    openDatabase(filePath);
}

parserSqlite::~parserSqlite() {
    closeDatabase();
}
