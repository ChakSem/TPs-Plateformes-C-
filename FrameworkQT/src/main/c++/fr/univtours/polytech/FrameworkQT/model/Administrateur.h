#include <string>
#include <vector>
#include "Profil.h"
#include "UUID.h"


#ifndef UTILISATEUR
#define UTILISATEUR 1

class Utilisateur {
private :
    //Gestion attribution id dynamique
    
    std :: string id;
    std::string lastname;
    std::string firstname;
    // Profil (Map avec l'idd et le role)
    std::vector<Profil> profil;

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