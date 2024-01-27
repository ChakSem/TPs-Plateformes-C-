#include "ClasseExo3.h"

string ClasseExo3::getNom() {
	return nom;
}

void ClasseExo3::setNom(string n) {
	nom = n;
}

unsigned int ClasseExo3::getEntier() {
	return entier;
}

void ClasseExo3::setEntier(unsigned int e) {
	entier = e;
}


bool ClasseExo3::operator<(const ClasseExo3& classe) const {
	if (entier == classe.entier) {
		return nom > classe.nom;
	}
	return entier < classe.entier;
}


ClasseExo3::ClasseExo3() {
	entier = 2;
	nom = "deux";
}

ClasseExo3::ClasseExo3(string n, int e) {
	nom = n;
	entier = e;
}