#ifndef CPARSERJSON_H
#define CPARSERJSON_H

#define ERREUR_OUVERTURE_FICHIER_JSON
#define ERREUR_UTILISATEUR_SANS_PROFIL
#define ERREUR_UTILISATEUR_INEXISTANT

#include <qstring>
#include <qlist>
#include <string>
#include <fstream>
#include "../model/User.h"
#include "../model/Profile.h"


class CparserJson
{
private:
	 
public:

	/*Constructeur de la classe CparseurJson
	 *Entree : std::string filepath
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Initialise le chemin du fichier json
	 */
    CparserJson(QString filepath);

	/*Methode qui permet de lire les utilisateurs dans le fichier json
	 *Entree : Rien
	 *Necessite : Rien
	 *Sortie : std::vector<User> 
	 *Entrain : Retourne un vecteur d'utilisateur qui contient tous les utilisateurs dans le fichier json
	 */
    QList<User> readUsers();
	/*
	 * Methode qui permet de lire les profils dans le fichier json
	 *Entree : Rien
	 *Necessite : Rien
	 *Sortie : std::vector<Profile>
	 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json
	*/
    QList<Profile> readProfils();

	/*
	 * Methode qui permet de lire les profils dans le fichier json d'un utilisateur
	 *Entree : std::string id
	 *Necessite : Rien
	 *Sortie : std::vector<Profile>
	 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json d'un utilisateur
	*/
    QList<Profile> readProfilsUser(std::string id);
	/*Methode qui permet de sauvegarder un utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
	 *Entree : User user, std::string password
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Sauvegarde l'utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
	 */

	
	void addUser(User user, std::string password);
	/*Methode qui permet de supprimer un utilisateur dans le fichier json
	 *Entree : User user
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Supprime l'utilisateur dans le fichier json
	 */
	void removeUser(User user);

	/* Methode qui permet de mettre a jour un utilisateur dans le fichier json
	 *Entree : User user
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Met a jour l'utilisateur dans le fichier json
	*/
	void updateNameUser(std::string id, std::string newName);

	/*Methode qui permet de savoir si l'id de l'utilisateur existe dans le fichier json
	 *Entree : std::string id
	 *Necessite : Rien
	 *Sortie : bool
	 *Entrain : Retourne true si l'utilisateur existe dans le fichier json, false sinon
	*/
	bool isIDUserExist(std::string id);

	/*Methode qui permet de crypter un mot de passe
	 *Entree : std::string password
	 *Necessite : Rien
	 *Sortie : std::string
	 *Entrain : Retourne le mot de passe crypte
	*/
	void setPassword(User* user, std::string password);

	/*Methode qui permet de decrypter un mot de passe
	 *Entree : std::string password
	 *Necessite : Rien
	 *Sortie : std::string
	 *Entrain : Retourne le mot de passe decrypte
	*/
	std::string getPassword(User* user);
};

#endif // CPARSER_H
