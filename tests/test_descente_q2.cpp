#include "../include/vecteur.hpp"
#include "../include/fonctions.hpp"
#include "../include/Optimiseur.hpp"
#include <iostream>

using namespace std;

int main() {
    Q2 q2;
    DescenteGradient<3> opt(q2);
    Vecteur<3> depart;
    depart[0] = 3.0;
    depart[1] = 5.0;
    depart[2] = 2.0;
    opt.optimiser(depart);

    return 0;
}
