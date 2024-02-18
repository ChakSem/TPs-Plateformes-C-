#ifndef EXCEPTION_H
#define EXCEPTION_H

#define PASDERREUR 0

#define NOMPROFILEDEJAATTRIBUE 1
#define BASEDEDONNEEDEJAAJOUTEE 2
#define ERREUROUVERTUREFICHIERPOURCHARGERUSER 3
#define ERREUROUVERTUREFICHIERPOURCHARGERADMIN 4
#define ERREUROUVERTUREFICHIERPOURSAUVEGARDEUSER 5
#define ERREUROUVERTUREFICHIERPOURSAUVEGARDEADMIN 6
#define ERREUROUVERTUREFICHIERPOURECRIREDANSLASAUVEGARDEUSER 7
#define ERREUROUVERTUREFICHIERPOURECRIREDANSLASAUVEGARDEADMIN 8
#define ERREURAUCUNUTILISATEURNECORRESPONDACETID 9
#define ERREURAUCUNDROITCORRESPONDANT 10
#define ERREURAUCUNROLECORRESPONDANT 11

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
