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

#define ADMIN 1
#define NOTADMIN 2

#define NO_PROFILES 0
#define SOME_PROFILES 1

#define NO_USERS 0
#define SOME_USERS 1

class CparserSqlite;

class Controller
{
public:
    /* Accesseurs en lecture des attributs de Data */
    static User* getUserConnected();
    static User* getUserProfiles();
    static User* getUser(QString id);

    /* Gestion de la session */
    static unsigned int connection(QString id, QString password);
    static int isAdmin();
    static void deconnection();

    /* Gestion des données nécessaires aux interfaces liés aux objets Profile */
    static void openUserProfilesForCurrentUser();
    static void openUserProfiles(User* userProfiles);
    static void closeUserProfiles();
    static unsigned int hasProfiles();
    static Profile* getProfileByTitle(QString profileTitle);

    /* Gestion d'objets User */
    static User* createUser(QString firstname, QString lastname, QString password, unsigned int roleValue);
    static void deleteUser(QString id);

    /* Gestion d'objets Profile */
    static void createProfile(QString name, unsigned int rightValue);
    static void deleteProfile(QString idUser, QString profileName);

    /* Gestion du profil visionneé */
    static void setProfileDatabases(Profile* profile);
    static void clearProfileDatabases();
    static Profile* getProfileDatabases();

    /* Accesseurs de l'attibut openedDatabase */
    static unsigned int removeDataBase(const QString& databaseName);
    static void openDatabase(const QString& filePath);
    static CparserSqlite* getOpenedDatabase();
    static void closeDatabase();

    /* Méthode pour le lancement de l'app */
    static unsigned int isThereUsers();

private:
    /* Contient uniquement des méthodes statiques, donc inutile de créer des objets de ce Controller */
    Controller();
    Controller(Controller& copy);
    ~Controller();
};

#endif // CONTROLLER_H
