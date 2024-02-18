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

        throw new Exception(ERREURAUCUNUTILISATEURNECORRESPONDACETID);
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
    users.insert(administrator->getId(), administrator);
    administrators.insert(administrator->getId(), administrator);
}


QMap<QString, User*> Data::getAdministrators() {
    return administrators;
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
