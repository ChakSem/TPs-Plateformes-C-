#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "QString"
#include "../model/User.h"

class Controller
{
public:
    static User* Connection(QString id, QString password);
    static void deleteUser(QString id);
    static User* createUser(QString firstname, QString lastname, QString password, unsigned int roleValue);
    static Profile* createProfile(User* user, QString name, unsigned int rightValue);
    static void deleteProfile(QString idUser, QString profileName);

private:
    Controller();
    Controller(Controller& copy);
    ~Controller();
};

#endif // CONTROLLER_H
