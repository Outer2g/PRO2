#include "utils.PRO2"
#include "Arbre.hpp"


typedef pair<int,int> par;

void llegir_arbre (Arbre<par>& a, int marca){
    Arbre<par> a1;
    Arbre<par> a2;
    par p;
    p.first=readint();
    while (p.first!=marca){
        p.second=readint();
        llegir_arbre(a1,marca);
        llegir_arbre(a2,marca);
        a.plantar(p,a1,a2);
        p.first=readint();
    }
}

void escriure_arbre(Arbre<par>& a){
    Arbre<par> a1;
    Arbre<par> a2;
    if (not a.es_buit()){
        cout << a.arrel().first << ", " << a.arrel().second << endl;
        a.fills(a1,a2);
        escriure_arbre(a1);
        escriure_arbre(a2);
    }
}
