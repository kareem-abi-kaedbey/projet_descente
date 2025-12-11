#ifndef C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C
#define C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C

#include "vecteur.hpp"

template<size_t N>
class FonctionObjective{
public:
    virtual double evaluer(const Vecteur<N>& x) const = 0;
    virtual Vecteur<N> calculerGradient(const Vecteur<N>& x) const = 0;
    virtual ~FonctionObjective() = default;
};

class Q1 : public FonctionObjective<2>{
public:
    double evaluer(const Vecteur<2>& x) const override{
        return x[0] * x[0] + 2 * x[1] * x[1];
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override{
        Vecteur<2> res;
        res[0] = 2 * x[0];
        res[1] = 4 * x[1];
        return res;
    }
};

class Q2 : public FonctionObjective<3>{
public:
    double evaluer(const Vecteur<3>& x) const override{
        return x[0] * x[0] + 2 * x[1] * x[1] + 3 * x[2] * x[2];
    }

    Vecteur<3> calculerGradient(const Vecteur<3>& x) const override{
        Vecteur<3> res;
        res[0] = 2 * x[0];
        res[1] = 4 * x[1];
        res[2] = 6 * x[2];
        return res;
    }
};

class R : public FonctionObjective<2>{
public:
    double evaluer(const Vecteur<2>& x) const override{
        return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override{
        Vecteur<2> res;
        res[0] = - 2 * (1 - x[0]) - 400 * x[0] * (x[1] - x[0] * x[0]);
        res[1] = 200 * (x[1] - x[0] * x[0]);
        return res;
    }
};

#endif /* C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C */
