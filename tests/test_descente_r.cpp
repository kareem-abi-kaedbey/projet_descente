#include "../include/vecteur.hpp"
#include "../include/fonctions.hpp"
#include "../include/descente.hpp"
#include "../include/affichage.hpp"
#include <iostream>


using namespace std;

int main() {
    double alpha = 0.1;
    double eps = 1e-6;
    int maxIter = 100;

    R r;

    Vecteur x0(2);
    x0[0] = 0.0;
    x0[1] = 0.0;

    ResultatDescente res = descente_gradient_pas_fixe(r, x0, alpha, eps, maxIter);

    afficher_resultat_descente(r, res,
                               "Sorties-Rosenbrock",
                               "(1 - x1)^2 + 100 * (x2 - x1^2)^2",
                               "Descente Gradient");

    return 0;
}
// on remarque que cette fonction explose avant d'arriver 
// meme a 10 iterations on obtient nan et inf (des valeurs
// non representables par des doubles). 
// Cela est du a la forme particuliere de cette fonction 
// qui exige un pas de deplacement plus petit pour avoir
// une chance de converger.