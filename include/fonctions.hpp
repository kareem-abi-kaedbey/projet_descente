#ifndef C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C
#define C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C

#include "vecteur.hpp"

class FonctionObjectif{
public:
    virtual Vecteur calculer_gradient(const Vecteur& x) const = 0;
    virtual double evaluer(const Vecteur& x) const = 0;
    virtual ~IFonction() = default;
};

class Q1 : public FonctionObjectif{
public:
    double evaluer(const Vecteur& x) const override;

    Vecteur calculer_gradient(const Vecteur& x) const override;
};

class Q2 : public FonctionObjectif{
public:
    double evaluer(const Vecteur& x) const override;

    Vecteur calculer_gradient(const Vecteur& x) const override;
};

class R : public FonctionObjectif{
public:
    double evaluer(const Vecteur& x) const override;

    Vecteur calculer_gradient(const Vecteur& x) const override;
};

#endif /* C822B61B_3D17_47D8_B5D2_E8C0FC2FA62C */
