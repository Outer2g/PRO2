#include "utils.PRO2"
#include "Estudiant.hpp"
#include "cjt_estudiants.hpp"

void afegir(Cjt_estudiants& e){
  int dni= readint();
  double nota=readdouble();
  if (not e.existeix_estudiant(dni)){
    Estudiant est(dni);
    if (nota>=0 and nota <=10){
    est.afegir_nota(nota);
    e.afegir_estudiant(est);
    cout << "done1" << endl;
    }
  }
  else cout << "couldn't add" << endl;
}
void consulta(Cjt_estudiants& e){
  int dni= readint();
  if (e.existeix_estudiant(dni)){
  Estudiant est;
  est=e.consultar_estudiant(dni);
  if (est.te_nota()){
  cout << dni << " " << est.consultar_nota()<< endl;
  }
  else cout << dni << " " << "no te nota" << endl;
  }
  else cout << "unexistent est"<< endl;
}
void modificar(Cjt_estudiants& e){
  int dni= readint();
  double nota= readdouble();
  if (e.existeix_estudiant(dni)){
    Estudiant est(dni);
    est.afegir_nota(nota);
    e.modificar_estudiant(est);
    cout << "done2" << endl;
  }
  else cout << "nope" << endl;
}
void redondeig(Cjt_estudiants& e){
  int n=e.mida();
  for (int i=1;i<=n;++i){
    Estudiant est;
    est = e.consultar_iessim(i);
    est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
    cout << "done3" << endl;
  }
}
void write (Cjt_estudiants& e){
  e.escriure_cjt_estudiants();
}

int main(){
  
  Cjt_estudiants e;
  e.llegir_cjt_estudiants();
  int x= readint();
  while (x != -6){
    if (x==-1){
      afegir(e);
    }
    else if (x==-2){
      consulta(e);
    }
    else if (x==-3){
      modificar(e);
    }
    else if(x==-4){
      redondeig(e);
    }
    else if (x==-5){
      write(e);
    }
    x=readint();
  }
}