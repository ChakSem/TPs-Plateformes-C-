#include "data.h"

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

Data::~Data() {
    // TODO : sérialisation des données dans les fichiers .json

    for(User* user : users) {
        delete user;
    }
}

Data::Data() {
    // TODO : initialisation à partir des de la désérialisation des fichiers .json
}

Data::Data(const Data&) {

}

Data& Data::operator=(const Data&) {
    return *this;
}
