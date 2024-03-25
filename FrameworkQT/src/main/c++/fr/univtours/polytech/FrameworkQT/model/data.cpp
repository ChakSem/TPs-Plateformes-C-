#include "data.h"

#include "../parseurJson/parserJson.h"
#include "../utils/Exception.h"
#include "../parseurSqlite/parsersqlite.h"

#include <QDebug>
/* Accesseurs de l'attribut users */
void Data::addUser(User* user) {
    users.insert(user->getId(), user);
}

QMap<QString, User*> Data::getUsers() {
    return users;
}

 /* Accesseurs de l'attribut administrators */
void Data::addAdministrator(User* administrator) {
    administrators.insert(administrator->getId(), administrator);
}

QMap<QString, User*> Data::getAdministrators() {
    return administrators;
}


/* Accesseur communs */
/**
 * Renvoi un pointeur sur l'objet User correspondant à l'id en paramètre
 * Entree : id, QString
 * Sortie : User*
 */
User* Data::getUser(QString id) {
    try {
        /* Si il s'agit d'un utilisateur */
        if(users.contains(id)) {
            return users[id];
        }
        /* Sinon, s'il s'agit d'un admin */
        if(administrators.contains(id)) {
            return administrators[id];
        }

        /* Sinon, il n'existe pas */
        throw new Exception(ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID);
    }

    catch(Exception* e) {
        e->EXCAffichageErreur();
        delete e;
        return NULL;
    }
}

/**
 * Supprime l'objet User correspondant à l'id en paramètre
 * Entree : id, QString
 * Sortie :
 */
void Data::removeUser(QString id) {
    try {
        /* Si il s'agit d'un utilisateur */
        if(users.contains(id)) {
            User* userToDelete = users[id];
            users.remove(id);

            delete userToDelete;
        } else {
            /* Sinon, s'il s'agit d'un admin */
            if (administrators.contains(id)) {
                User* userToDelete = administrators[id];
                administrators.remove(id);

                delete userToDelete;
            }
            /* Sinon, il n'existe pas */
            else {
                throw new Exception(ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID);
            }
        }
    }

    catch(Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}

/* Méthode avec la gestion de sessions */
unsigned int Data::typeOfConnectedUser() {
    return isAdmin; // Indique si l'utilisateur connecté est admin ou user
}

User* Data::getUserConnected() {
    return userConnected;
}

/**
 * Gere la connexion de l'utilisateur en parametre
 * Entree : user, User*
 *          isAdminParam, unsigned int : indique s'il s'agit d'un admin ou d'un user
 * Sortie :
 */
void Data::connect(User* user, unsigned int isAdminParam) {
    try {
        /* Si la valeur de isAdminParam n'a aucun sens */
        if(isAdminParam != NOTADMIN && isAdminParam != ADMIN) {
            throw new Exception(ERREUR_ISADMIN_INCORRECT);
        }

        userConnected = user;
        isAdmin = isAdminParam;
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}

/**
 * Gere la déconnexion de l'utilisateur actuellement connecté
 * Entree :
 * Sortie :
 */
void Data::disconnect() {
    userConnected = NULL;
    isAdmin = ERROR;
}

/* Accesseurs de l'attibut userProfiles */
void Data::setUserProfiles(User* user) {
    userProfiles = user;
}

void Data::clearUserProfiles() {
    userProfiles = NULL; // On retire la réference qui été stockée dans userProfiles
}

User* Data::getUserProfiles() {
    return userProfiles;
}

/* Accesseurs de l'attibut userProfiles */
void Data::setProfileDatabases(Profile* profile) {
    profileDatabases = profile;
}

void Data::clearProfileDatabases() {
    profileDatabases = NULL;
}

Profile* Data::getProfileDatabases() {
    return profileDatabases;
}

/* Accesseurs de l'attibut openedDatabase */
void Data::openDatabase(QString filePath) {
    openedDatabase = new parserSqlite(filePath);
}

parserSqlite* Data::getOpenedDatabase() {
    return openedDatabase;
}

void Data::closeDatabase() {
    delete openedDatabase;
    openedDatabase = NULL;
}

/* Destructeur, qui sera appelé automatiquement à la fin du programme */
Data::~Data() {
    parserJson::saveData(*this);

    for(User* user : users) {
        delete user;
    }
    for(User* administrator : administrators) {
        delete administrator;
    }
}

/* Constructeurs et opérateur = à ne pas utiliser (Singleton) */
Data::Data() {
    parserJson::updateData(*this);
}
