#include "ArbIOint.hpp"
int main (){
 
  Arbre<int> a;
  cout << "Pon el arbol en preorden:" << endl;
  llegir_arbre_int(a,0);
  Arbre<int> s;
  a.arb_sumas(s);
  cout << "tam de a: " << a.tam() << endl;
  cout << "tam de suma: "<<s.tam()<<endl;
  cout << "a:" << endl;
  escriure_arbre_int(a);
  cout <<"suma: "<<endl;
  escriure_arbre_int(s);
  cout  << endl;
}
