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
    printf_s("ERREUR : ");
    switch (uiEXCCodeErreur)
    {
    case NOM_PROFIL_DEJA_ATTRIBUE :
        printf_s("Le nom de profil saisi est deja affecte\n");
        break;
    case BASE_DE_DONNEE_DEJA_AJOUTEE :
        printf_s("La base de donnee est deja ajoutee\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER :
        printf_s("Le fichier pour la sauvegarde des utilisateurs n'a pu etre ouvert\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN :
        printf_s("Le fichier pour la sauvegarde des administrateurs n'a pu etre ouvert\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER :
        printf_s("Le fichier pour le chargement des utilisateurs n'a pu etre ouvert\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN :
        printf_s("Le fichier pour le chargement des administrateurs n'a pu etre ouvert\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER:
        printf_s("L'ecriture dans fichier pour le sauvegarde des utilisateurs a echoue\n");
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN :
        printf_s("L'ecriture dans fichier pour le sauvegarde des administrateurs a echoue\n");
        break;
    case ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID :
        printf_s("L'id ne correspond à aucuns utilisateur et admin existants\n");
        break;
    case ERREUR_AUCUN_DROIT_CORRESPONDANT :
        printf_s("L'id de droit ne correspond a aucun droit existant\n");
        break;
    case ERREUR_AUCUN_ROLE_CORRESPONDANT :
        printf_s("L'id de role ne correspond a aucun droit existant\n");
        break;
    case ERREUR_ISADMIN_INCORRECT :
        printf_s("La valeur de isAdmin n'a aucun sens\n");
        break;
    case ERREUR_MAINWINDOW_NON_TROUVE :
        printf_s("La vue n'a pas pu acceder a MainWindow\n");
        break;
    default:
        printf_s("INCONNUE");
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
