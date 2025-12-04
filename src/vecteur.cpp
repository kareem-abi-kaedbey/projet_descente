#include "../include/vecteur.hpp"
#include <cmath>

Vecteur::Vecteur(int n){
    coordonnees.resize(n, 0.0);    
}

Vecteur::Vecteur(const std::vector<double>& data) : coordonnees(data){}

int Vecteur::size() const{
    return coordonnees.size();
}
double Vecteur::norm() const{
    double s = 0.0;
    for (int i = 0; i < (int)coordonnees.size(); i++){
        s += coordonnees[i] * coordonnees[i];
    }
    return sqrt(s);
}

double& Vecteur::operator[](int i){
    return coordonnees[i];
}

const double& Vecteur::operator[](int i) const{
    return coordonnees[i];
}

Vecteur Vecteur::operator+(const Vecteur& other) const{
    Vecteur somme(other.size());
    for (int i = 0; i < other.size(); i++){
        somme[i] = coordonnees[i] + other[i];
    }
    return somme;
}

Vecteur Vecteur::operator-(const Vecteur& other) const{
    Vecteur soustraction(other.size());
    for (int i = 0; i < other.size(); i++){
        soustraction[i] = coordonnees[i] - other[i];
    }
    return soustraction;
}

Vecteur Vecteur::operator*(double lambda) const{
    Vecteur mult(coordonnees.size());
    for (int i = 0; i < (int)coordonnees.size(); i++){
        mult[i] = coordonnees[i] * lambda;
    }
    return mult;
}

std::ostream& operator<<(std::ostream& os, const Vecteur& v){
    os << "(";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i < v.size() - 1)
            os << ", ";
    }
    os << ")";
    return os;
}
