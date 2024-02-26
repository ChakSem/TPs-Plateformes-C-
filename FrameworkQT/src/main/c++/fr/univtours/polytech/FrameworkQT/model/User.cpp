#include "User.h"
#include "Profile.h"


/*Getteur de l'attribut Id */
QString User::getId() {
    return id;
}

/*Accesseur de l'attribut lastname */
QString User::getLastname() {
    return lastname;
}

void User::setLastname(const QString& newLastname) {
    lastname = newLastname;
}

/*Accesseur de l'attribut firstname */
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

/*Méthode pour supprimer un profil (en fonction de son titre) */
void User::deleteProfile(const QString title) {
    for(QList<Profile*>::const_iterator iter = profiles.constBegin(); iter != profiles.constEnd(); ++iter) {
        if(title == (*iter)->getTitle()) {
            delete *iter;
            profiles.erase(iter);
            break;
        }
    }
}

/*Surcharge de l'opérateur = , pour copier un utilisateur */
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
