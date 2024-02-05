#include <stdio.h>
#include <stdlib.h>
#include <UUID.h>
#include <iostream>
#include <string>
#include <list>


#ifndef USER
#define USER 1

class Profile;

class User {
private :
    //Gestion attribution id dynamique
    std::string id;
    std::string lastname;
    std::string firstname;
    std::list<Profile> profiles;

    // User():genreateId(uuid::generate_uuid_v4()){};//on genere un id unique pour chaque utilisateur
    // //        ^ peut etre juste id 
public :
    std::string getId();
    void setId(std::string newId);
    std::string getLastname();
    void setLastname(std::string newLastname);
    std::string getFirstname();
    void setFirstname(std::string newFirstname);

    User();
};

#endif
