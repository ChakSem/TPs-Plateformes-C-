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
    QString getId();
    QString getLastname();
    void setLastname(const QString& newLastname);
    QString getFirstname();
    void setFirstname(const QString& newFirstname);
    void addProfile(const Profile& profile);
    void deleteProfile(const QString intitule);

private:
    User();
    User(User& user);

public :
    User(const QString& newLastname, const QString& newFirstname);
    User(const QString& newLastname, const QString& newFirstname, const QList<Profile*>& newProfiles);
};

#endif
