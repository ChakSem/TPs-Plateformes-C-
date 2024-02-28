#include <algorithm>
#include "Profile.h"
#include "User.h"
#include "../utils/exception.h"

#define PASTROUVE 0
#define TROUVE 1

QString Profile::getTitle()
{
    return title;
}

/**
 * Fonction cherchant si un intitulé de profil est unique
 *
 * Entrée : - profiles, const QList<Profile*>&
 *          - newTitle, const QString&
 * Sortie : - PASTROUVE, (ou 0) si newTitle est bel et bien unique
 *          - TROUVE, (ou 1) si newTitle a déjà été affecté à un profil
 */
int searchTitle(const QList<Profile *> &profiles, const QString &newTitle)
{
    for (Profile *profile : profiles)
    {
        if (profile->getTitle() == newTitle)
        {
            return TROUVE;
        }
    }

    return PASTROUVE;
}

/**
 * Accesseur de l'attribut title
 * Entree : - newTitle, const QString&
 * Sortie :
 */
void Profile::setTitle(const QString &newTitle)
{
    try
    {
        // On vérifie que le titre est unique
        if (searchTitle(user->getProfiles(), newTitle) == TROUVE)
        {
            throw new Exception(NOM_PROFIL_DEJA_ATTRIBUE);
        }

        title = newTitle;
    }

    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

/*Accesseur de l'attribut right */
Rights Profile::getRight()
{
    return right;
}

void Profile::setRight(const Rights &newRight)
{
    right = newRight;
}

/* Accesseurs de l'attribut databases */
QList<QString *> Profile::getDatabases()
{
    return databases;
}
/**
 * Ajoute une base de données à la liste des bases de données
 * Entree : - newDatabase, const QString&
 * Sortie :
 */
void Profile::addDataBase(const QString &newDatabase)
{
    /* Foncteur qui ajoute une base de données à la liste des bases de données (si (son nom)  n'est pas déjà présente dans la liste) */
    struct Search
    {
        QString newDatabase;
        Search(QString db) : newDatabase(db) {}
        void operator()(const QString *n) { find += *n == newDatabase; }
        int find{0};
    };

    Search s(newDatabase);

    // On vérifie que la base de données n'est pas déjà présente
    std::for_each(databases.begin(), databases.end(), s);
    try
    {
        if (s.find > 0)
        {
            throw new Exception(BASE_DE_DONNEE_DEJA_AJOUTEE);
        }
        else
        {
            databases.append(new QString(newDatabase));
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
    }
}

/* Surcharge de l'opérateur = (pour copier un profil) */
Profile &Profile::operator=(const Profile &profile)
{
    user = profile.user;

    QString uniqueTitle = profile.title;
    int copyCount = 1;
    
    /* On incremente un entier, ajouté à la fin de newTile, jusqu'à avoir une chaîne unique */
    while (searchTitle(user->getProfiles(), uniqueTitle) == TROUVE)
    {
        uniqueTitle = profile.title + QString::number(copyCount);
        copyCount++;
    }
    title = uniqueTitle;
    right = profile.right;

    /* On copie et ajoute les noms de base de données un à un */
    for (QString *str : profile.databases)
    {
        databases.append(new QString(*str));
    }
    return *this;
}

Profile::Profile(const Profile &profile)
{
    operator=(profile);
}

/**
 * Constructeur de la classe Profile
 * Entree : - actualUser, User*
 *          - newTitle, const QString&
 * Sortie :
 */
Profile::Profile(User *actualUser, const QString &newTitle)
{
    user = actualUser;

    /* On incremente un entier, ajouté à la fin de newTile, jusqu'à avoir une chaîne unique */
    QString uniqueTitle = newTitle;
    int copyCount = 1;
    while (searchTitle(user->getProfiles(), uniqueTitle) == TROUVE)
    {
        uniqueTitle = newTitle + QString::number(copyCount);
        copyCount++;
    }
    title = uniqueTitle;
    right = Rights::LECTURE;
}

/**
 * Constructeur de la classe Profile
 * Entree : - actualUser, User*
 *          - newTitle, const QString&
 *          - newRight, const Rights&
 * Sortie :
 */
Profile::Profile(User *actualUser, const QString &newTitle, const Rights &newRight)
{
    user = actualUser;

    /* On incremente un entier, ajouté à la fin de newTile, jusqu'à avoir une chaîne unique */
    QString uniqueTitle = newTitle;
    int copyCount = 1;
    while (searchTitle(user->getProfiles(), uniqueTitle) == TROUVE)
    {
        uniqueTitle = newTitle + QString::number(copyCount);
        copyCount++;
    }
    title = uniqueTitle;
    right = newRight;
}

/**
 * Constructeur de la classe Profile
 * Entree : - actualUser, User*
 *          - newTitle, const QString&
 *          - newRight, const Rights&
 *          - newDataBases, const QList<QString*>&
 * Sortie :
 */
Profile::Profile(User *actualUser, const QString &newTitle, const Rights &newRight, const QList<QString *> &newDataBases)
{
    user = actualUser;

    /* On incremente un entier, ajouté à la fin de newTile, jusqu'à avoir une chaîne unique */
    QString uniqueTitle = newTitle;
    int copyCount = 1;
    
    // On vérifie que le titre est unique
    while (searchTitle(user->getProfiles(), uniqueTitle) == TROUVE)
    {
        uniqueTitle = newTitle + QString::number(copyCount);
        copyCount++;
    }
    title = uniqueTitle;
    right = newRight;

    /* On copie et ajoute les noms de base de données un à un */
    for (QString *str : newDataBases)
    {
        databases.append(new QString(*str));
    }
}

Profile::~Profile()
{
}
