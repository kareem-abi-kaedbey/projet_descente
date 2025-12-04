#ifndef C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C
#define C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C

#include "vecteur.hpp"

class IFonction{
public:
    virtual double f(const Vecteur& x) const = 0;
    virtual Vecteur grad_f(const Vecteur& x) const = 0;
    virtual ~IFonction() = default;
};

class Q1 : public IFonction{
public:
    double f(const Vecteur& x) const override;

    Vecteur grad_f(const Vecteur& x) const override;
};

class Q2 : public IFonction{
public:
    double f(const Vecteur& x) const override;

    Vecteur grad_f(const Vecteur& x) const override;
};

class R : public IFonction{
public:
    double f(const Vecteur& x) const override;

    Vecteur grad_f(const Vecteur& x) const override;
};
#endif /* C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C */
