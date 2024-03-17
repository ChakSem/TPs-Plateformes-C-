#include "Cparsersqlite.h"
#include "../utils/Exception.h"

CparserSqlite::CparserSqlite() {}

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
// #define PASDERREUR 0

// #define NOM_PROFIL_DEJA_ATTRIBUE 1
// #define BASE_DE_DONNEE_DEJA_AJOUTEE 2
// #define BASE_DE_DONNEE_NON_TROUVEE 20
// #define BASE_DE_DONNEE_NON_OUVERTE 21


// /* Parsing */
// #define ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER 3
// #define ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN 4
// #define ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER 5
// #define ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN 6
// #define ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER 7
// #define ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN 8
// #define ERREUR_DROIT_INCONNU 18
// #define ERREUR_OUVERTURE_FICHIER_POUR_MOTS_DE_PASSE 19

// /* Data */
// #define ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID 9
// #define ERREUR_ISADMIN_INCORRECT 12

// /* Controller */
// #define ERREUR_AUCUN_DROIT_CORRESPONDANT 10
// #define ERREUR_AUCUN_ROLE_CORRESPONDANT 11
// #define ERREUR_AUCUN_PROFIL_CORRESPONDANT 16

// /* Vues */
// #define ERREUR_MAINWINDOW_NON_TROUVE 13
// #define ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS 14
// #define ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES 15
// #define ERREUR_USER_MANAGEMENT_SUPPRESSION_SUPER_ADMIN 17


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

        if (profile->getRight() != Rights::LECTURE && profile->getRight() != Rights::LECTURE_MODIFICATION && profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
                displayQueryError();
                return QList<QList<QString>>();
        }
        QList<QList<QString>> result;
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
        if (query.isEmpty()) // Vérification si la requête est vide
            throw new Exception(QUERY_VIDE);

        if (profile->getRight() != Rights::LECTURE_MODIFICATION && profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
            displayQueryError();
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
        if (query.isEmpty()) // Vérification si la requête est vide
            throw new Exception(QUERY_VIDE);

        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
            displayQueryError();
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
        if (query.isEmpty()) // Vérification si la requête est vide
            throw new Exception(QUERY_VIDE);

        if (profile->getRight() != Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION)
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);

        QSqlDatabase db = openDatabase(query);
        QSqlQuery myQuery(db);
        if (!myQuery.exec(query))
        {
            displayQueryError();
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

void CparserSqlite::displayQueryError()
{
}
