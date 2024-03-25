#ifndef CPARSER_SQLITE_H
#define CPARSER_SQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include <QMap>
#include "../model/User.h"
#include "../model/Profile.h"
#include "../model/data.h"
// #include "../model/Rights.h"

class parserSqlite
{
private:
    QSqlDatabase database;

public:
    /* Méthode pour ouvrir une connexion à une base de données */
    void openDatabase(const QString &filePath);

    /* Méthode pour fermer une connexion à une base de données */
    void closeDatabase();

    /* Méthode pour effectuer le parsing d'une base de données, le parsing consiste à récupérer les tables et les colonnes de la base de données */
    QList<QList<QString>> parseDatabase(QString tableName);

    /* Méthode pour traiter les requêtes SELECT (tout en verifiant les droits de l'utilisateur) */
    QList<QList<QString>> processSelectQuery(const QString &query, Profile *profile);

    /* Méthode pour traiter les requêtes UPDATE (tout en verifiant les droits de l'utilisateur) */
    bool processUpdateQuery(const QString &query, Profile *profile);

    /* Méthode pour traiter les requêtes INSERT (tout en verifiant les droits de l'utilisateur) */
    bool processInsertQuery(const QString &query, Profile *profile);

    /* Méthode pour traiter les requêtes DELETE (tout en verifiant les droits de l'utilisateur) */
    bool processDeleteQuery(const QString &query, Profile *profile);

    /* Methode pour recuperer la liste des tables d'une base de données */
    QList<QString> getTablesNames();

    void displayQueryError();

    parserSqlite(QString filePath);
    ~parserSqlite();

private :
    QList<QString> getFields(QString tableName);

    parserSqlite();
    parserSqlite(parserSqlite& CparserSqliteParam);
};

#endif // CPARSER_SQLITE_H
