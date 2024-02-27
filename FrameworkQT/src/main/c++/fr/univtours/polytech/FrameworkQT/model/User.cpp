#include "User.h"
#include "Profile.h"


QString User::getId() {
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

/**
 * "Accesseur en lecture" de l'attribut profiles de User, ajoute l'élement en parametre à l'attribut profiles
 * Entrée : profile, Profile&
 * Sortie :
 */
void User::addProfile(const Profile& profile) {
    profiles.push_back(new Profile(profile));
}

/**
 * Méthode pour supprimer un profil à partir du titre passé en paramètre
 * Entrée : title, QString
 * Sortie :
 */
void User::deleteProfile(const QString title) {
    for(QList<Profile*>::const_iterator iter = profiles.constBegin(); iter != profiles.constEnd(); ++iter) {
        if(title == (*iter)->getTitle()) {
            delete *iter;
            profiles.erase(iter);
            break;
        }
    }
}

/**
 * Surcharge de l'opérateur =
 * Entrée : user, User&
 * Sortie : User&
 */
User& User::operator=(const User& user) {
    // On ne recopie pas l'id (Pas la même personne)
    lastname = QString(user.lastname);
    firstname = QString(user.firstname);

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : user.profiles) {
        addProfile(*newProfile);
    }

    return *this;
}

User::User() {} // Méthode privé, inutile de la définir

/*Constructeur de copie */
User::User(const User& user){
    id = uuid::generate_uuid_v4();
    operator=(user);
}

/*Constructeur avec les attributs (firstname, lastname) */
User::User(const QString& newFirstname, const QString& newLastname) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;
}

/*Constructeur avec les attributs (firstname, lastname, liste de profils) */
User::User(const QString& newFirstname, const QString& newLastname, const QList<Profile*>& newProfiles) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : newProfiles) {
        addProfile(*newProfile);
    }
}

/*Constructeur avec les attributs (id, firstname, lastname) */
User::User(const QString& newId, const QString& newFirstname, const QString& newLastname) {
    id = newId;
    lastname = newLastname;
    firstname = newFirstname;
}

/*Destructeur */
User::~User() {
    for(Profile* profile : profiles) {
        delete profile;
    }
}
