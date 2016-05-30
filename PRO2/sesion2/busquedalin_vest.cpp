#include "utils.PRO2"
#include "Estudiant.hpp"
#include <vector>

void leer_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i){
    V[i].llegir_estudiant();
  }
}

void escribir_estudiant(vector<Estudiant>& V, int x){
  if (x==-1) cout << "estudiante no tiene nota" << endl;
  else if (V[x].te_nota()) cout << "nota estudiante: " << V[x].consultar_nota()<< endl;
  else cout << "estudiante no encontrado" << endl;
}
int busqueda_lin(const vector<Estudiant> &v, int x)
{
  int tam = v.size();
  int i =0;
  bool b= false;
  while (i<tam) {
    if (v[i].consultar_DNI() ==x){
      b=true;
      return i;
    }
    else ++i;
  }
  return -1;
}

int main(){
  int x= readint();
  vector <Estudiant> V(x);
  leer_vector(V);
  x=readint();
  x=busqueda_lin(V,x);
  escribir_estudiant(V,x);
}