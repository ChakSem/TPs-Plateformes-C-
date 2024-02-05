#include <iostream>
#include <unordered_map>
#include <string>

#include "User.h"

#ifndef DATA_H
#define DATA_H 1

class Data
{
private:
    Data* instance;
    //Map des données des utilisateurs ( clé: id de l'utilisateur, valeur: l'utilisateur) 
    std::unordered_map<std::string, User> users;
    Data();
    
public:
    //Signleton
    Data* getInstance();
    
    //Recuperer un utilisateur avec son id
    User getUser(std::string id);
    
};

#endif // DATA_H
