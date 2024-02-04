#ifndef CPARSERJSON_H
#define CPARSERJSON_H

#define ERREUR_OUVERTURE_FICHIER_JSON 
#define ERREUR_UTILISATEUR_SANS_PROFIL 
#define ERREUR_UTILISATEUR_INEXISTANT 

#include <string>
#include <vector>
#include <fstream>
#include "Utilisateur.h"
#include "Profil.h"


class CparseurJson
{
private:
	 
public:

	/*Constructeur de la classe CparseurJson
	 *Entree : std::string filepath
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Initialise le chemin du fichier json
	 */
	CparseurJson(std::string filepath);

	/*Methode qui permet de lire les utilisateurs dans le fichier json
	 *Entree : Rien
	 *Necessite : Rien
	 *Sortie : std::vector<Utilisateur> 
	 *Entrain : Retourne un vecteur d'utilisateur qui contient tous les utilisateurs dans le fichier json
	 */
	std::vector<Utilisateur> readUsers();
	/*
	 * Methode qui permet de lire les profils dans le fichier json
	 *Entree : Rien
	 *Necessite : Rien
	 *Sortie : std::vector<Profil>
	 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json
	*/
	std::vector<Profil> readProfils();

	/*
	 * Methode qui permet de lire les profils dans le fichier json d'un utilisateur
	 *Entree : std::string id
	 *Necessite : Rien
	 *Sortie : std::vector<Profil>
	 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json d'un utilisateur
	*/
	std::vector<Profil> readProfilsUser(std::string id);
	/*Methode qui permet de sauvegarder un utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
	 *Entree : Utilisateur user, std::string password
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Sauvegarde l'utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
	 */

	
	void addUser(Utilisateur user, std::string password);
	/*Methode qui permet de supprimer un utilisateur dans le fichier json
	 *Entree : Utilisateur user
	 *Necessite : Rien
	 *Sortie : Rien
	 *Entrain : Supprime l'utilisateur dans le fichier json
	 */
	void removeUser(Utilisateur user);

	/* Methode qui permet de mettre a jour un utilisateur dans le fichier json
	 *Entree : Utilisateur user
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
	std::string cryptPassword(std::string password);

	/*Methode qui permet de decrypter un mot de passe
	 *Entree : std::string password
	 *Necessite : Rien
	 *Sortie : std::string
	 *Entrain : Retourne le mot de passe decrypte
	*/
	std::string decryptPassword(std::string password);

};

#endif // CPARSEUR_H
