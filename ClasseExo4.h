#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

#ifndef EXO4
#define EXO4 1

class ClasseExo4 {
private:
	vector<vector<unsigned int>> matrice;
	unsigned int n;
	unsigned int m;

public:
	void ajouterLigne();
	void ajouterColonne();
	void modifierElement(unsigned int i, unsigned int j, unsigned int valeur);

	void genererValeurs();
	void print();

	void duplicat();

private :
	int duplicatC(int j);
	int duplicatL(int i);

public:
	ClasseExo4(unsigned int m);
	ClasseExo4(unsigned int n, unsigned int m);
};

#endif