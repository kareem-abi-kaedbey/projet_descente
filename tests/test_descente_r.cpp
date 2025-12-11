#include "../include/vecteur.hpp"
#include "../include/fonctions.hpp"
#include "../include/Optimiseur.hpp"
#include <iostream>

using namespace std;

int main() {
    R r;
    PlusFortePente<2> opt(r);
    Vecteur<2> depart;
    depart[0] = 3.0;
    depart[1] = 5.0;
    opt.optimiser(depart);

    return 0;
}
