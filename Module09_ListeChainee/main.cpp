#include <iostream>
#include "listeChainee.h"
#include "node.h"

void afficherElement(const int& valeur);
bool comparerCroissant(const int& p_valeur1, const int& p_valeur2);

int main()
{
    ListeChainee liste;

    liste.ajouterDebut(5);
    liste.ajouterDebut(10);
    liste.ajouterFin(3);
    liste.inserer(7, 2);

    std::cout << "Liste initiale: ";
    liste.parcourir(afficherElement);
    std::cout << std::endl;
    int x = liste.obtenir(1);
    std::cout << "liste.obtenir(1): " << x << std::endl;
    liste.supprimerA(2);
    std::cout << "Liste - fin: ";
    liste.parcourir(afficherElement);
    std::cout << std::endl;

    liste.supprimerDebut();
    std::cout << "Liste - debut: ";
    liste.parcourir(afficherElement);
    std::cout << std::endl;
    liste.trier(comparerCroissant);

    std::cout << "Liste triee: ";
    liste.parcourir(afficherElement);
    std::cout << std::endl;

    return 0;
}
void afficherElement(const int& valeur) {
    std::cout << valeur << " ";
}

// Fonction de comparaison pour le tri croissant
bool comparerCroissant(const int& a, const int& b) {
    return a < b; // Modifiez ici pour trier en ordre décroissant si nécessaire
}