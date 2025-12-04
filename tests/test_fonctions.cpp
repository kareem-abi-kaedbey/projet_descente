#include "../include/fonctions.hpp"
#include <iostream>
using namespace std;

int main() {
    Q1 q1;
    Vecteur x({3, 5});
    cout << "q1(x) = " << q1.f(x) << endl;
    cout << "grad q1(x) = " << q1.grad_f(x) << endl;
}
