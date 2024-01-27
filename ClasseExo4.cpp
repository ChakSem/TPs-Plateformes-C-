#include "ClasseExo4.h"

#include <unordered_map>

#include "Outils.h"

void ClasseExo4::ajouterLigne() {
	n++;
	matrice.push_back(vector<unsigned int>(m));
}

void ClasseExo4::ajouterColonne() {
	m++;
	for (unsigned int i = 0; i < n; i++) {
		matrice[i].push_back(0);
	}
}

void ClasseExo4::modifierElement(unsigned int i, unsigned int j, unsigned int valeur) {
	if (i < n && j < m) {
		matrice[i][j] = valeur;
	}
	else {
		cout << "Probleme coordonnees" << endl;
	}
}

void ClasseExo4::genererValeurs() {
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < m; j++) {
			modifierElement(i, j, generer(0, 10));
		}
	}
}

void ClasseExo4::print() {
	for (unsigned int j = 0; j < m; j++) {
		cout << "\tc" << j+1;
	}
	cout << endl;
	for (unsigned int i = 0; i < n; i++) {
		cout << "l" << i+1;
		for (unsigned int j = 0; j < m; j++) {
			cout << "\t" << matrice[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}

void ClasseExo4::duplicat() {
	for (unsigned int i = 0; i < n; i++) {
		duplicatL(i);
	}
	for (unsigned int j = 0; j < m; j++) {
		duplicatC(j);
	}
	cout << endl;
}

int ClasseExo4::duplicatL(int i) {
	cout << "l" << i + 1;
	unordered_map<unsigned int, int> map;

	for (unsigned int value : matrice[i]) {
		if (map.find(value) != map.end()) {
			cout << ", duplicat trouve :" << value << endl;
			return 1;
		}
		map[value] = 1;
	}
	cout << ", pas de duplicat trouve." << endl;
	return 0;
}

int ClasseExo4::duplicatC(int j) {
	cout << "c" << j + 1;
	unordered_map<unsigned int, int> map;

	for (unsigned int idx = 0; idx < n; idx++) {
		unsigned int value = matrice[idx][j];

		if (map.find(value) != map.end()) {
			cout << ", duplicat trouve :" << value << endl;
			return 1;
		}
		map[value] = 1;
	}
	cout << ", pas de duplicat trouve." << endl;
	return 0;
	
}

ClasseExo4::ClasseExo4(unsigned int j) {
	n = 0;
	m = j;
}

ClasseExo4::ClasseExo4(unsigned int i, unsigned int j) {
	n = 0;
	m = j;
	for (unsigned int ind = 0; ind < i; ind++) {
		ajouterLigne();
	}
}