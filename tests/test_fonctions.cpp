#include "../include/fonctions.hpp"
#include <iostream>
using namespace std;

int main() {
    Q1 q1;
    Vecteur<2> x({2, 5});
    cout << "q1(x) = " << q1.evaluer(x) << endl;
    cout << "grad q1(x) = " << q1.calculerGradient(x) << endl;

    Q2 q2;
    Vecteur<3> y({2, 5, 3});
    cout << "q2(y) = " << q2.evaluer(y) << endl;
    cout << "grad q2(y) = " << q2.calculerGradient(y) << endl;
    
    R r;
    Vecteur<2> z({2, 5});
    cout << "r(z) = " << r.evaluer(z) << endl;
    cout << "grad r(z) = " << r.calculerGradient(z) << endl;
    
}
