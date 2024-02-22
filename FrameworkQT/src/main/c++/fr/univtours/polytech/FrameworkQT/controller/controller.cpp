#include <cstdio>
#include <cstdlib>

#include "QString"
#include "controller.h"
#include "../parseurJson/CparserJson.h"
#include "../model/Data.h"
#include "../utils/exception.h"

unsigned int Controller::connection(const QString id, QString password) {
    if(CparserJson::getPassword(id) != password) {
        return ERROR;
    }

    User* user = Data::getInstance().getUser(id);

    if(Data::getInstance().getUsers().contains(id)) {
        Data::getInstance().connect(user, ADMIN);

        return SUCCESS_ADMIN;
    } else {
        Data::getInstance().connect(user, USER);

        return SUCCESS_USER;
    }
    return ERROR;
}

static unsigned int isAdmin() {
    return Data::getInstance().typeOfConnectedUser();
}

User* Controller::getUserConnected() {
    return Data::getInstance().getUserConnected();
}

User* Controller::getUser(QString id) {
    return Data::getInstance().getUser(id);
}

void Controller::deleteUser(QString id) {
    Data::getInstance().removeUser(id);
}

User* Controller::createUser(QString firstname, QString lastname, QString password, unsigned int roleValue) {
    User* newUser = new User(firstname, lastname);

    try {
        switch(roleValue) {
        case ROLE_ADMIN:
            Data::getInstance().addAdministrator(newUser);
            break;
        case ROLE_USER:
            Data::getInstance().addUser(newUser);
            break;
        default :
            throw new Exception(ERREUR_AUCUN_ROLE_CORRESPONDANT);
        }
        CparserJson::setPassword(newUser->getId(), password);

        return newUser;
    }

    catch (Exception* e) {
        e->EXCAffichageErreur();
        return NULL;
    }
}

Profile* Controller::createProfile(User* user, QString name, unsigned int rightValue) {
    Rights right;

    try {
        switch(rightValue) {
        case DROIT_LECTURE:
            right = Rights::LECTURE;
            break;
        case DROIT_LECTURE_MODIFICATION:
            right = Rights::LECTURE_MODIFICATION;
            break;
        case DROIT_LECTURE_MODIFICATION_ECRITURE_SUPPRESSION:
            right = Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION;
            break;
        default :
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);
        }

        Profile* newProfile = new Profile(user, name, right);

        return newProfile;
    }

    catch (Exception* e) {
        e->EXCAffichageErreur();
        return NULL;
    }
}

void Controller::deleteProfile(QString idUser, QString profileName) {
    User* user = Data::getInstance().getUser(idUser);
    user->deleteProfile(profileName);
}

void Controller::deconnection() {
    Data::getInstance().disconnect();
}

void Controller::openUserProfilesForCurrentUser() {
    User* userConnected = Data::getInstance().getUserConnected();
    try {
        if(userConnected == NULL) {
            // TODO : Exception
        }

        openUserProfiles(userConnected);
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void Controller::openUserProfiles(User* userProfiles) {
    Data::getInstance().setUserProfiles(userProfiles);
}

void Controller::closeUserProfiles() {
    Data::getInstance().clearUserProfiles();
}

User* Controller::getUserProfiles() {
    Data::getInstance().getUserProfiles();
}
