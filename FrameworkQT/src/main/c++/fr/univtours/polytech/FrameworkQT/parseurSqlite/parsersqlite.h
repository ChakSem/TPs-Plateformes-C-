#ifndef CPARSER_SQLITE_H
#define CPARSER_SQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include <QMap>
#include "../model/User.h"
#include "../model/Profile.h"
#include "../model/data.h"

class parserSqlite
{
private:
    QSqlDatabase database; //

public:
    /* Méthodes pour gérer l'attribue database */
    void openDatabase(const QString &filePath);
    void closeDatabase();

    /* Méthode pour la recuperation des donnees dans le cadre d'une requete SELECT */
    QList<QList<QString>> parseDatabase(QString tableName);
    QList<QList<QString>> processSelectQuery(const QString &query);

    /* Méthode pour traiter les requêtes UPDATE / INSERT INTO / DELETE FROM */
    bool processUpdateQuery(const QString &query, Profile *profile);
    bool processInsertQuery(const QString &query, Profile *profile);
    bool processDeleteQuery(const QString &query, Profile *profile);

    /* Methode pour recuperer la liste des tables d'une base de données */
    QList<QString> getTablesNames();

    /* Constructeur et Destructeur à utiliser */
    parserSqlite(QString filePath);
    ~parserSqlite();

private :
    /* Méthode pour récuperer les champs d'une table */
    QList<QString> getFields(QString tableName);
    /* Constructeurs à bannir */
    parserSqlite();
    parserSqlite(parserSqlite& CparserSqliteParam);
};

#endif // CPARSER_SQLITE_H
