#include <algorithm>
#include "Profile.h"
#include "User.h"
#include "exception.h"

std::string Profile::getTitle() {
    return title;
}

void Profile::setTitle(std::string newTitle) {
    title = newTitle; // A FAIRE DANS UTILISATEUR
}

void Profile::setRight(Rights newRight){
    right = newRight;
}

std::list<std::string> Profile::getDatabases(){
    return databases;
}

void Profile::addDataBase(std::string newDatabase){
    //Foncteur qui ajoute une base de données à la liste des bases de données (si (son nom)  n'est pas déjà présente dans la liste)
    struct Search
    {
        std::string newDatabase;
        Search(std::string db) : newDatabase(db) {} 
        void operator()(const std::string& n) { find += n == newDatabase; }  
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

Profile::Profile(User* actualUser, std::string newTitle)
{
    user = actualUser;
    title = newTitle;
    right = Rights::LECTURE;
    databases = std::list<std::string>(); 
}

Profile::Profile(User* actualUser,std::string newTitle, Rights newRight)
{
    user = actualUser;
    title = newTitle;
    right = newRight;
    databases = std::list<std::string>(); 
}

Profile::Profile(User* actualUser, std::string newTitle, Rights newRight, std::list<std::string> newDataBases)
{
    user = actualUser;
    title = newTitle;
    right = newRight;
    databases = newDataBases;
}
