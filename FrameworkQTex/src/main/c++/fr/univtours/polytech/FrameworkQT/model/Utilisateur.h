#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef UTILISATEUR
#define UTILISATEUR 1

class Utilisateur {
private :
    //Gestion attribution id dynamique

    unsigned long int id;
    std::string lastname;
    std::string firstname;
    // Profil

public :
    unsigned long int getId();
    void setId(unsigned long int newId);
    std::string getLastname();
    void setLastname(std::string newLastname);
    std::string getFirstname();
    void setFirstname(std::string newFirstname);

    Utilisateur();
};

#endif