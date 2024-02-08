#include <iostream>
#include <unordered_map>
#include <string>

#include "User.h"
#include "qmap.h"

#ifndef DATA_H
#define DATA_H 1

class Data
{
private:
    //Map des données des utilisateurs ( clé: id de l'utilisateur, valeur: l'utilisateur)
    QMap<std::string, User*> users;
    Data();
    
public:
    //Singleton
    static Data& getInstance()
        {
            static Data instance;
            return instance;
        }
    
    //Recuperer un utilisateur avec son id
    User* getUser(std::string id);
    void addUser(User* user);
    QMap<std::string, User*> getUsers();
};

#endif // DATA_H
