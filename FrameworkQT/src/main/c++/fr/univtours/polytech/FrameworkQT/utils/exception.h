#ifndef EXCEPTION_H
#define EXCEPTION_H

#define PASDERREUR 0

class CException {
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
    CException();

    /********************************************************************
    ***** ~CException : Destructeur									*****
    *********************************************************************
    ***** Necessite : <pas de cond>									*****
    ***** Entree :													*****
    ***** Sortie :													*****
    ***** Entraine : <pas de cond>									*****
    ********************************************************************/
    ~CException();
};


#endif // EXCEPTION_H
