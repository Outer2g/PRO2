#include "utils.PRO2"
#include "Cjt_estudiants.hpp"
#include "estudiant.hpp"

void Actualitzar(Cjt_estudiants& e1,Cjt_estudiants& e2){
  int n= e1.mida();
  for (int i=1;i<=n;++i){
    Estudiant est1,est2;
    est1=e1.consultar_iessim(i);
    est2=e2.consultar_iessim(i);
    if (not est1.te_nota() and est2.te_nota()) e1.modificar_estudiant(est2);
    else if (est1.te_nota() and est2.te_nota()){
     if (est1.consultar_nota()<est2.consultar_nota())e1.modificar_estudiant(est2); 
    }
  }
}

int main(){
  Cjt_estudiants e1;
  Cjt_estudiants e2;
  e1.llegir_cjt_estudiants();
  e2.llegir_cjt_estudiants();
  Actualitzar(e1,e2);
  e1.escriure_cjt_estudiants();
}