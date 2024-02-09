#include <qstring>

#include "User.h"
#include "Administrator.h"
#include "qmap.h"

#ifndef DATA_H
#define DATA_H 1

class Data
{
private:
    //Map des données des utilisateurs ( clé: id de l'utilisateur, valeur: l'utilisateur)
    QMap<QString, User*> users;
    QMap<QString, Administrator*> administrators;
    
public:
    //Singleton
    static Data& getInstance()
        {
            static Data instance;
            return instance;
        }
    
    /* Accesseurs de l'attribut users */
    User* getUser(QString id);
    QMap<QString, User*> getUsers();
    void addUser(const User& user);

    /* Accesseurs de l'attribut administrators */
    Administrator* getAdministrator(QString id);
    QMap<QString, Administrator*> getAdministrators();
    void addAdministrator(const Administrator& administrator);

private :
/* Destructeur, sera appelé automatiquement à la fin du programme */
    ~Data();

/* Constructeurs et opérateur = à ne pas utiliser (Singleton) */
    Data();
    Data(const Data&);
    Data& operator=(const Data&);
};

#endif // DATA_H
