#include <qstring>
#include "qlist.h"

#include "Rights.h"

#ifndef PROFILE
#define PROFILE 1

class User;

class Profile
{
private:
    /* Profile (un profil est defini par un nom(string) et son role(string issue du enum Rights mais faut voir comment on fait pour l'enum) */
    QString title;
    Rights right;
    QList<QString> databases;
    User *user; //Utilisateur du profil

public:
    /* Accesseurs de l'attribut title */
    QString getTitle();
    void setTitle(QString newTitle);

    /* Accesseurs de l'attribut right */
    void setRight(Rights newRight);
    Rights getRight();

    /* Accesseurs de l'attribut databases */
    QList<QString> getDatabases();
    void addDataBase(QString newDatabase);

    Profile* operator=(const Profile& profile);

    /* Constructeur */
    Profile(const Profile& profile);
    Profile(User* actualUser, QString newTitle);
    Profile(User* actualUser, QString newTitle, Rights newRight);
    Profile(User* actualUser, QString newTitle, Rights newRight, QList<QString> newDatabases);

    /* Destructeur */
    ~Profile();
   
    // QString toString(); //Pour convertir le profil en string et ensuite le sauvegarder dans un fichier ou l'afficher / PAS NECESAIRE POUR LE MOMENT
};

#endif
