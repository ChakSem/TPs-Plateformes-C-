#include <stdlib.h>
#include <stdio.h>
#include "exception.h"


/********************************************************************
***** EXCLireCodeErreur : Accesseur en lecture de				*****
*****					  uiEXCCodeErreur						*****
*********************************************************************
***** Nécessite : <pas de cond>									*****
***** Entrée :													*****
***** Sortie : uiEXCValeur : unsigned int  						*****
***** Entraine : <pas de cond>									*****
********************************************************************/
unsigned int Exception::EXCLireValeur()
{
    return uiEXCCodeErreur;
}

/********************************************************************
***** EXCModifierValeur : Modifie uiEXCCodeErreur				*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :	uiCodeErreur : unsigned int 					*****
***** Sortie :													*****
***** Entraine : uiEXCCodeErreur = uiCodeErreur 				*****
********************************************************************/
void Exception::EXCModifierValeur(unsigned int uiValeur)
{
    uiEXCCodeErreur = uiValeur;
}

/********************************************************************
***** EXCAffichageErreur : Méthode qui affiche le message		*****
*****					   d'erreur								*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :													*****
***** Sortie :													*****
***** Entraine : <pas de cond>									*****
********************************************************************/
void Exception::EXCAffichageErreur()
{
    printf_s("Erreur : ");
    switch (uiEXCCodeErreur)
    {
    case NOMPROFILEDEJAATTRIBUE :
        printf_s("ERREUR : Le nom de profil saisi est deja affecte");
        break;
    case BASEDEDONNEEDEJAAJOUTEE :
        printf_s("ERREUR : La base de donnee est deja ajoutee");
        break;
    case ERREUROUVERTUREFICHIERPOURSAUVEGARDEUSER :
        printf_s("ERREUR : Le fichier pour la sauvegarde des utilisateurs n'a pu etre ouvert");
        break;
    case ERREUROUVERTUREFICHIERPOURSAUVEGARDEADMIN :
        printf_s("ERREUR : Le fichier pour la sauvegarde des administrateurs n'a pu etre ouvert");
        break;
    case ERREUROUVERTUREFICHIERPOURCHARGERUSER :
        printf_s("ERREUR : Le fichier pour le chargement des utilisateurs n'a pu etre ouvert");
        break;
    case ERREUROUVERTUREFICHIERPOURCHARGERADMIN :
        printf_s("ERREUR : Le fichier pour le chargement des administrateurs n'a pu etre ouvert");
        break;
    case ERREUROUVERTUREFICHIERPOURECRIREDANSLASAUVEGARDEUSER :
        printf_s("ERREUR : L'ecriture dans fichier pour le sauvegarde des utilisateurs a echoue");
        break;
    case ERREUROUVERTUREFICHIERPOURECRIREDANSLASAUVEGARDEADMIN :
        printf_s("ERREUR : L'ecriture dans fichier pour le sauvegarde des administrateurs a echoue");
        break;
    case ERREURAUCUNUTILISATEURNECORRESPONDACETID :
        printf_s("ERREUR : L'id ne correspond à aucuns utilisateur et admin existants");
        break;
    case ERREURAUCUNDROITCORRESPONDANT :
        printf_s("ERREUR : L'id de droit ne correspond a aucun droit existant");
        break;
    case ERREURAUCUNROLECORRESPONDANT :
        printf_s("ERREUR : L'id de role ne correspond a aucun droit existant");
        break;
    default:
        printf_s("\n");
    }
}

/********************************************************************
***** CException : Constructeur par défaut						*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :													*****
***** Sortie :	uiEXCCodeErreur = PASDERREUR					*****
***** Entraine : <pas de cond>									*****
********************************************************************/
Exception::Exception()
{
    uiEXCCodeErreur = PASDERREUR;
}

/********************************************************************
***** CException : Constructeur par défaut						*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :						i							*****
***** Sortie :	uiEXCCodeErreur = i					*****
***** Entraine : <pas de cond>									*****
********************************************************************/
Exception::Exception(int i)
{
    uiEXCCodeErreur = i;
}

/********************************************************************
***** ~CException : Destructeur									*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :													*****
***** Sortie :													*****
***** Entraine : <pas de cond>									*****
********************************************************************/
Exception::~Exception()
{
}
