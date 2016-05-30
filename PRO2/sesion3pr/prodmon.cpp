#include "Poli.hpp"

void mult_poli_mon(const Poli& pol, int n, int i, Poli& res) 
  /* Pre: res es el polinomio 0; i>=0, 
     i + pol.grado() <= grado maximo permitido */
  /* Post: res = pol * nx^i */
{ 
  if (n!=0) {
    int j=0;
    while (j<=pol.grado()) { 
      res.modif_coef(n*pol.coef(j),j+i);
      j++;
    }
  }
}

int  main () 
{
  cout <<"Escribe una marca: ";
  int marca = readint();
  cout << "Escribe un polinomio acabado por la marca " << endl;
  Poli p1;
  p1.leer_poli(marca);
  cout << "Escribe el coeficiente y el exponente del monomio " << endl;
  int coef = readint();
  int expo = readint();
  Poli q;
  mult_poli_mon(p1,coef,expo,q);

  cout << "el resultado es: "<< endl;
  q.escribir_poli();  
}
