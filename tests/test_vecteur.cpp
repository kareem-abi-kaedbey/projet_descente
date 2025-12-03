# include <iostream>
# include "../include/vecteur.hpp"
using namespace std;

int main(){
    cout << "=== Test : vecteur.cpp ===" << endl;
    
    Vecteur a({1,2,3});
    Vecteur b({-2,4,6});
    cout << a + b << endl;
    cout << a - b << endl;
    cout << b * 3 << endl;
    cout << a.norm() << endl;
    return 0;
}