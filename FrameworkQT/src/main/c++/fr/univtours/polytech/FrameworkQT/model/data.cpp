#include "data.h"

Data::Data() {
    // INITIALISER A PARTIR DES FICHIERS .JSON
}

User* Data::getUser(QString id)
{
    return users[id];
}

void Data::addUser(User* user) {
    users[user->getId()] = user;
}

QMap<QString, User*> Data::getUsers() {
    return users;
}
