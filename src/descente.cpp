#include "../include/descente.hpp"
#include "../include/fonctions.hpp"
#include <iostream>
#include <iomanip>   

using namespace std;


Vecteur descente_gradient_pas_fixe(const IFonction& f,
                                   const Vecteur& x0,
                                   double alpha,
                                   double eps,
                                   int maxIter)
{
    Vecteur x = x0;
    Vecteur g = f.grad_f(x);
    double norm_g = g.norm();
    int k = 0;

    cout << k << " ";
    cout << fixed << setprecision(5) << f.f(x) << " ";
    cout << scientific << setprecision(2) << norm_g << " ";
    cout << fixed << setprecision(2) << x << endl;

    while (norm_g > eps && k < maxIter) {

        Vecteur d = g * (-1.0);

        x = x + d * alpha;

        g = f.grad_f(x);
        norm_g = g.norm();

        ++k;

        if (k % 10 == 0) {
            cout << k << " ";
            cout << fixed << setprecision(5) << f.f(x) << " ";
            cout << scientific << setprecision(2) << norm_g << " ";
            cout << fixed << setprecision(2) << x << endl;
        }
    }

    return x;
}
