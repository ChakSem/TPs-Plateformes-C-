#include "data.h"

Data::Data() {
    users = std::unordered_map<std::string, User>();
    // INITIALISER A PARTIR DES FICHIERS .JSON
}

Data* Data::getInstance() {
    if(instance == NULL) {
        instance = new Data();
    }

    return instance;
}

User Data::getUser(std::string id)
{
    return users[id];
}
