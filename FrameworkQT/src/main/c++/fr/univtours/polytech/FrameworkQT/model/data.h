#include <qstring>

#include "user.h"
#include "qmap.h"

#ifndef DATA_H
#define DATA_H 1

#define ERROR 0
#define ADMIN 1
#define NOTADMIN 2

class parserSqlite;

class Data
{
private:
    /* On stocke l'utilisateur qui est connecté ainsi que son role */
    User* userConnected;
    unsigned int isAdmin;

    User* userProfiles; // Permettra de stocké l'utilisateur dont on visionne les profils pour la vue Profiles

    Profile* profileDatabases; // Permettra de stocké le profil visionné

    /* Map des données des utilisateurs ( clé: id de l'utilisateur, valeur: l'utilisateur) */
    QMap<QString, User*> users;
    QMap<QString, User*> administrators;

    /* Gerera le stockge de la base de donnee ouverte dans les vues database */
    parserSqlite* openedDatabase;
    
public:
    //Singleton
    static Data& getInstance()
        {
            static Data instance;
            return instance;
        }
    
    /* Accesseurs de l'attribut users */
    QMap<QString, User*> getUsers();
    void addUser(User* user);

    /* Accesseurs de l'attribut administrators */
    QMap<QString, User*> getAdministrators();
    void addAdministrator(User* administrator);

    /* Accesseur commun */
    User* getUser(QString id);
    void removeUser(QString id);

    /* Méthode avec la gestion de sessions */
    unsigned int typeOfConnectedUser();
    void connect(User* user, unsigned int isAdminParam);
    void disconnect();
    User* getUserConnected();

    /* Accesseurs de l'attibut userProfiles */
    void setUserProfiles(User* user);
    void clearUserProfiles();
    User* getUserProfiles();

    /* Accesseurs de l'attibut userProfiles */
    void setProfileDatabases(Profile* profile);
    void clearProfileDatabases();
    Profile* getProfileDatabases();

    /* Accesseurs de l'attibut openedDatabase */
    void openDatabase(QString filePath);
    parserSqlite* getOpenedDatabase();
    void closeDatabase();

private :
    /* Destructeur, sera appelé automatiquement à la fin du programme */
    ~Data();

    /* Constructeurs et opérateur = à ne pas utiliser (Singleton) */
    Data();
    Data(const Data&);
    Data& operator=(const Data&);
};

#endif // DATA_H
