#include "data.h"

#include "../parseurJson/CparserJson.h"
#include "../utils/Exception.h"

User* Data::getUser(QString id)
{
    try {
        if(users.contains(id)) {
            return users[id];
        }
        if(administrators.contains(id)) {
            return administrators[id];
        }

        throw new Exception(ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID);
    }

    catch(Exception* e) {
        e->EXCAffichageErreur();
        return NULL;
    }
}

void Data::addUser(User* user) {
    users.insert(user->getId(), user);
}

QMap<QString, User*> Data::getUsers() {
    return users;
}

void Data::addAdministrator(User* administrator) {
    administrators.insert(administrator->getId(), administrator);
}

QMap<QString, User*> Data::getAdministrators() {
    return administrators;
}

unsigned int Data::typeOfConnectedUser() {
    return isAdmin;
}


User* Data::getUserConnected() {
    return userConnected;
}

void Data::connect(User* user, unsigned int isAdminParam) {
    try {
        if(isAdminParam != NOTADMIN && isAdminParam != ADMIN) {
            throw new Exception(ERREUR_ISADMIN_INCORRECT);
        }

        userConnected = user;
        isAdmin = isAdminParam;
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void Data::disconnect() {
    userConnected = NULL;
    isAdmin = ERROR;
}

void Data::setUserProfiles(User* user) {
    userProfiles = user;
}

void Data::clearUserProfiles() {
    userProfiles = NULL;
}

Data::~Data() {
    CparserJson::saveData(*this);

    for(User* user : users) {
        delete user;
    }
    for(User* administrator : administrators) {
        delete administrator;
    }
}

Data::Data() {
    CparserJson::updateData(*this);
}

Data::Data(const Data&) {

}

Data& Data::operator=(const Data&) {
    return *this;
}
