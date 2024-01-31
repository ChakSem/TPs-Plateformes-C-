#include <iostream>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;

// Classe avec un nom et un entier comme attributs
class MaClasse {
public:
    string nom;
    int entier;

    // Constructeur
    MaClasse(string n, int e) : nom(n), entier(e) {}

    // Surcharge de l'opérateur <
    bool operator<(const MaClasse& autre) const {
        // Trie selon les entiers de manière décroissante
        if (entier != autre.entier) {
            return entier > autre.entier;
        }
        // En cas d'égalité, trie lexicographiquement sur le nom
        return nom > autre.nom;
    }
};

// Foncteur pour afficher le contenu de la priority queue
struct AfficherQueue {
    void operator()(const MaClasse& obj) const {
        cout << "Nom : " << obj.nom << " ; Entier : " << obj.entier << endl;
    }
};

int main() {
    // Création de la priority queue
    priority_queue<MaClasse> maQueue;

    // Ajout de 10 objets à la queue
    maQueue.push(MaClasse("Objet1", 20));
    maQueue.push(MaClasse("Objet2", 15));
    maQueue.push(MaClasse("Objet3", 20));
    maQueue.push(MaClasse("Objet4", 10));
    maQueue.push(MaClasse("Objet5", 15));
    maQueue.push(MaClasse("Objet6", 10));
    maQueue.push(MaClasse("Objet7", 25));
    maQueue.push(MaClasse("Objet8", 30));
    maQueue.push(MaClasse("Objet9", 25));
    maQueue.push(MaClasse("Objet10", 30));

    // Copie de la queue pour pouvoir l'afficher
    priority_queue<MaClasse> copieQueue = maQueue;

    // Affichage de la queue
    while (!copieQueue.empty()) {
        AfficherQueue()(copieQueue.top());
        copieQueue.pop();
    }

    return 0;
}
