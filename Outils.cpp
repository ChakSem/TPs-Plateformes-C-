#include "Outils.h"

int generer(int min, int max) {
	std::uniform_int_distribution <int> distribution(min, max);
	std::random_device rd;
	std::mt19937 engine(rd());

	return distribution(engine);
}
