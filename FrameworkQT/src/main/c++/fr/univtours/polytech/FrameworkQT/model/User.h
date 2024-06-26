#include <qstring>
#include "qlist.h"

#include "uuid.h"

#ifndef USER
#define USER 1

class Profile;

class User {
private :
    QString id; // Gestion attribution id dynamique
    QString firstname;
    QString lastname;
    QList<Profile*> profiles;

public :
    /* Accesseurs de l'attribut id */
    QString getId();

    /* Accesseurs de l'attribut lastname */
    QString getLastname();
    void setLastname(const QString& newLastname);

   
    /* Accesseurs de l'attribut firstname */
    QString getFirstname();
    void setFirstname(const QString& newFirstname);

    /* Accesseur en lecture et Pseudo-Accesseurs en écriture de l'attribut profiles */
    QList<Profile*> getProfiles();
    void addProfile(const Profile& profile);
    void deleteProfile(const QString intitule);

    /* Méthode pour connaitre le rôle d'un utilisateur */
    QString getRole();


    /* Surcharge de l'opérateur = */
    User& operator=(const User& user);

private:
/* Constructeur à ne pas utiliser (on veut avoir des utilisateurs nommés) */
    User();

public :
/* Constructeurs et Destructeur */
    User(const User& user);
    User(const QString& newFirstname, const QString& newLastname);
    User(const QString& newFirstname, const QString& newLastname, const QList<Profile*>& newProfiles);
    User(const QString& newId, const QString& newFirstname, const QString& newLastname); // Constructeur pour le parseur

    ~User();
};

#endif
