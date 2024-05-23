#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <iterator>
#include "ClasseExo3.h"

using namespace std;


int main_Q3() {
	priority_queue<ClasseExo3 , std::deque<ClasseExo3>> queue;

    queue.push(*new ClasseExo3("maison", 1));
    queue.push(*new ClasseExo3("arbre", 6));
    queue.push(*new ClasseExo3("riviere", 3));
    queue.push(*new ClasseExo3("montagne", 5));
    queue.push(*new ClasseExo3("ocean", 9));
    queue.push(*new ClasseExo3("nuage", 4));
    queue.push(*new ClasseExo3("soleil", 7));
    queue.push(*new ClasseExo3("foret", 6));
    queue.push(*new ClasseExo3("lac", 8));
    queue.push(*new ClasseExo3("etoile", 2));

    while (!queue.empty()) {
        ClasseExo3 element = queue.top();
        std::cout << "Nom : " << element.getNom() << ", Entier : " << element.getEntier() << std::endl;
        queue.pop();
    }

	return 0;
}