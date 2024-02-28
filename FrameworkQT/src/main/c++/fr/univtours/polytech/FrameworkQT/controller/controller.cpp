#include <cstdio>
#include <cstdlib>

#include "QString"
#include "controller.h"
#include "../parseurJson/CparserJson.h"
#include "../model/Data.h"
#include "../utils/exception.h"

/* Accesseurs en lecture des attributs de Data */
/**
 * "Accesseur en lecture" de l'attribut profiles de User, ajoute l'élement en parametre à l'attribut profiles
 * Entrée : profile, Profile&
 * Sortie :
 */
User *Controller::getUserConnected()
{
    return Data::getInstance().getUserConnected();
}
/**
 * "Accesseur en lecture" de l'attribut profiles de User, ajoute l'élement en parametre à l'attribut profiles
 * Entrée : profile, Profile&
 * Sortie :
 */
User *Controller::getUserProfiles()
{
    Data::getInstance().getUserProfiles();
}
/**
 * "Accesseur en lecture" de l'attribut profiles de User, ajoute l'élement en parametre à l'attribut profiles
 * Entrée :
 * Sortie :
 */
User *Controller::getUser(QString id)
{
    return Data::getInstance().getUser(id);
}

/* Gestion de la session */
/**
 * Verifie que les logins sont correctes puis réalise la connection
 * Entree : id, QString
 *          password, QString
 * Sortie : unsigned int :  - SUCCESS_ADMIN : si les logins sont bons et s'il s'agit d'un admin
 *                          - SUCCESS_USER : si les logins sont bons et qu'il s'agit d'un user
 *                          - ERROR : si ca s'est mal passé
 */
unsigned int Controller::connection(const QString id, QString password)
{

    if (CparserJson::getPassword(id) != password)
    {
        return ERROR;
    }

    User *user = Data::getInstance().getUser(id);

    if (Data::getInstance().getAdministrators().contains(id))
    {
        Data::getInstance().connect(user, ADMIN);

        return SUCCESS_ADMIN;
    }
    else
    {
        Data::getInstance().connect(user, USER);

        return SUCCESS_USER;
    }
    return ERROR;
}

int Controller::isAdmin()
{
    return Data::getInstance().typeOfConnectedUser();
}

void Controller::deconnection()
{
    Data::getInstance().disconnect();
}

/* Gestion des données nécessaires aux interfaces liés aux objets Profile */
/**
 * Initialise userProfiles par rapport à l'utilisateur connecté
 * Entree :
 * Sortie :
 */
void Controller::openUserProfilesForCurrentUser()
{
    User *userConnected = Data::getInstance().getUserConnected();
    try
    {
        if (userConnected == NULL)
        {
            // TODO : Exception
        }

        openUserProfiles(userConnected);
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

/**
 * Initialise userProfiles par rapport à l'utilisateur en paramètre
 * Entree : userProfiles, User*
 * Sortie :
 */
void Controller::openUserProfiles(User *userProfiles)
{
    Data::getInstance().setUserProfiles(userProfiles);
}

/**
 * Ré-initialise userProfiles
 * Entree :
 * Sortie :
 */
void Controller::closeUserProfiles()
{
    Data::getInstance().clearUserProfiles();
}

unsigned int Controller::hasProfiles()
{
    User *userProfiles = getUserProfiles();

    if (userProfiles->getProfiles().size() == 0)
    {
        return NO_PROFILES;
    }
    else
    {
        return SOME_PROFILES;
    }
}

Profile *Controller::getProfileByTitle(QString profileTitle)
{
    for (Profile *profile : getUserProfiles()->getProfiles())
    {
        if (profile->getTitle() == profileTitle)
        {
            return profile;
        }
    }

    return NULL;
}

/* Gestion d'objets User */
/**
 * Crée un nouvel objet User vis à vis des données en parametre
 * Entree : firstname, QString
 *          lastname, QString
 *          password, QString
 *          roleValue, unsigned int :   - ROLE_ADMIN s'il faut créer un admin
 *                                      - ROLE_USER sinon
 * Sortie : User*
 */
User *Controller::createUser(QString firstname, QString lastname, QString password, unsigned int roleValue)
{
    User *newUser = new User(firstname, lastname);

    try
    {
        switch (roleValue)
        {
        case ROLE_ADMIN:
            Data::getInstance().addAdministrator(newUser);
            break;
        case ROLE_USER:
            Data::getInstance().addUser(newUser);
            break;
        default:
            throw new Exception(ERREUR_AUCUN_ROLE_CORRESPONDANT);
        }
        CparserJson::setPassword(newUser->getId(), password);

        return newUser;
    }

    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        return NULL;
    }
}

/**
 * Supprime l'objet User correspondant à l'id en paramètre
 * Entree : id, QString
 * Sortie : User*
 */
void Controller::deleteUser(QString id)
{
    Data::getInstance().removeUser(id);
}

/* Gestion d'objets Profile */
/**
 * Crée un nouvel objet Profile vis à vis des données en parametre
 * Entree : name, QString
 *         rightValue, unsigned int :   - DROIT_LECTURE Permet d'avoir le droit de lire
 *                                     - DROIT_LECTURE_MODIFICATION Permet d'avoir le droit de lire et de modifier
 *                                    - DROIT_LECTURE_MODIFICATION_ECRITURE_SUPPRESSION Permet d'avoir le droit de lire, de modifier, d'écrire et de supprimer (Droit reservé à l'admin uniquement)
 * Sortie : User*
 */
void Controller::createProfile(QString name, unsigned int rightValue)
{
    Rights right;
    User *user = Data::getInstance().getUserProfiles();

    try
    {
        switch (rightValue)
        {
        case DROIT_LECTURE:
            right = Rights::LECTURE;
            break;
        case DROIT_LECTURE_MODIFICATION:
            right = Rights::LECTURE_MODIFICATION;
            break;
        case DROIT_LECTURE_MODIFICATION_ECRITURE_SUPPRESSION:
            right = Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION;
            break;
        default:
            throw new Exception(ERREUR_AUCUN_DROIT_CORRESPONDANT);
        }

        Profile *newProfile = new Profile(user, name, right);

        user->addProfile(*newProfile);
        delete newProfile;
    }

    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

/**
 * Supprime l'objet Profile correspondant à l'id en paramètre
 * Entree : id, QString
 * Sortie : User*
 */
void Controller::deleteProfile(QString idUser, QString profileName)
{
    Data::getInstance().getUser(idUser)->deleteProfile(profileName);
}
/**
 *Méthode pour vérifier si des utilisateurs sont présents
 * Entrée :
 * Sortie : unsigned int :  - NO_USERS : s'il n'y a pas d'utilisateurs
 *                         - SOME_USERS : s'il y a des utilisateurs
 */
unsigned int Controller::isThereUsers()
{
    if (Data::getInstance().getUsers().size() == 0)
    {
        return NO_USERS;
    }
    else
    {
        return SOME_USERS;
    }
}
