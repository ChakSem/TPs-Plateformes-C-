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
