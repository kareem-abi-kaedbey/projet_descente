#ifndef CA6DA950_35D6_4B67_B276_A86ABBE72C64
#define CA6DA950_35D6_4B67_B276_A86ABBE72C64

#include "vecteur.hpp"
#include <vector>
#include <string>

class IFonction;

struct ResultatDescente {
    std::vector<Vecteur> points;        
    std::vector<double> valeurs;       
    std::vector<double> normes_grad;   

    bool convergence = false;
    int nb_iters = 0;
};

ResultatDescente descente_gradient_pas_fixe(const IFonction& f,
                                            const Vecteur& x0,
                                            double alpha,
                                            double eps,
                                            int maxIter);


#endif /* CA6DA950_35D6_4B67_B276_A86ABBE72C64 */
