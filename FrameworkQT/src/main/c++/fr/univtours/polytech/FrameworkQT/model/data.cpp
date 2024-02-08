#include "data.h"

Data::Data() {
    // INITIALISER A PARTIR DES FICHIERS .JSON
}

User* Data::getUser(std::string id)
{
    return users[id];
}

void Data::addUser(User* user) {
    users[user->getId()] = user;
}

QMap<std::string, User*> Data::getUsers() {
    return users;
}
