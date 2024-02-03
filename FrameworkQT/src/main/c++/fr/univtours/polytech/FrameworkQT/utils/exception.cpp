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
unsigned int CException::EXCLireValeur()
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
void CException::EXCModifierValeur(unsigned int uiValeur)
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
void CException::EXCAffichageErreur()
{
    printf_s("Erreur : ");
    switch (uiEXCCodeErreur)
    {
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
CException::CException()
{
    uiEXCCodeErreur = PASDERREUR;
}

/********************************************************************
***** ~CException : Destructeur									*****
*********************************************************************
***** Necessite : <pas de cond>									*****
***** Entree :													*****
***** Sortie :													*****
***** Entraine : <pas de cond>									*****
********************************************************************/
CException::~CException()
{
}
