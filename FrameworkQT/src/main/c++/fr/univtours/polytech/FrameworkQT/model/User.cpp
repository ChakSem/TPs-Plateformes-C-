#include "User.h"
#include "Profile.h"

QString User::getId() const {
    return id;
}

QString User::getLastname() {
    return lastname;
}

void User::setLastname(const QString& newLastname) {
    lastname = newLastname;
}

QString User::getFirstname() {
    return firstname;
}

void User::setFirstname(const QString& newFirstname) {
    firstname = newFirstname;
}

QList<Profile*> User::getProfiles() {
    return profiles;
}

void User::addProfile(const Profile& profile) {
    profiles.push_back(new Profile(profile));
}

void User::deleteProfile(const QString title) {
    for(QList<Profile*>::const_iterator iter = profiles.constBegin(); iter != profiles.constEnd(); ++iter) {
        if(title == (*iter)->getTitle()) {
            delete *iter;
            profiles.erase(iter);
            break;
        }
    }
}

User& User::operator=(const User& user) {
    // On ne recopie pas l'id (Pas la même personne)
    lastname = QString(user.lastname);
    firstname = QString(user.lastname);
    lastname = QString();

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : user.profiles) {
        addProfile(*newProfile);
    }

    return *this;
}

User::User() {} // Méthode privé, inutile de la définir

User::User(const User& user){
    operator=(user);
}

User::User(const QString& newFirstname, const QString& newLastname) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;
}

User::User(const QString& newFirstname, const QString& newLastname, const QList<Profile*>& newProfiles) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : newProfiles) {
        addProfile(*newProfile);
    }
}

User::User(const QString& newId, const QString& newFirstname, const QString& newLastname) {
    id = newId;
    lastname = newLastname;
    firstname = newFirstname;
}

User::~User() {
    for(Profile* profile : profiles) {
        delete profile;
    }
}
