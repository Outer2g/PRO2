#include "ArbGIOint.hpp"

int main(){

  ArbreGen<int> a;
  cout << "Pon los valores del arbol general en preorden" << endl;
  llegir_arbre_int(a,0);
  cout << "Escribimos el arbol general en preorden" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
