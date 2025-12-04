#ifndef CA6DA950_35D6_4B67_B276_A86ABBE72C64
#define CA6DA950_35D6_4B67_B276_A86ABBE72C64

#include "vecteur.hpp"

class IFonction;

// Descente de gradient à pas fixe générique
Vecteur descente_gradient_pas_fixe(const IFonction& f,
                                   const Vecteur& x0,
                                   double alpha,
                                   double eps,
                                   int maxIter);

#endif /* CA6DA950_35D6_4B67_B276_A86ABBE72C64 */
