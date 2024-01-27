#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>

#include "Outils.h"

using namespace std;


void Afficher(vector<unsigned int> l) {

	auto print = [](unsigned int& n) { std::cout << n << ' '; };
	for_each(l.begin(), l.end(), print);


	cout << "\n\n";
}

void Afficher(list<unsigned int> l) {
	cout << "Affichage :\n";
	auto print = [](unsigned int& n) { std::cout << n << ' '; };
	for_each(l.begin(), l.end(), print);


	cout << "\n\n";
}

bool is_inferior(int i) { return i > 9; };

void vecteur(
	vector<unsigned int>* vadd) {
	vector<unsigned int> v = *vadd;

	for (int i = 0; i < 10; i++) {
		v.push_back(generer(2, 10));

		cout << v[i] << ", ";
	}
	cout << "\n\n";


	vector<unsigned int>::iterator it;
	it = find_if(v.begin(), v.end(), is_inferior);

	if (it == v.end()) {
		cout << "Pas de sup" << "\n";
	}
	else {
		cout << "Au moins 1 sup" << "\n";
	}

	std::function<void(unsigned int&)> carre = [](unsigned int& a) { a = a * a; };
	for_each(v.begin(), v.end(), carre);

	Afficher(v);

}

list<unsigned int> liste() {
	list<unsigned int> l(10);

	list<unsigned int>::iterator myIterator;
	myIterator = l.begin();

	while (myIterator != l.end()) {
		*myIterator = generer(2,10);

		myIterator++;
	}

	Afficher(l);
	
	std::function<void(unsigned int&)> carre = [](unsigned int& a) { a = a * a; };
	for_each(l.begin(), l.end(), carre);

	Afficher(l);

	l.clear();
	Afficher(l);

	return l;
}

int main_Q1() {
	cout << "Vector :\n";

	vector<unsigned int> v;
	vecteur(&v);

	Afficher(v);

	cout << "\n\n";
	cout << "List :\n";
	
	list<unsigned int> l = liste();

	Afficher(l);


	cout << "\n\n";

	return 0;
}

