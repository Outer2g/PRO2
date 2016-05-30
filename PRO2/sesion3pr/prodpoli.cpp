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

void mult_poli(const Poli& p1, const Poli& p2, Poli& prod) 
  /* Pre: prod es el polinomio 0; 
     p1.grado() + p2.grado() <= grado maximo permitido */
  /* Post: prod = p1*p2 */
{
  int i=0;
  while (i<=p2.grado()) {
    Poli aux;
    mult_poli_mon(p1,p2.coef(i),i,aux);
    prod.suma_poli(aux);
    i++;
  }
}

int  main () 
{
  cout <<"Escribe una marca: ";
  int marca = readint();
  cout << "Escribe dos polinomios acabados por la marca " << endl;
  Poli p1;
  Poli p2;
  p1.leer_poli(marca);
  p2.leer_poli(marca);
  Poli q;
  mult_poli(p1,p2,q);

  cout << "el resultado es: "<< endl;
  q.escribir_poli();  
}
