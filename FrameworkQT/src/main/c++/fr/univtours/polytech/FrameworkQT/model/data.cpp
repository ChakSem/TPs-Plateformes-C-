#include "data.h"

Data::Data() {
    users = std::unordered_map<std::string, User*>();
    // INITIALISER A PARTIR DES FICHIERS .JSON
}

User* Data::getUser(std::string id)
{
    return users[id];
}

void Data::addUser(User* user) {
    users[user->getId()] = user;
}

std::unordered_map<std::string, User*> Data::getUsers() {
    return users;
}