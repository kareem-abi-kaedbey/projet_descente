#include "../include/affichage.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void afficher_resultat_descente(const IFonction& f,
                                const ResultatDescente& res,
                                const string& titre_sortie,
                                const string& nom_fonction,
                                const string& nom_methode)
{
    if (res.points.empty()) {
        cout << "Aucun point dans le resultat de descente." << endl;
        return;
    }

    const Vecteur& x0 = res.points.front();

    cout << titre_sortie << endl;
    cout << "---" << endl;
    cout << "--- " << nom_methode << " (Pas Fixe)" << endl;
    cout << "---" << endl;

    cout << "Point initial : " << fixed << setprecision(2) << x0 << endl;
    cout << "Fonction : " << nom_fonction << endl;
    cout << "Methode : " << nom_methode << endl;
    cout << "Max-iters : " << res.nb_iters << endl;
    cout << "Iter. Obj. ||Grad|| Point" << endl;

    for (int k = 0; k < (int)res.points.size(); ++k) {
        if (k % 10 == 0) {
            cout << k << " ";
            cout << fixed << setprecision(5) << res.valeurs[k] << " ";
            cout << scientific << setprecision(2) << res.normes_grad[k] << " ";
            cout << fixed << setprecision(2) << res.points[k] << endl;
        }
    }

    const Vecteur& x_final = res.points.back();

    cout << "Solution :" << endl;
    if (res.convergence) {
        cout << "Statut : CONVERGENCE (Tolerance atteinte)" << endl;
    } else {
        cout << "Statut : ARRET (Max-iters atteint)" << endl;
    }
    cout << "Solution : " << fixed << setprecision(2) << x_final << endl;
    cout << "Valeur : " << fixed << setprecision(2) << f.f(x_final) << endl;
}
