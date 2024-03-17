#ifndef CPARSER_SQLITE_H
#define CPARSER_SQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QList>
#include <QMap>
#include "../model/User.h"
#include "../model/Profile.h"
// #include "../model/Rights.h"

class CparserSqlite {
private:
    QSqlDatabase database;
public:
    CparserSqlite();
    // Méthode pour ouvrir une connexion à une base de données
    QSqlDatabase openDatabase(const QString& filePath);

    // Méthode pour fermer une connexion à une base de données
    void closeDatabase(const QString& databaseName);

    // Méthode pour effectuer le parsing d'une base de données, le parsing consiste à récupérer les tables et les colonnes de la base de données
    void parseDatabase(QSqlDatabase &database, QMap<QString, QList<QString>> &tables);

    // Méthode pour traiter les requêtes SELECT (tout en verifiant les droits de l'utilisateur)
    QList<QList<QString>> processSelectQuery(const QString& query, Profile* profile);

    // Méthode pour traiter les requêtes UPDATE (tout en verifiant les droits de l'utilisateur)
    bool processUpdateQuery(const QString& query, Profile* profile);

    // Méthode pour traiter les requêtes INSERT (tout en verifiant les droits de l'utilisateur)
    bool processInsertQuery(const QString& query, Profile* profile);

    // Méthode pour traiter les requêtes DELETE (tout en verifiant les droits de l'utilisateur)
    bool processDeleteQuery(const QString& query, Profile* profile);

    void displayQueryError();

};

#endif // CPARSER_SQLITE_H

