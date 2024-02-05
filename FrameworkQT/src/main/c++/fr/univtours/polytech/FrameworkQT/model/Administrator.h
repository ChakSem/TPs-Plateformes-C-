#include <string>
#include <vector>
#include "UUID.h"


#ifndef ADMINISTRATOR
#define ADMINISTRATOR 1

#include "User.h"
class Profile;

class Administrator : public User {
public :
    //Methode liées a l'administration d'un utilsateur 
    void createUser( std::string newFirstname, std::string newLastname, std::string newPassword);
    void deleteUser( std::string userId);
    void updateUser( std::string userId, std::string newFirstname, std::string newLastName, std::string newPassword);

    //Methode liées a l'administration des profils
    void createProfile(std::string profileTitle);
    void deleteProfile(std::string profileTitle);
    
    //Methode liées a l'administration des BDD
    void createDatabase(std::string databaseName);
    void deleteDatabase(std::string id);
    
    Administrator();
};

#endif