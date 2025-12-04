#include "../include/fonctions.hpp"

// ======= Q1 =======

double Q1::f(const Vecteur& x) const{
    return x[0] * x[0] + 2 * x[1] * x[1];
}

Vecteur Q1::grad_f(const Vecteur& x) const{
    Vecteur res(2);
    res[0] = 2 * x[0];
    res[1] = 4 * x[1];
    return res;
}

// ======= Q2 =======

double Q2::f(const Vecteur& x) const{
    return x[0] * x[0] + 2 * x[1] * x[1] + 3 * x[2] * x[2];
}

Vecteur Q2::grad_f(const Vecteur& x) const{
    Vecteur res(3);
    res[0] = 2 * x[0];
    res[1] = 4 * x[1];
    res[2] = 6 * x[2];
    return res;
}

// ======= R =======

double R::f(const Vecteur& x) const{
    return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
}

Vecteur R::grad_f(const Vecteur& x) const{
    Vecteur res(2);
    res[0] = - 2 * (1 - x[0]) - 400 * x[0] * (x[1] - x[0] * x[0]);
    res[1] = 200 * (x[1] - x[0] * x[0]);
    return res;
}