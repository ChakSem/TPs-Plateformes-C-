#include <algorithm>
#include "Profile.h"
#include "User.h"
#include "../utils/exception.h"

QString Profile::getTitle() {
    return title;
}

void Profile::setTitle(QString newTitle) {
    title = newTitle; // A FAIRE DANS UTILISATEUR
}

void Profile::setRight(Rights newRight){
    right = newRight;
}

QList<QString> Profile::getDatabases(){
    return databases;
}

void Profile::addDataBase(QString newDatabase){
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

    if(s.find > 0) {
        throw Exception(1); 
    } else {
        databases.push_back(newDatabase);
    }
}

Profile* Profile::operator=(const Profile& profile) {
    QList<QString> newDataBases = QList<QString>(profile.databases);
    return new Profile(profile.user, profile.title, profile.right, newDataBases);
}

Profile::Profile(const Profile& profile){
    operator=(profile);
}

Profile::Profile(User* actualUser, QString newTitle)
{
    user = actualUser;
    title = newTitle;
    right = Rights::LECTURE;
}

Profile::Profile(User* actualUser,QString newTitle, Rights newRight)
{
    user = actualUser;
    title = newTitle;
    right = newRight;
}

Profile::Profile(User* actualUser, QString newTitle, Rights newRight, QList<QString> newDataBases)
{
    user = actualUser;
    title = newTitle;
    right = newRight;
    databases = newDataBases;
}

Profile::~Profile()
{
}
