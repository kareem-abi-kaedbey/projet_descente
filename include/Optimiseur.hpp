#ifndef A5A5FAD2_D9E1_4D7E_9974_2F303BE9C2EF
#define A5A5FAD2_D9E1_4D7E_9974_2F303BE9C2EF

#include"vecteur.hpp"
#include"fonctions.hpp"
#include<iostream>
#include<iomanip>
#include"pas_deplacement/PasFixe.hpp"


template<size_t N>
class Optimiseur{
protected : 
    const FonctionObjective<N>& f;
    PasFixe<N>& pas;
    double epsilon = 1e-6;
    int max_iter = 1000;

public:
    Optimiseur(const FonctionObjective<N>& f_obj,PasFixe<N>& pas1) : f(f_obj){
        this->pas = pas1;
    }

    virtual Vecteur<N> calculerDirection(const Vecteur<N>& x) const = 0;

    virtual ~Optimiseur() = default;
    
    void optimiser(Vecteur<N>& depart){
        Vecteur<N> x = depart;
        Vecteur<N> g_f = f.calculerGradient(x);
        double norm_g = g_f.norm();
        int k = 0;
        Vecteur<N> dirDescente;
        std::cout << "---\n--- Descente de Gradient (Pas Fixe)\n---\n";
        std::cout << "   Point initial : " << depart << std::endl;
        std::cout << "   Methode : Descente Gradient" << std::endl;
        std::cout << "   Max-iters : " << max_iter << std::endl;
        std::cout << "Iter Obj ||Grad|| Point" << std::endl;
        while ((k < max_iter) and (norm_g > epsilon)){
            dirDescente = calculerDirection(x);

            x = x + dirDescente * pas.calculerPas(x,-norm_g,g_f,f);
            g_f = f.calculerGradient(x);
            norm_g = g_f.norm();
            if (k%10 == 0){
                std::cout << k << " ";
                std::cout << std::fixed << std::setprecision(5) << f.evaluer(x) << " ";
                std::cout << std::scientific << std::setprecision(2) << norm_g << " ";
                std::cout << std::fixed << std::setprecision(2) << x << std::endl;
            }
            k++; 
        }
        std::cout << "Solution :\n    Statut : " ;
        if (k == max_iter){
            std::cout << "DIVERGENCE (max_iter atteint)\n";  
        }else{
            std::cout << "CONVERGENCE (Tolerance atteinte)" << std::endl;
            std::cout << "Solution : " << x << std::endl;
            std::cout << "Valeur : " << f.evaluer(x) << std::endl;
        }
        return;
    }

};

template <size_t N>
class DescenteGradient : public Optimiseur<N> {
public:
    using Optimiseur<N>::Optimiseur;

    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override {
        Vecteur<N> g = this->f.calculerGradient(x);
        return g * (-1.0);
    }
};

template <size_t N>
class PlusFortePente : public Optimiseur<N> {
public:
    using Optimiseur<N>::Optimiseur;

    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override {
        Vecteur<N> g = this->f.calculerGradient(x);
        double n = g.norm();
        if (n < 1e-12) return g;
        return g * (-1.0 / n);
    }
};



#endif /* A5A5FAD2_D9E1_4D7E_9974_2F303BE9C2EF */
