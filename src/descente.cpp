#include "../include/descente.hpp"
#include "../include/fonctions.hpp"
#include <iostream>

ResultatDescente descente_gradient_pas_fixe(const IFonction& f,
                                            const Vecteur& x0,
                                            double alpha,
                                            double eps,
                                            int maxIter)
{
    ResultatDescente res;

    Vecteur x = x0;
    Vecteur g = f.grad_f(x);
    double norm_g = g.norm();
    int k = 0;

    res.points.push_back(x);
    res.valeurs.push_back(f.f(x));
    res.normes_grad.push_back(norm_g);

    while (norm_g > eps && k < maxIter) {
        Vecteur d = g * (-1.0);

        x = x + d * alpha;

        g = f.grad_f(x);
        norm_g = g.norm();

        ++k;

        res.points.push_back(x);
        res.valeurs.push_back(f.f(x));
        res.normes_grad.push_back(norm_g);
    }

    res.nb_iters = k;
    res.convergence = (norm_g <= eps);

    return res;
}
