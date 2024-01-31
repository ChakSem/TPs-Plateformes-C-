#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <algorithm>
#include <math.h>

using namespace std;
int random_value(int min, int max);
void afficher_vector(vector<unsigned int> v1);
void afficher_liste(list<unsigned int> l1);
void ModifierVector(vector<unsigned int>& v1); // Added function declaration
void ModifierListe(list<unsigned int>& l1); // Added function declaration
void TrouverValeur(list<unsigned int> l1); // Added function declaration

int main()
{
    // 1.1 Creation des conteneurs : un vecteur et une liste d'entier non signés
    vector<unsigned int> v1; // Removed pointer
    list<unsigned int> l1; // Removed pointer
    
    // 1.2 Ajout des valeurs aleatoires dans les conteneurs
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(random_value(1, 10)); 
        l1.push_back(random_value(1, 10)); 
    }

    // Affichage des conteneurs
    cout << "Vecteur avant modification: " << endl;
    afficher_vector(v1); // Pass vector by reference
    cout << "Liste avant modification: " << endl;
    afficher_liste(l1); // Pass list by reference

    // Modification des conteneurs
    ModifierVector(v1); 
    ModifierListe(l1); 

    // Affichage des conteneurs
    cout << "Vecteur apres modification: " << endl;
    afficher_vector(v1);
    cout << "Liste apres modification: " << endl;
    afficher_liste(l1);

    // Recherche d'une valeur dans la liste
    TrouverValeur(l1); // Uncomment function call

    // Vider les conteneurs
    ViderConteneurs(v1, l1); 
}

// Methode pour generer des valeurs aleatoires
int random_value(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    std::random_device rd;
    std::mt19937 engine(rd());
    return distribution(engine);
}

//1.3 Methode pour afficher les vecteurs avec L'operateur [] permet d'acceder aux elements d'un vecteur
void afficher_vector(vector<unsigned int> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] ;
        
    }
    cout << endl;
}

// 1.4 Methode pour afficher les listes en utilisant un iterateur (A verifier ....)
void afficher_liste(list<unsigned int> l1)
{
    for (auto it = l1.begin(); it != l1.end(); it++)//auto : type de variable qui est automatiquement deduit par le compilateur
    {
        cout << *it ;
    }
    cout << endl;
}

// 1.5 Methode pour modifier les vecteurs (pour mettre au carré les valeurs)
void ModifierVector(vector<unsigned int>& v1)
{
    for_each(v1.begin(), v1.end(), [](unsigned int& n) { n = pow(n, 2); });
    cout << "Vecteur apres modification: " << endl;
    afficher_vector(v1);
}

//1.5(bis) Methode pour modifier les listes (pour mettre au carré les valeurs) 
void ModifierListe(list<unsigned int>& l1)
{
    for_each(l1.begin(), l1.end(), [](unsigned int& n) { n = pow(n, 2); });
    cout << "Liste apres modification: " << endl;
    afficher_liste(l1);
}

// 1.6 Methode pour trouver une valeur plus grande que 5 dans la liste
void TrouverValeur(list<unsigned int> l1)
{
    auto it = find_if(l1.begin(), l1.end(), [](unsigned int &n)
                      { return n > 5; });
    if (it != l1.end())
    {
        cout << "Valeur trouvee: " << *it << endl;
        cout << "Position: " << distance(l1.begin(), it) << endl;
    }
    else
        cout << "Valeur non trouvee" << endl;
}

//1.7 Videz les deux conteneurs
void ViderConteneurs(vector<unsigned int>& v1, list<unsigned int>& l1)
{
    v1.clear();
    l1.clear();
    cout << "Vecteur apres vidage: " << endl;
    afficher_vector(v1);
    cout << "Liste apres vidage: " << endl;
    afficher_liste(l1);
}
