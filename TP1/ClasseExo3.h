#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#ifndef EXO3
#define EXO3 1

class ClasseExo3 {
private :
	string nom;
	unsigned int entier;

public :
	string getNom();
	void setNom(string n);
	unsigned int getEntier();
	void setEntier(unsigned int e);

	bool operator<(const ClasseExo3& classe) const;

	ClasseExo3();
	ClasseExo3(string nom, int entier);
};

#endif