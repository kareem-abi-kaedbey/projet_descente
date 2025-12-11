#include "../include/vecteur.hpp"
#include "../include/fonctions.hpp"
#include "../include/Optimiseur.hpp"
#include <iostream>

using namespace std;

int main() {
    Q1 q1;
    DescenteGradient<2> opt(q1);
    Vecteur<2> depart;
    depart[0] = 3.0;
    depart[1] = 5.0;
    opt.optimiser(depart);

    return 0;
}
