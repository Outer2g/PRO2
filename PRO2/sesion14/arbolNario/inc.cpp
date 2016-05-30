#include "ArbNIOint.hpp"

int main (){
  cout << "Pon la aridad:" << endl;
  ArbreNari<int> a(readint());
  cout << "Pon el arbol en preorden:" << endl;

  llegir_arbre_int(a,0);
  cout << "Pon la aridad:" << endl;
  ArbreNari<int> s(readint());
  a.arb_sumas(s);
  cout << "a:" << endl;
  escriure_arbre_int(a);
  cout <<"suma: "<<endl;
  escriure_arbre_int(s);
  int x= a.maximo();
  cout << "maximo de a: "<<x << endl;
  x=s.maximo();
  cout <<"maximo de la suma: "<<x<<endl;
  cout  << endl;
 }
