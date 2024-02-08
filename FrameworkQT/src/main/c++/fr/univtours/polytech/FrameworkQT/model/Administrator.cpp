#include "Administrator.h"
#include "Data.h"
#include "Profile.h"

void Administrator::createUser(const QString& newFirstname, const QString& newLastname, const QString& newPassword)
{
    User* newUser = new User(newLastname, newFirstname);
    Data data = Data::getInstance();
    // ecrire mot de passe à "user.id : newPassword"

    data.addUser(newUser);
}

void Administrator::deleteUser(const QString& userId)
{
    QMap<QString, User*> users = Data::getInstance().getUsers();

    for(QMap<QString, User*>::const_iterator iter = users.constBegin(); iter != users.constEnd(); ++iter)
    {
        if (iter.key() == userId)
        {
            delete iter.value();
            users.erase(iter);
            break;
        }
    }
}

void Administrator::updateUser(const QString& userId, const QString& newFirstname, const QString& newLastName, const QString& newPassword)
{
    QMap<QString, User*> users = Data::getInstance().getUsers();
    
    for(QMap<QString, User*>::iterator iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter.key() == userId)
        {
            iter.value()->setFirstname(newFirstname);
            iter.value()->setLastname(newLastName);
            // ecrire mot de passe à "userId : newPassword"

            break;
        }
    }
}

// Methode liées a l'administration des profils
void Administrator::createProfile(User* actualUser, const QString& profileTitle)
{
    Profile* newProfile = new Profile(actualUser, profileTitle);
    actualUser->addProfile(*newProfile);
}

void Administrator::deleteProfile(User* actualUser, const QString& profileTitle)
{
    actualUser->deleteProfile(profileTitle);
}

// Methode liées a l'administration des BDD
void Administrator::createDatabase(const QString& databaseName) {
    // TODO
}

void Administrator::deleteDatabase(const QString& id){
    // TODO
}

Administrator::Administrator(const User& user) : User(user) {
}

Administrator::Administrator(const QString& newLastname, const QString& newFirstname) : User(newLastname, newFirstname) {
}

Administrator::Administrator(const QString& newLastname, const QString& newFirstname, const QList<Profile*>& newProfiles) : User(newLastname, newFirstname, newProfiles) {
}

Administrator::~Administrator() {
}
