#include <qstring>

#include "User.h"
#include "qmap.h"

#ifndef DATA_H
#define DATA_H 1

#define ERROR 0
#define ADMIN 1
#define NOTADMIN 2

class Data
{
private:
    User* userConnected;
    unsigned int isAdmin;

    //Map des données des utilisateurs ( clé: id de l'utilisateur, valeur: l'utilisateur)
    QMap<QString, User*> users;
    QMap<QString, User*> administrators;
    
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

    unsigned int typeOfConnectedUser();
    void connect(User* user, unsigned int isAdminParam);
    void disconnect();

private :
/* Destructeur, sera appelé automatiquement à la fin du programme */
    ~Data();

/* Constructeurs et opérateur = à ne pas utiliser (Singleton) */
    Data();
    Data(const Data&);
    Data& operator=(const Data&);
};

#endif // DATA_H
