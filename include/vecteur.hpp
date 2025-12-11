#ifndef C5C32BA7_EC66_44CC_9C82_67DFE329ABAF
#define C5C32BA7_EC66_44CC_9C82_67DFE329ABAF

#include <iostream>
#include <ostream>
#include <cmath>
#include <array>

template <size_t N>
class Vecteur{
public:
    std::array<double, N> coordonnees;

    Vecteur(){
        coordonnees.fill(0.0);
    }

    Vecteur(const std::array<double, N>& data){
        coordonnees = data;
    }

    size_t size() const{
        return N;
    }

    double norm() const{
        double s = 0.0;
        for (size_t i = 0; i < N; i++){
            s += coordonnees[i] * coordonnees[i];
        }
        return std::sqrt(s);
    }
    
    double& operator[] (size_t i){
        return coordonnees[i];
    }

    const double& operator[] (size_t i) const{
        return coordonnees[i];
    }

    Vecteur operator+(const Vecteur& other) const{
        Vecteur<N> somme;
        for (size_t i = 0; i < N; i++){
            somme[i] = coordonnees[i] + other[i];
        }
        return somme;
    }

    Vecteur operator-(const Vecteur& other) const{
        Vecteur<N> sous;
        for (size_t i = 0; i < N; i++){
            sous[i] = coordonnees[i] - other[i];
        }
        return sous;
    }
    Vecteur operator*(double lambda) const{
        Vecteur<N> mult;
        for (size_t i = 0; i < N; i++){
            mult[i] = coordonnees[i] * lambda;
        }
        return mult;
    }

    ~Vecteur() = default;

};

template<size_t N>
std::ostream& operator<<(std::ostream& os, const Vecteur<N>& v){
    os << "(";
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i];
        if (i < v.size() - 1)
            os << ", ";
    }
    os << ")";
    return os;
}

#endif /* C5C32BA7_EC66_44CC_9C82_67DFE329ABAF */
