#include <algorithm>
#include "Profile.h"
#include "User.h"
#include "../utils/exception.h"

#define PASTROUVE 0
#define TROUVE 1

/**
 * "Accesseur en lecture" de l'attribut title
 * Entree :
 * Sortie : - title, QString (titre du profil)
 */
QString Profile::getTitle()
{
    return title;
}

/**
 * Fonction cherchant si un intitulé de profil est unique
 *
 * Entrée : - profiles, const QList<Profile*>& (liste des profils)
 *          - newTitle, const QString& (nouveau titre à tester)
 * Sortie : - int (entier indiquant si newTitle est unique ou non)
 *              - PASTROUVE, (ou 0) si newTitle est bel et bien unique
 *              - TROUVE, (ou 1) si newTitle a déjà été affecté à un profil
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
 * "Accesseur en ecriture" de l'attribut title
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
        delete e;
    }
}

/**
 * "Accesseur en lecture" de l'attribut right
 * Entree :
 * Sortie : - right, Rights (droit du profil)
 */
Rights Profile::getRight()
{
    return right;
}

/**
 * "Accesseur en ecriture" de l'attribut right
 * Entree : - newRight, const Rights& (nouveau droit)
 * Sortie :
 */
void Profile::setRight(const Rights &newRight)
{
    right = newRight;
}

/* Accesseurs de l'attribut databases */
QMap<QString *, QString *> Profile::getDatabases()
{
    return databases;
}

QString *Profile::getPathFile(const QString &databaseName)
{
    return databases.find(new QString(databaseName)).value();
}
/**
 * Ajoute une base de données à la liste des bases de données
 * Entree : - newDatabase, const QString& (nouvelle base de données à ajouter)
 * Sortie :
 */
void Profile::addDataBase(const QString &databaseName, const QString &databaseFilePath)
{
    try
    {
        // On vérifie que la base de données n'est pas déjà présente
        if (databases.contains(new QString(databaseName)))
        {
            throw new Exception(BASE_DE_DONNEE_DEJA_AJOUTEE);
        }
        else
        {
            databases.insert(new QString(databaseName), new QString(databaseFilePath));
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}

/**
 * Supprime une base de données de la liste des bases de données
 * Entree : - databaseName, const QString& (nom de la base de données à supprimer)
 * Sortie :
 */
void Profile::removeDataBase(const QString &databaseName)
{
    try
    {
        // On vérifie que la base de données est bien présente
        if (!databases.contains(new QString(databaseName)))
        {
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);
        }
        else
        {
            databases.remove(new QString(databaseName));
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
}

/**
 * Methode pour récupérer la liste des tables d'une base de données
 * Entree : - databaseName, const QString& (nom de la base de données)
 * Sortie : - tables, QList<QString> (liste des tables de la base de données)
 */
QList<QString> Profile::getTables(const QString &databaseName)
{
    QList<QString> tables;
    try
    {
        // On vérifie que la base de données est bien présente
        if (!databases.contains(new QString(databaseName)))
        {
            throw new Exception(BASE_DE_DONNEE_NON_TROUVEE);
        }
        else
        {
            // Ouvrir la base de données SQLite
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "connectionName");
            QString dbFilePath = *databases[new QString(databaseName)];
            db.setDatabaseName(dbFilePath);

            if (!db.open())
            {
                qDebug() << "Error: Unable to open database.";
                return tables;
            }

            // Récupérer la liste des tables de la base de données
            QStringList tableNames = db.tables();
            foreach (const QString &tableName, tableNames)
            {
                tables.append(tableName);
            }

            db.close();
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
    }
    return tables;
}

/**
 * Surcharge de l'opérateur = , permet de copier un profil dans un autre
 * Entree : - profile, const Profile&
 * Sortie : - *this, Profile& (profil copié)
 */
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
    for (auto it = profile.databases.begin(); it != profile.databases.end(); it++)
    {
        databases.insert(new QString(*it.key()), new QString(*it.value()));
    }
    return *this;
}

/**
 * Constructeur de la classe Profile
 * Entree :  - profile, const Profile&
 * Sortie :
 */
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
 * Entree : - actualUser, User* (pointeur vers l'utilisateur auquel appartient le profil)
 *          - newTitle, const QString& (nouveau titre du profil)
 *          - newRight, const Rights& (nouveau droit du profil)
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
Profile::Profile(User *actualUser, const QString &newTitle, const Rights &newRight, const QMap<QString *, QString *> &newDatabases)
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
    for (auto it = newDatabases.begin(); it != newDatabases.end(); it++)
    {
        databases.insert(new QString(*it.key()), new QString(*it.value()));
    }
}

Profile::~Profile()
{
    // TODO
}
