#include <qstring>

#ifndef ADMINISTRATOR
#define ADMINISTRATOR 1

#include "User.h"
class Profile;

class Administrator : public User {
public :
    //Methode liées a l'administration d'un utilisateur
    void createUser(const QString& newFirstname, const QString& newLastname, const QString& newPassword);
    void deleteUser(const QString& userId);
    void updateUser(const QString& userId, const QString& newFirstname, const QString& newLastName, const QString& newPassword);

    //Methode liées a l'administration des profils
    void createProfile(User* actualUser, const QString& profileTitle);
    void deleteProfile(User* actualUser, const QString& profileTitle);
    
    //Methode liées a l'administration des BDD
    void createDatabase(const QString& databaseName);
    void deleteDatabase(const QString& id);
    
    Administrator();
};

#endif
