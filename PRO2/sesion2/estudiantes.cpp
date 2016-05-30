#include "utils.PRO2"
#include "Estudiant.hpp"
#include <vector>

void leer_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i){
    V[i].llegir_estudiant();
  }
}

void escribir_estudiant(vector<Estudiant>& v,int j){
  for (int i=0; i<j;++i){
    v[i].escriure_estudiant();
  }
}
vector<Estudiant> simplificar(vector<Estudiant>&v,int&j){
  int n= v.size();
  vector<Estudiant> S(n);
  S[0]=v[0];
  j=1;
  for (int i=1;i<n;++i){
    if (v[i].consultar_DNI() != v[i-1].consultar_DNI()){
      S[j]=v[i];
      ++j;
    }
    else if (v[i].te_nota() and not v[i-1].te_nota()) S[j-1]=v[i];
    else if (v[i].te_nota() and v[i-1].te_nota()){
      if (v[i].consultar_DNI()== v[i-1].consultar_DNI()){
	if (v[i].te_nota()and v[i].consultar_nota()>v[i-1].consultar_nota())
	  S[j-1]=v[i];
      }
    }
  }
  return S;
}

int main(){
  int x= readint();
  vector <Estudiant> V(x);
  leer_vector(V);
  vector <Estudiant> S(x);
  int j;
  S= simplificar(V,j);
  escribir_estudiant(S,j);
}