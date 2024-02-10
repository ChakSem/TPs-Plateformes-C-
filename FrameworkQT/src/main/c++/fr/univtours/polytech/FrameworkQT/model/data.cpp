#include "data.h"

#include "../parseurJson/CparserJson.h"

User* Data::getUser(QString id)
{
    return users[id];
}

void Data::addUser(User* user) {
    users.insert(user->getId(), user);
}

QMap<QString, User*> Data::getUsers() {
    return users;
}

Administrator* Data::getAdministrator(QString id)
{
    return administrators[id];
}

void Data::addAdministrator(Administrator* administrator) {
    users.insert(administrator->getId(), administrator);
    administrators.insert(administrator->getId(), administrator);
}

QMap<QString, Administrator*> Data::getAdministrators() {
    return administrators;
}

Data::~Data() {
    CparserJson::saveData(*this);

    for(User* user : users) {
        delete user;
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
