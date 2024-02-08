#include <qstring>

#ifndef ADMINISTRATOR
#define ADMINISTRATOR 1

#include "User.h"
class Profile;

class Administrator : public User {
public :
    //Methode liées a l'administration d'un utilisateur
    void createUser(QString newFirstname, QString newLastname, QString newPassword);
    void deleteUser(QString userId);
    void updateUser(QString userId, QString newFirstname, QString newLastName, QString newPassword);

    //Methode liées a l'administration des profils
    void createProfile(User* actualUser, QString profileTitle);
    void deleteProfile(User* actualUser, QString profileTitle);
    
    //Methode liées a l'administration des BDD
    void createDatabase(QString databaseName);
    void deleteDatabase(QString id);
    
    Administrator();
};

#endif
