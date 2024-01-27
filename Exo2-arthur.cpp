#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
int somme(T umap) {
	return std::accumulate(umap.begin(), umap.end(), 0,
		[](int value, const typename T::value_type& p) {
			return value + p.second;
		}
	);
}

unordered_map<string, double> main_unordered_map() {
	unordered_map<string, double> umap;

	umap["un"] = 1;
	umap["deux"] = 2;
	umap["trois"] = 3;
	umap["quatre"] = 4;
	umap["cinq"] = 5;

	unordered_map<string, double>::iterator it = umap.begin();

	while (it != umap.end()) {
		cout << "map[" << it->first << "] = " << it->second << endl;

		it++;
	}

	/* Stupide vu que unordered_map => valeur dans un ordre aléatoire */
	//it = umap.begin()++++++;
	//umap.erase(it->first);

	/* plutot comme ca du coups */
	umap.erase("trois");
	cout << endl;

	it = umap.begin();

	while (it != umap.end()) {
		cout << "map[" << it->first << "] = " << it->second << endl;

		it++;
	}

	cout << "somme : " << somme(umap) << endl;

	return umap;
}

map<string, double> main_map() {
	map<string, double> sdmap;

	sdmap["un"] = 1;
	sdmap["deux"] = 2;
	sdmap["trois"] = 3;
	sdmap["quatre"] = 4;
	sdmap["cinq"] = 5;

	map<string, double>::iterator it = sdmap.begin();

	while (it != sdmap.end()) {
		cout << "map[" << it->first << "] = " << it->second << endl;

		it++;
	}

	it = sdmap.begin();
	it++;
	it++;
	it++;

	sdmap.erase(it->first);
	cout << endl;

	it = sdmap.begin();

	while (it != sdmap.end()) {
		cout << "map[" << it->first << "] = " << it->second << endl;

		it++;
	}

	cout << "somme : " << somme(sdmap) << endl;

	return sdmap;
}

template <class T>
void trucVecteur(T umap) {
	vector<int> v(10, somme(umap));

	vector<int>::iterator it = v.begin();

	double value = *it;

	cout << "vecteur = { ";
	while (it != v.end()) {
		value = value * value;
		*it = value;

		it++;
		cout << value << " , ";
	}
	cout << "}" << endl;

}


int main_Q2() {
	cout << "MAP : " << endl;
	map<string, double> sdmap = main_map();
	trucVecteur(sdmap);

	cout << endl << "UNORDORED_MAP : " << endl;
	unordered_map<string, double> umap = main_unordered_map();
	trucVecteur(umap);

	cout << endl << "EXEMPLE ENONCE : " << endl;
	unordered_map<string, double> mapEx;
	mapEx["deux"] = 2;
	mapEx["trois"] = 3;
	trucVecteur(mapEx);

	return 0;
}