#include "utils.PRO2"
#include "Poli.hpp"


int  main () 
{
  cout <<"Escribe una marca: ";
  int marca = readint();
  cout << "Escribe dos polinomios acabados por la marca " << endl;
  Poli p1;
  p1.leer_poli(marca);
  Poli p2;
  p2.leer_poli(marca);
  cout << "p1 antes de sumar: "<< endl;
  p1.escribir_poli();
  cout << "p2 antes de sumar: "<< endl;
  p2.escribir_poli();
  p1.suma_poli(p2);
  cout << "p1 despues de sumar: "<< endl;
  p1.escribir_poli();
  cout << "p2 despues de sumar: "<< endl;
  p2.escribir_poli();
  
}

