#include "User.h"
#include "Profile.h"

/**
 * "Accesseur en lecture" de l'attribut id de User, permet de récupérer l'id de l'utilisateur
 * Entrée : 
 * Sortie :
 */
QString User::getId() {
    return id;
}

/**
 * "Accesseur en lecture" de l'attribut lastname de User, permet de récupérer le nom de famille de l'utilisateur
 * Entrée : 
 * Sortie :
 */
QString User::getLastname() {
    return lastname;
}

/**
 * "Accesseur en ecriture" de l'attribut lastname de User, ajoute l'élement en parametre à l'attribut lastname
 * Entrée :  newLastname, QString
 * Sortie :
 */
void User::setLastname(const QString& newLastname) {
    lastname = newLastname;
}
/**
 * "Accesseur en lecture" de l'attribut firstname de User, ajoute l'élement en parametre à l'attribut firstname
 * Entrée : 
 * Sortie :
 */
QString User::getFirstname() {
    return firstname;
}
/**
 * "Accesseur en ecriture" de l'attribut firstname de User, ajoute l'élement en parametre à l'attribut firstname
 * Entrée : newFirstname, QString
 * Sortie :
 */
void User::setFirstname(const QString& newFirstname) {
    firstname = newFirstname;
}
/**
 * "Accesseur en lecture" de l'attribut profiles de User, permet de récupérer la liste des profils de l'utilisateur
 * Entrée : 
 * Sortie :
 */
QList<Profile*> User::getProfiles() {
    return profiles;
}

/**
 * "Accesseur en ecriture" de l'attribut profiles de User, permet d'ajouter un profil à la liste des profils de l'utilisateur
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
    /* On parcourt la liste des profils */
    for(QList<Profile*>::const_iterator iter = profiles.constBegin(); iter != profiles.constEnd(); ++iter) {
        /* Si on trouve le profil, on le supprime */
        if(title == (*iter)->getTitle()) {
            delete *iter;
            profiles.erase(iter);
            break;
        }
    }
}

/**
 * Surcharge de l'opérateur =, permet de copier un utilisateur dans un autre
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

/**
 * Constructeur de recopie, permet de copier un utilisateur dans un autre
 * Entrée : user, User&
 * Sortie : User
 */
User::User(const User& user){
    id = uuid::generate_uuid_v4();
    operator=(user);
}

/**
 * Constructeur avec les attributs (firstname, lastname)
 * Entrée : - newFirstname, QString
 *          - newLastname, QString
 * Sortie : User
 */
User::User(const QString& newFirstname, const QString& newLastname) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;
}

/**
 * Constructeur avec les attributs (firstname, lastname, profiles)
 * Entrée : - newFirstname, QString
 *          - newLastname, QString
 *          - newProfiles, QList<Profile*>
 * Sortie : User
 * */
User::User(const QString& newFirstname, const QString& newLastname, const QList<Profile*>& newProfiles) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : newProfiles) {
        addProfile(*newProfile);
    }
}

/**
 * Constructeur avec les attributs (id, firstname, lastname)
 * Entree : - newId, QString
 *         - newFirstname, QString
 *        - newLastname, QString
 * Sortie : User
 * */
User::User(const QString& newId, const QString& newFirstname, const QString& newLastname) {
    id = newId;
    lastname = newLastname;
    firstname = newFirstname;
}

/**
 * Destructeur 
 * Entree : 
 * Sortie : 
 * */
User::~User() {
    for(Profile* profile : profiles) {
        delete profile;
    }
}
