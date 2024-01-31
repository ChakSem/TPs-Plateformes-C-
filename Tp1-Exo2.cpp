#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <set>

using namespace std;

int random_value(int min, int max);

// Foncteur pour obtenir la somme des valeurs des paires de la map
struct SommeValeursMap
{
    double operator()(const double &somme, const std::pair<std::string, double> &paire) const
    {
        return somme + paire.second;
    }
};

// Foncteur pour afficher le contenu de la map
struct AfficherMap
{
    void operator()(const std::pair<std::string, double> &paire) const
    {
        cout << "map[" << paire.first << "] = " << paire.second << endl;
    }
};

// Foncteur pour calculer le carré des valeurs de la map
struct CarreDesValeurs
{
    double operator()(const std::pair<std::string, double> &paire) const
    {
        return paire.second * paire.second;
    }
};

// Foncteur pour initialiser la map avec des valeurs aléatoires
struct ValeursAleatoires
{
    double operator()() const
    {
        return random_value(1, 10); // 1 etant le min et 10 le max
    }
};

// Foncteur pour générer des noms de clés uniques aléatoires
struct NomsAleatoiresUniques
{
    static std::set<std::string> nomsUtilises;

    string operator()() const
    {
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        string nom;
        do
        {
            nom = "";
            for (int i = 0; i < 3; ++i)
            {
                nom += alphanum[rand() % (sizeof(alphanum) - 1)];
            }
        } while (nomsUtilises.count(nom) > 0);

        nomsUtilises.insert(nom);

        return nom;
    }
};

std::set<std::string> NomsAleatoiresUniques::nomsUtilises;

// Prototype de la fonction pour générer des valeurs aléatoires
int random_value(int min, int max);

int main()
{

    // 2.1 Création de la map
    map<string, double> m1;

    // 2.2 Ajout de 5 paires dans un vecteur avec des clés uniques et des valeurs aléatoires
    vector<pair<string, double>> paires;
    for (int i = 0; i < 5; ++i)
    {
        paires.push_back({NomsAleatoiresUniques()(), ValeursAleatoires()()});
    }
    // 2.3 Insérer les paires dans la map
    m1.insert(paires.begin(), paires.end());

    // 2.3 Affichage de la map
    for_each(m1.begin(), m1.end(), AfficherMap());

    // 2.4 Suppression de l'élément à la troisième position
    map<string, double>::iterator it = m1.begin();
    advance(it, 2);
    m1.erase(it);

    // 2.4(bis) Affichage de la map après la suppression
    for_each(m1.begin(), m1.end(), AfficherMap());

    // 2.5 Somme des valeurs des paires de la map
    double somme = accumulate(m1.begin(), m1.end(), 0.0, SommeValeursMap());

    // 2.5(bis) Affichage de la somme
    cout << "Somme des valeurs des paires de la map : " << somme << endl;
    // 2.5 Somme des carrés des valeurs des paires de la map

    vector<double> vecteurCarres;
    for (int i = 0; i < 10; ++i)
    { 
        
        double sommeCarres = accumulate(m1.begin(), m1.end(), 0.0, [&](double somme, const auto &paire)
                                        { return somme + CarreDesValeurs()(paire); });

        vecteurCarres.push_back(sommeCarres);
    }
    // 2.5(bis) Affichage du vecteur des carrés
    cout << "Vecteur des carrés des valeurs des paires de la map : ";
    for_each(vecteurCarres.begin(), vecteurCarres.end(), [](double val)
             { cout << val << ", "; });
    cout << endl;

    return 0;
}

// Fonction pour générer des valeurs aléatoires
int random_value(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    std::random_device rd;
    std::mt19937 engine(rd());
    return distribution(engine);
}
