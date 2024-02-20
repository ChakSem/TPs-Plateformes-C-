#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "QString"
#include "../model/User.h"

#define ERROR 0
#define SUCCESS_ADMIN 1
#define SUCCESS_USER 2

#define ROLE_ADMIN 3
#define ROLE_USER 4

#define DROIT_LECTURE 5
#define DROIT_LECTURE_MODIFICATION 6
#define DROIT_LECTURE_MODIFICATION_ECRITURE_SUPPRESSION 7

class Controller
{
public:
    static unsigned int connection(QString id, QString password);
    static void deleteUser(QString id);
    static User* createUser(QString firstname, QString lastname, QString password, unsigned int roleValue);
    static Profile* createProfile(User* user, QString name, unsigned int rightValue);
    static void deleteProfile(QString idUser, QString profileName);
    static void deconnection();
    static void openUserProfilesForCurrentUser();
    static void openUserProfiles(User* userProfiles);
    static void closeUserProfiles();

private:
    Controller();
    Controller(Controller& copy);
    ~Controller();
};

#endif // CONTROLLER_H
