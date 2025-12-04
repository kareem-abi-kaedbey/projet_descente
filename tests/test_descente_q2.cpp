#include "../include/vecteur.hpp"
#include "../include/fonctions.hpp"
#include "../include/descente.hpp"
#include <iostream>
#include <iomanip>

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

    cout << "---" << endl;
    cout << "--- Descente de Gradient (Pas Fixe)" << endl;
    cout << "---" << endl;
    cout << "Point initial : " << fixed << setprecision(2) << x0 << endl;
    cout << "Fonction : x1^2 + 2*x2^2 + 3x_3^2" << endl;
    cout << "Methode : Descente Gradient" << endl;
    cout << "Max-iters : " << maxIter << endl;
    cout << "Iter. Obj. ||Grad|| Point" << endl;

    Vecteur sol = descente_gradient_pas_fixe(q2, x0, alpha, eps, maxIter);

    cout << "Solution :" << endl;
    cout << "Statut : CONVERGENCE (Tolerance atteinte)" << endl;
    cout << "Solution : " << fixed << setprecision(2) << sol << endl;
    cout << "Valeur : " << fixed << setprecision(2) << q2.f(sol) << endl;

    return 0;
}
