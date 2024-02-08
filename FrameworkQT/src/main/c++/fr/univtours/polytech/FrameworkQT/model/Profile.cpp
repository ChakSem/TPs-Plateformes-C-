#include <algorithm>
#include "Profile.h"
#include "User.h"
#include "../utils/exception.h"

QString Profile::getTitle() {
    return title;
}

void Profile::setTitle(const QString& newTitle) {
    try {
        for(Profile* profile : user->getProfiles()) {
            if(profile->getTitle() == newTitle) {
                throw new Exception(NOMPROFILEDEJAATTRIBUE);
            }
        }
        title = newTitle;
    }

    catch(Exception* e) {
        e->EXCAffichageErreur();
    }
}

Rights Profile::getRight() {
    return right;
}

void Profile::setRight(const Rights& newRight){
    right = newRight;
}

QList<QString*> Profile::getDatabases(){
    return databases;
}

void Profile::addDataBase(const QString& newDatabase){
    //Foncteur qui ajoute une base de données à la liste des bases de données (si (son nom)  n'est pas déjà présente dans la liste)
    struct Search
    {
        QString newDatabase;
        Search(QString db) : newDatabase(db) {}
        void operator()(const QString& n) { find += n == newDatabase; }
        int find {0};
    };

    Search s(newDatabase); 

    std::for_each(databases.begin(), databases.end(), s);
    try {
        if(s.find > 0) {
            throw new Exception(BASEDEDONNEEDEJAAJOUTEE);
        } else {
            databases.append(new QString(newDatabase));
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

Profile& Profile::operator=(const Profile& profile) {
    user = profile.user;
    title = profile.title;
    right = profile.right;
    databases = QList<QString*>(profile.databases);
    return *this;
}

Profile::Profile(const Profile& profile){
    operator=(profile);
}

Profile::Profile(User* actualUser, const QString& newTitle)
{
    user = actualUser;
    title = newTitle;
    right = Rights::LECTURE;
}

Profile::Profile(User* actualUser,const QString& newTitle,  const Rights& newRight)
{
    user = actualUser;
    title = newTitle;
    right = newRight;
}

Profile::Profile(User* actualUser, const QString& newTitle,  const Rights& newRight, const QList<QString*>& newDataBases)
{
    user = actualUser;
    title = newTitle;
    right = newRight;

    /* On copie et ajoute les noms de base de données un à un */
    for (QString* str : newDataBases) {
        databases.append(new QString(*str));
    }
}

Profile::~Profile()
{
}
