#include "data.h"

#include "../parseurJson/CparserJson.h"

User* Data::getUser(QString id)
{
    return users[id];
}

void Data::addUser(const User& user) {
    users.insert(user.getId(), new User(user));
}

QMap<QString, User*> Data::getUsers() {
    return users;
}

Administrator* Data::getAdministrator(QString id)
{
    return administrators[id];
}

void Data::addAdministrator(const Administrator& administrator) {
    users.insert(administrator.getId(), new User(administrator));
    administrators.insert(administrator.getId(), new Administrator(administrator));
}

QMap<QString, Administrator*> Data::getAdministrators() {
    return administrators;
}

Data::~Data() {
    // TODO : sérialisation des données dans les fichiers .json

    for(User* user : users) {
        delete user;
    }

    for(Administrator* administrator : administrators) {
        delete administrator;
    }
}

Data::Data() {
    // TODO : initialisation à partir des de la désérialisation des fichiers .json
    CparserJson::updateData(*this);
}

Data::Data(const Data&) {

}

Data& Data::operator=(const Data&) {
    return *this;
}
