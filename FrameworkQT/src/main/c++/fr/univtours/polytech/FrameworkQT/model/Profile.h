#include <qstring>
#include "qmap.h"
//include pour utiliser QSQLdatabase a mettre
#include <QtSql>
#include <QSqlDatabase>

#include "rights.h"

#ifndef PROFILE
#define PROFILE 1

#define PASTROUVE 0
#define TROUVE 1

#define DATABASE_ADD_SUCCESS 0
#define DATABASE_ADD_ERROR 1

class User;

class Profile
{
private:
    /* Profile (un profil est defini par un nom(string) et son role(string issue du enum Rights mais faut voir comment on fait pour l'enum) */
    QString title;
    Rights right;
    QMap<QString, QString> databases; //Map de database a mettre (avec le nom de la database et l'addresse ) pour pouvoir les ouvrir et les fermer
    
    User *user; // Utilisateur du profil

public:
    /* Accesseurs de l'attribut title */
    QString getTitle();
    void setTitle(const QString& newTitle);

    /* Accesseurs de l'attribut right */
    void setRight(const Rights& newRight);
    Rights getRight();

    /* Accesseurs de l'attribut databases */
    QMap<QString, QString> getDatabases();
    QString getPathFile(const QString& databaseName);
    unsigned int addDataBase(const QString& databaseName, const QString& databaseFilePath);
    unsigned int removeDataBase(const QString& databaseName);

    /* Surcharge de l'opérateur = */
    Profile& operator=(const Profile& profile);

private:
    /* Constructeur à ne pas utiliser (on veut avoir des utilisateurs nommés) */
    Profile();

public:
    /* Constructeurs et Destructeurs */
    Profile(const Profile& profile);
    Profile(User* actualUser, const QString& newTitle);
    Profile(User* actualUser, const QString& newTitle, const Rights& newRight);
    Profile(User* actualUser, const QString& newTitle, const Rights& newRight, const QMap<QString, QString>& newDatabases);

    ~Profile();
   
    // QString toString(); //Pour convertir le profil en string et ensuite le sauvegarder dans un fichier ou l'afficher / PAS NECESAIRE POUR LE MOMENT
};

#endif

