#include "PilaIOint.hpp"


int main(){

  Pila<int> p;
  cout << "Entra pila naturals (acabada per -1): " << endl;
  llegir_pila_int(p,-1);
  cout << "Entra n�mero a buscar: " << endl;
  int x = readint();
  bool b;
    b = p.cerca_pila(x);

  if (b) cout << "esta" << endl;
  else cout << "no esta" << endl;
  cout << "pila p, despues de buscar (notad que no se destruye en ningun caso, aunque no se ha usado copia)" << endl;
  escriure_pila_int(p);

}
