#include <stdlib.h>
#include <stdio.h>
#include "exception.h"
#include "qdebug.h"
#include "qlogging.h"


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
    qDebug() << "ERREUR : ";
    switch (uiEXCCodeErreur)
    {
    case NOM_PROFIL_DEJA_ATTRIBUE :
         qDebug() << "Le nom de profil saisi est deja affecte";
        break;
    case BASE_DE_DONNEE_DEJA_AJOUTEE :
         qDebug() << "La base de donnee est deja ajoutee";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER :
         qDebug() << "Le fichier pour la sauvegarde des utilisateurs n'a pu etre ouvert";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN :
         qDebug() << "Le fichier pour la sauvegarde des administrateurs n'a pu etre ouvert";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER :
         qDebug() << "Le fichier pour le chargement des utilisateurs n'a pu etre ouvert";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN :
         qDebug() << "Le fichier pour le chargement des administrateurs n'a pu etre ouvert";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER:
         qDebug() << "L'ecriture dans fichier pour le sauvegarde des utilisateurs a echoue";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN :
         qDebug() << "L'ecriture dans fichier pour le sauvegarde des administrateurs a echoue";
        break;
    case ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID :
         qDebug() << "L'id ne correspond à aucuns utilisateur et admin existants";
        break;
    case ERREUR_AUCUN_DROIT_CORRESPONDANT :
         qDebug() << "L'id de droit ne correspond a aucun droit existant";
        break;
    case ERREUR_AUCUN_ROLE_CORRESPONDANT :
         qDebug() << "L'id de role ne correspond a aucun droit existant";
        break;
    case ERREUR_ISADMIN_INCORRECT :
         qDebug() << "La valeur de isAdmin n'a aucun sens";
        break;
    case ERREUR_MAINWINDOW_NON_TROUVE :
         qDebug() << "La vue n'a pas pu acceder a MainWindow";
        break;
    case ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS :
         qDebug() << "Tout les champs ne sont pas remplis";
        break;
    case ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES :
         qDebug() << "Aucunes lignes n'est selectionnees";
        break;
    case ERREUR_AUCUN_PROFIL_CORRESPONDANT :
         qDebug() << "Aucun profil ne correspond a l'id";
        break;
    case ERREUR_USER_MANAGEMENT_SUPPRESSION_SUPER_ADMIN :
         qDebug() << "Le super admin ne peut pas être supprimé";
        break;
    case ERREUR_DROIT_INCONNU :
         qDebug() << "Le droit lu n'existe pas";
        break;
    case ERREUR_OUVERTURE_FICHIER_POUR_MOTS_DE_PASSE :
         qDebug() << "Impossible d'ouvrir le fichier des mots de passe";
        break;
    default:
         qDebug() << "INCONNUE";
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
