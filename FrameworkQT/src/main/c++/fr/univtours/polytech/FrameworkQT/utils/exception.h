#ifndef EXCEPTION_H
#define EXCEPTION_H

#define PASDERREUR 0

#define NOM_PROFIL_DEJA_ATTRIBUE 1
#define BASE_DE_DONNEE_DEJA_AJOUTEE 2
#define BASE_DE_DONNEE_NON_TROUVEE 3
#define BASE_DE_DONNEE_NON_OUVERTE 4


/* Parsing */
#define ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER 5
#define ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN 6
#define ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER 7
#define ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN 8
#define ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER 9
#define ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN 10
#define ERREUR_DROIT_INCONNU 11
#define ERREUR_OUVERTURE_FICHIER_POUR_MOTS_DE_PASSE 12

/* Data */
#define ERREUR_AUCUN_UTILISATEUR_NE_CORRESPOND_A_CET_ID 13
#define ERREUR_ISADMIN_INCORRECT 14

/* Controller */
#define ERREUR_AUCUN_DROIT_CORRESPONDANT 15
#define ERREUR_AUCUN_ROLE_CORRESPONDANT 16
#define ERREUR_AUCUN_PROFIL_CORRESPONDANT 17

/* Vues */
#define ERREUR_MAINWINDOW_NON_TROUVE 18
#define ERREUR_ALL_TOUS_LES_CHAMPS_NE_SONT_PAS_REMPLIS 19
#define ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES 20
#define ERREUR_USER_MANAGEMENT_SUPPRESSION_SUPER_ADMIN 21
#define ERREUR_CHEMIN_VIDE 22
#define ERREUR_BASE_DE_DONNEE_DEJA_AJOUTEE 23
#define ERREUR_COMBOBOX_VIDE 24
#define ERREUR_REQUETE_SQL 25


/* Erreur fatale */
#define ERREUR_FATALE 999

class Exception {
private:
    unsigned int uiEXCCodeErreur;

public:

    /********************************************************************
    ***** EXCLireCodeErreur : Accesseur en lecture de				*****
    *****					  uiEXCCodeErreur						*****
    *********************************************************************
    ***** Nécessite : <pas de cond>									*****
    ***** Entrée :													*****
    ***** Sortie : uiEXCValeur : unsigned int  						*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    unsigned int EXCLireValeur();

    /********************************************************************
    ***** EXCModifierValeur : Modifie uiEXCCodeErreur				*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :	uiCodeErreur : unsigned int 					*****
    ***** Sortie :													*****
    ***** Entraine : uiEXCCodeErreur = uiCodeErreur 				*****
    ********************************************************************/
    void EXCModifierValeur(unsigned int uiCodeErreur);

    /********************************************************************
    ***** EXCAffichageErreur : Méthode qui affiche le message		*****
    *****					   d'erreur								*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :													*****
    ***** Sortie :													*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    void EXCAffichageErreur();

    //Constructeur et destructeur

    /********************************************************************
    ***** CException : Constructeur par défaut						*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :													*****
    ***** Sortie :	uiEXCCodeErreur = PASDERREUR					*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    Exception();

    
    /********************************************************************
    ***** CException : Constructeur par défaut						*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :													*****
    ***** Sortie :	uiEXCCodeErreur = PASDERREUR					*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    Exception(int i);

    /********************************************************************
    ***** ~CException : Destructeur									*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :													*****
    ***** Sortie :													*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    ~Exception();
};


#endif // EXCEPTION_H
