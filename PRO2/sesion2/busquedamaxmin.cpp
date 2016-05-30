#include "utils.PRO2"
#include "Estudiant.hpp"
#include <vector>

void leer_vector(vector<Estudiant>& V){
  int n=V.size();
  for (int i=0;i<n;++i){
    V[i].llegir_estudiant();
  }
}

void escribir_estudiant(vector<Estudiant>& v,int i,int j){
  if (i!=-1 and j!=11){
  cout << "Estudiante nota maxima: ";
  v[i].escriure_estudiant();
  cout << "Estudiante nota minima: ";
  v[j].escriure_estudiant();
  }
  else cout <<"El estudiante no tiene nota" << endl;
}
void busqueda_maxmin(const vector<Estudiant> &v,int&z,int&j){
  int n=v.size();
  int max=-1;
  int min=11;
  for (int i=0;i<n;++i){
    if (v[i].te_nota()){
      if(v[i].consultar_nota()>max){
	max=v[i].consultar_nota();
	z=i;
      }
      if (v[i].consultar_nota()<min){
	min=v[i].consultar_nota();
	j=i;
      }
      if (v[i].consultar_nota()==max){
	if (v[i].consultar_DNI() <v[z].consultar_DNI()) z=i;
      }
      if (v[i].consultar_nota()==min){
	if (v[i].consultar_DNI()<v[j].consultar_DNI()) j=i;
      }
    }
    z=-1;
    j=11;
  }
}

int main(){
  int x= readint();
  vector <Estudiant> V(x);
  leer_vector(V);
  int z,j;
  busqueda_maxmin(V,z,j);
  escribir_estudiant(V,z,j);
}