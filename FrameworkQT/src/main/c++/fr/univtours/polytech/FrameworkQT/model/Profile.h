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
    QList<QString*> databases;
    //Map de database a mettre (avec le nom de la database et l'addresse ) pour pouvoir les ouvrir et les fermer
    
    User *user; // Utilisateur du profil

public:
    /* Accesseurs de l'attribut title */
    QString getTitle();
    void setTitle(const QString& newTitle);

    /* Accesseurs de l'attribut right */
    void setRight(const Rights& newRight);
    Rights getRight();

    /* Accesseurs de l'attribut databases */
    QList<QString*> getDatabases();
    void addDataBase(const QString& newDatabase);

    Profile& operator=(const Profile& profile);


private:
    /* Constructeur à ne pas utiliser (on veut avoir des utilisateurs nommés) */
    Profile();

public:
    /* Constructeurs et Destructeurs */
    Profile(const Profile& profile);
    Profile(User* actualUser, const QString& newTitle);
    Profile(User* actualUser, const QString& newTitle, const Rights& newRight);
    Profile(User* actualUser, const QString& newTitle, const Rights& newRight, const QList<QString*>& newDatabases);

    ~Profile();
   
    // QString toString(); //Pour convertir le profil en string et ensuite le sauvegarder dans un fichier ou l'afficher / PAS NECESAIRE POUR LE MOMENT
};

#endif
