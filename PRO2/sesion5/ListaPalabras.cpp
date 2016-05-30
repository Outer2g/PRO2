#include "utils.PRO2"
#include "Palabra.hpp"
#include <vector>
#include "ListaPalabras.hpp"

ListaPalabras::ListaPalabras(){
  paraules=vector <palfrec> (MAXNUMPAL);
  nparaules=0;
}
void ListaPalabras::anadir_palabra(const Palabra& p){
  int n=nparaules;

  for (int i=0;i<n+1;i++){
    bool b=false;
    if (not b and p.iguales(paraules[i].par)){
      paraules[i].freq++;
      b=true;
      cout << "Estaba" << endl;
    }
    else if (paraules[i].par.long_pal() == 0){
      paraules[i].par=p;
      paraules[i].freq=0;
      nparaules++;
      cout << "Nuevo" << endl;
    }
  }
}

int ListaPalabras::longitud_maxima (){
  return MAXNUMPAL;
}

int ListaPalabras::longitud() const{
  return nparaules;
}
int ListaPalabras::max_frec() const{
  int n=nparaules;
  int max=-1;
  for (int i=0;i<n;i++){
    if (paraules[i].freq>max) max=paraules[i].freq;
  }
  return max;
}

void ListaPalabras::escribir_lista() const{
  int n=nparaules;
  for (int i=0;i<n;i++){
    paraules[i].par.escribir_palabra();
  }
}