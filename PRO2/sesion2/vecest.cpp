#include "utils.PRO2"
#include "Estudiant.hpp"
#include <vector>

void leer_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i){
    V[i].llegir_estudiant();
  }
}
void redondear_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i)if(V[i].te_nota())
  V[i].modificar_nota(((int) (10. * (V[i].consultar_nota() + 0.05))) / 10.0);
}
void escribir_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i) V[i].escriure_estudiant();
}


int main(){
  int x= readint();
  vector <Estudiant> V(x);
  leer_vector(V);
  redondear_vector(V);
  escribir_vector(V);
}