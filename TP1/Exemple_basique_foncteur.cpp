#include <iostream>

// Définition d'un foncteur
struct MonFoncteur {
    void operator()() const {
        std::cout << "Hello world (foncteur) !" << std::endl;
    }
};

int main() {
    // Création d'un objet foncteur
    MonFoncteur foncteur;

    // Appel de la fonction () du foncteur
    foncteur();  // -> Cela affichera "Hello world (foncteur) !"

    return 0;
}