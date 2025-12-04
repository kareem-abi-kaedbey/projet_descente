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

    Q2 q2;

    Vecteur x0(3);
    x0[0] = 3.0;
    x0[1] = 5.0;
    x0[2] = 2.0;

    ResultatDescente res = descente_gradient_pas_fixe(q2, x0, alpha, eps, maxIter);

    afficher_resultat_descente(q2, res,
                               "Sorties-2",
                               "x1^2 + 2*x2^2 + 3x_3^2",
                               "Descente Gradient");

    return 0;
}
