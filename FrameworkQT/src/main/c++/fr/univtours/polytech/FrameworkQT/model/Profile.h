#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "qlist.h"

#include "Rights.h"

#ifndef PROFILE
#define PROFILE 1

class User;

class Profile
{
private:
    // Profile (un profils est defini par un nom(string) et son role(string issue du enum Rights mais faut voir comment on fait pour l'enum)
    
    std::string title;
    Rights right;
    QList<std::string> databases;
    User *user;

public:
    /*Methode qui permet de recuperer le nom du profil
    *Entree: aucun
    *Sortie: le nom du profil
    *Entraine: On recupere le nom du profil

     */
    std::string getTitle();
    void setTitle(std::string newTitle);
    void setRight(Rights newRight);

    /*Methode qui permet de recuperer le role du profil
    *Entree: aucun
    *Sortie: le role du profil
    *Entraine: On recupere le role du profil
    */

    Rights getRight();

    /*Methode qui permet de recuperer la liste des bases de données
    *Entree: aucun
    *Sortie: la liste des bases de donnees
    *Entraine: On recupere la liste des bases de donnees
    */
    QList<std::string> getDatabases();

    /*Methode qui permet d'ajouter une base de donnees a la liste des bases de donnees
    *Entree: le nom de la base de donnees a ajouter
    *Sortie: aucun
    *Entraine: On ajoute la base de donnees a la liste des bases de donnees
    *Exception: si la base de donnees est deja dans la liste, on ne l'ajoute pas
    */
    void addDataBase(std::string newDatabase);
    
    Profile(User* actualUser, std::string newTitle);
    Profile(User* actualUser, std::string newTitle, Rights newRight);
    Profile(User* actualUser, std::string newTitle, Rights newRight, QList<std::string> newDatabases);
   
    // std::string toString(); //Pour convertir le profil en string et ensuite le sauvegarder dans un fichier ou l'afficher / PAS NECESAIRE POUR LE MOMENT
};

#endif
