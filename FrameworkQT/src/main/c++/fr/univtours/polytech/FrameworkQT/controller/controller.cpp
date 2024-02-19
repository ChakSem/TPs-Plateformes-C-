#include <cstdio>
#include <cstdlib>

#include "QString"
#include "controller.h"
#include "../parseurJson/CparserJson.h"
#include "../model/Data.h"
#include "../utils/exception.h"


User* Controller::Connection(const QString id, QString password) {
    if(CparserJson::getPassword(id) != password) {
        return NULL;
    }

    return Data::getInstance().getUser(id);
}

void Controller::deleteUser(QString id) {
    try {
        QMap<QString, User*> users = Data::getInstance().getUsers();
        if(users.contains(id)) {
            User* userToDelete = users[id];
            users.remove(id);

            delete userToDelete;
        } else {
            QMap<QString, User*> admins = Data::getInstance().getAdministrators();
            if (admins.contains(id)) {
                User* userToDelete = admins[id];
                users.remove(id);

                delete userToDelete;
            } else {
                throw new Exception(ERREURAUCUNUTILISATEURNECORRESPONDACETID);
            }
        }
    }

    catch(Exception* e) {
        e->EXCAffichageErreur();
    }
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
            throw new Exception(ERREURAUCUNROLECORRESPONDANT);
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
            throw new Exception(ERREURAUCUNDROITCORRESPONDANT);
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
