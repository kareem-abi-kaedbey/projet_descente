#ifndef C5C32BA7_EC66_44CC_9C82_67DFE329ABAF
#define C5C32BA7_EC66_44CC_9C82_67DFE329ABAF

#include <vector>
#include <ostream>

class Vecteur{
private:
    std::vector<double> coordonnees;

public:
    Vecteur(int n);
    Vecteur(const std::vector<double>& data);
    int size () const;

    double norm() const;

    double& operator[] (int i);
    const double& operator[] (int i) const;

    Vecteur operator+(const Vecteur& other) const;
    Vecteur operator-(const Vecteur& other) const;
    Vecteur operator*(double lambda) const;


};

std::ostream& operator<<(std::ostream& os, const Vecteur& v);


#endif /* C5C32BA7_EC66_44CC_9C82_67DFE329ABAF */
