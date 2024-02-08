#include <qstring>
#include "qlist.h"

#include "UUID.h"

#ifndef USER
#define USER 1

class Profile;

class User {
private :
    QString id; // Gestion attribution id dynamique
    QString lastname;
    QString firstname;
    QList<Profile*> profiles;

public :
    /* Accesseurs de l'attribut id */
    QString getId() const;

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

    /* Surcharge de l'opérateur = */
    User& operator=(const User& user);

private:
/* Constructeur à ne pas utiliser (on veut avoir des utilisateurs nommés) */
    User();

public :
/* Constructeurs et Destructeur */
    User(const User& user);
    User(const QString& newLastname, const QString& newFirstname);
    User(const QString& newLastname, const QString& newFirstname, const QList<Profile*>& newProfiles);

    ~User();
};

#endif
