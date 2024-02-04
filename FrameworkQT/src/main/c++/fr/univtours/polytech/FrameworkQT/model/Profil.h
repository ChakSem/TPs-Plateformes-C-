#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>


#ifndef PROFIL
#define PROFIL 1

class Profil {
private :    
    // Profil (un profils est defini par un nom(string) et son role(string issue du enum Droits mais faut voir comment on fait pour l'enum)
    std::map<std::string, std::string> profil;
public :
    std::map<std::string, std::string> getProfil();
    void setProfil(std::map<std::string, std::string> newProfil);
    Profil(std::map<std::string, std::string> newProfil);
    void addProfil(std::string id, std::string role);
    void removeProfil(std::string id);
    std::string getRole(std::string id);
    void setRole(std::string id, std::string role);
    std::string toString(); //Pour convertir le profil en string et ensuite le sauvegarder dans un fichier ou l'afficher/
  
};

#endif