#include "Administrator.h"
#include "Data.h"

void createUser(std::string newFirstname, std::string newLastname, std::string newPassword)
{
    User* newUser = new User();
    newUser->setFirstname(newFirstname);
    newUser->setLastname(newLastname);
    
    //, newPassword);
    users.push_back(*newUser);
}

void deleteUser(std::string userId)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == userId)
        {
            users.erase(users.begin() + i);
            break;
        }
    }
}

void updateUser(std::string userId, std::string newFirstname, std::string newLastName, std::string newPassword)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == userId)
        {
            users[i].setFirstname(newFirstname);
            users[i].setLastname(newLastName);
            users[i].setPassword(newPassword);
            break;
        }
    }
}

// Methode liées a l'administration des profils
void createProfile(std::string profileTitle);
{
    Profile newProfile = new Profile(profileTitle);
    profiles.push_back(newProfile);
}

void deleteProfile(std::string profileTitle);
{
    for (int i = 0; i < profiles.size(); i++)
    {
        if (profiles[i].getTitle() == profileTitle)
        {
            profiles.erase(profiles.begin() + i);
            break;
        }
    }
}

// Methode liées a l'administration des BDD
void createDatabase(std::string databaseName);
void deleteDatabase(std::string id);