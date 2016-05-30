#ifndef ARBIOINT_HPP
#define ARBIOINT_HPP

#include "ArbreN.hpp"

// tanto la lectura como la escritura son en preorden

// para la lectura, los arboles vacios se denotan mediante la marca;
// ver ejemplo en inc.dat

void llegir_arbre_int(ArbreNari<int>& a, int marca)
//Pre: a es buit
//Post: a conté l'arbre llegit de l'entrada
{
  int x;
  cin >> x;
  if (x!= marca) {
    int ari = a.aritat();
    vector<ArbreNari<int> > vect(ari, ArbreNari<int>(ari));
    for (int i=0; i<ari; ++i){
      llegir_arbre_int(vect[i], marca);
    }
    a.plantar(x,vect);
  }
}

void escriure_arbre_int( ArbreNari<int> &a) {
    if (a.es_buit()){
        cout << " 0 ";
    }
  if (not a.es_buit()) {
    int x =a.arrel();
    cout<< x  << " ";
    vector<ArbreNari<int> > v;  
    a.fills(v);      
    for (int i=0; i<a.aritat(); ++i) {
      escriure_arbre_int(v[i]);
    }
    a.plantar(x,v);
  }
}

#endif
