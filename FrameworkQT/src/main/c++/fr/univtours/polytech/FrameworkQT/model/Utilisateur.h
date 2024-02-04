#include <stdio.h>
#include <stdlib.h>
#include <UUID.h>
#include <Profil.h>
#include <iostream>
#include <string>
#include <map>



#ifndef UTILISATEUR
#define UTILISATEUR 1

class Utilisateur {
private :
    //Gestion attribution id dynamique
    std :: string id;
    std::string lastname;
    std::string firstname;
    std::vector<Profil> profils;

public :

    Utilisateur():id(uuid::generate_uuid_v4()){};//on genere un id unique pour chaque utilisateur
    unsigned long int getId();
    void setId(const std::string& newId);
    std::string getLastname();
    void setLastname(std::string& newLastname);
    std::string getFirstname();
    void setFirstname(std::string& newFirstname);
    
};

#endif