#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include "ClasseExo4.h"

using namespace std;


int main() {
	ClasseExo4* matrice = new ClasseExo4(5, 7);
	matrice->print();

	matrice->genererValeurs();
	matrice->print();

	matrice->duplicat();

	return 0;
}