#ifndef PARSERJSON_H
#define PARSERJSON_H

#define ERREUR_OUVERTURE_FICHIER_JSON
#define ERREUR_UTILISATEUR_SANS_PROFIL
#define ERREUR_UTILISATEUR_INEXISTANT

#include <qstring>
#include <qlist>
#include <string>
#include <fstream>
#include "../model/user.h"
#include "../model/profile.h"

class Data;

class parserJson
{
private:
	 
public:
    /**
	 * Methode qui permet de lire les profils dans le fichier json d'un utilisateur
     * Entree : std::string id
     * Sortie : std::vector<Profile>
     * Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json d'un utilisateur
     */
    int static saveData(Data& data);

    /**
     * Methode qui permet de sauvegarder un utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
     * Entree : User user, std::string password
     * Sortie : Rien
     * Entrain : Sauvegarde l'utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
	 */
    int static updateData(Data& data);

    /**
     * Methode qui permet de crypter un mot de passe
     * Entree : std::string password
     * Sortie : std::string
     * Entrain : Retourne le mot de passe crypte
     */
    void static setPassword(QString id, QString password);

    /**
     * Methode qui permet de decrypter un mot de passe
     * Entree : std::string password
     * Sortie : std::string
     * Entrain : Retourne le mot de passe decrypte
     */
    QString static getPassword(QString id);
};

#endif // CPARSER_H
