#include "Administrator.h"
#include "Data.h"
#include "Profile.h"

void Administrator::createUser(QString newFirstname, QString newLastname, QString newPassword)
{
    User* newUser = new User();
    newUser->setFirstname(newFirstname);
    newUser->setLastname(newLastname);
    
    Data data = Data::getInstance();

    //, newPassword);
    data.addUser(newUser);
}

void Administrator::deleteUser(QString userId)
{
    QMap<QString, User*> users = Data::getInstance().getUsers();

    for(QMap<QString, User*>::iterator iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter.key() == userId)
        {
            delete iter.value();
            users.erase(iter);
            break;
        }
    }
}

void Administrator::updateUser(QString userId, QString newFirstname, QString newLastName, QString newPassword)
{
    QMap<QString, User*> users = Data::getInstance().getUsers();
    
    for(QMap<QString, User*>::iterator iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter.key() == userId)
        {
            iter.value()->setFirstname(newFirstname);
            iter.value()->setLastname(newLastName);
            //iter->second->setPassword(newPassword);
            break;
        }
    }
}

// Methode liées a l'administration des profils
void Administrator::createProfile(User* actualUser, QString profileTitle)
{
    Profile* newProfile = new Profile(actualUser, profileTitle);
    actualUser->addProfile(newProfile);
}

void Administrator::deleteProfile(User* actualUser, QString profileTitle)
{
    actualUser->deleteProfile(profileTitle);
}

// Methode liées a l'administration des BDD
void Administrator::createDatabase(QString databaseName) {
    // TODO
}

void Administrator::deleteDatabase(QString id){
    // TODO
}
