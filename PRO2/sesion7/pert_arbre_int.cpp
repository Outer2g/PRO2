#include "ArbIOint.hpp"

bool cerca(Arbre<int>& a, int x)
/* Pre: a=A */
/* Post: El resultat indica si x és a l'arbre A o no */
{
  bool b;
  if (a.es_buit()) b=false;            // if (a.es_buit()) return false;
  else if (a.arrel()==x) b=true;       // if (a.arrel()==x) return true;
  else{                                // return cerca(a1,x) or cerca(a2,x)
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    b=cerca(a1,x);
    if (not b) b= cerca(a2,x);
  }
  return b;
}

int main(){

  Arbre<int> a;
  llegir_arbre_int(a,0);
  int n;
  Arbre<int> b(a);
  cout << "Escrivim b per veure que es igual que a" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Número a cercar: "; 
  cin >> n;
  bool es = cerca(b,n);
  if (es) cout << "Hi és" << endl;
  else cout << "No hi és" << endl;
  cout << "Escrivim b per veure que s'ha destruït durant l'operació" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Escrivim a per veure que no s'ha modificat durant l'operació" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
