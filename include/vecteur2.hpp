#include <array>
#include <iostream>
#include <cmath>

template <size_t N>
std::ostream& operator<<(std::ostream& os, const Vecteur<N>& v) {
    os << "[";
    for (size_t i = 0; i < N; ++i) {
        os << v[i];
        if (i + 1 < N) os << ", ";
    }
    os << "]";
    return os;
}

template <size_t N>
class Vecteur {
private:
    std::array<double, N> coordonnees{};

public:
    
    Vecteur() {
        coordonnees.fill(0.0);
    }

    
    Vecteur(const std::array<double, N>& data) : coordonnees(data) {}

    
    Vecteur(std::initializer_list<double> init) {
        size_t i = 0;
        for (double v : init) {
            if (i < N) coordonnees[i++] = v;
        }
    }

    double norm() const {
        double s = 0.0;
        for (size_t i = 0; i < N; i++) {
            s += coordonnees[i] * coordonnees[i];
        }
        return std::sqrt(s);
    }

    double& operator[](size_t i) {
        return coordonnees[i];
    }

    const double& operator[](size_t i) const {
        return coordonnees[i];
    }

    Vecteur operator+(const Vecteur& other) const {
        Vecteur somme;
        for (size_t i = 0; i < N; ++i) {
            somme[i] = coordonnees[i] + other[i];
        }
        return somme;
    }

    Vecteur operator-(const Vecteur& other) const {
        Vecteur diff;
        for (size_t i = 0; i < N; ++i) {
            diff[i] = coordonnees[i] - other[i];
        }
        return diff;
    }

    Vecteur operator*(double lambda) const {
        Vecteur mult;
        for (size_t i = 0; i < N; ++i) {
            mult[i] = coordonnees[i] * lambda;
        }
        return mult;
    }
};
