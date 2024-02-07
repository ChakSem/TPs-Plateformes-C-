#include "Administrator.h"
#include "Data.h"
#include "Profile.h"

void Administrator::createUser(std::string newFirstname, std::string newLastname, std::string newPassword)
{
    User* newUser = new User();
    newUser->setFirstname(newFirstname);
    newUser->setLastname(newLastname);
    
    Data data = Data::getInstance();

    //, newPassword);
    data.addUser(newUser);
}

void Administrator::deleteUser(std::string userId)
{
    std::unordered_map<std::string, User*> users = Data::getInstance().getUsers();

    for(std::unordered_map<std::string, User*>::iterator iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter->first == userId)
        {
            users.erase(iter->first);
            break;
        }
    }
}

void Administrator::updateUser(std::string userId, std::string newFirstname, std::string newLastName, std::string newPassword)
{
    std::unordered_map<std::string, User*> users = Data::getInstance().getUsers();
    
    for(std::unordered_map<std::string, User*>::iterator iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter->first == userId)
        {
            iter->second->setFirstname(newFirstname);
            iter->second->setLastname(newLastName);
            //iter->second->setPassword(newPassword);
            break;
        }
    }
}

// Methode liées a l'administration des profils
void Administrator::createProfile(User* actualUser, std::string profileTitle)
{
    Profile* newProfile = new Profile(actualUser, profileTitle);
    actualUser->addProfile(newProfile);
}

void Administrator::deleteProfile(User* actualUser, std::string profileTitle)
{
    actualUser->deleteProfile(profileTitle);
}

// Methode liées a l'administration des BDD
void createDatabase(std::string databaseName);
void deleteDatabase(std::string id);