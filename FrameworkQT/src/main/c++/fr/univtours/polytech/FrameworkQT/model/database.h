#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QString>
#include <QFileDialog>
#include <QSqlQuery>
#include "User.h"
#include "../utils/exception.h"


class Database
{
private:
    QSqlDatabase m_db;
    User* actualUser;
    //QList<QString> databases;
    QList<QString> tables;

public:
    Database();
    Database(User* actualUser);
    bool addDatabase(const QString& filePath);
    bool removeDatabase(const QString& databaseName);

    QList<QString> getTables(const QString& databaseName);
    bool executeQuery(const QString& query);
    bool viewContent(const QString& databaseName, const QString& tableName);
    bool viewQuery(const QString& query);
    QList<QString> getUserDatabases(User* user);
};

#endif // DATABASE_H
