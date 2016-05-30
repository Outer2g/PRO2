#include "utils.PRO2"
#include <vector>
#include "Estudiant.hpp"


/* Leer vector */
void leerVector_int(vector<Estudiant>& v) // version accion
{
  cout<<"Escribe el tamaño del vector:"<<endl;
 
  int numEst=readint();
  v = vector<int> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i)
    {
       v[i] = readint();
    }
 }

/* Escribir vector */
void escribirVector_int(const vector<Estudiant>& v)
{
  for (int i=0; i<v.size();++i)
    {
      cout << v[i] << " ";
    }
  cout << endl;
}

//Pre: cierto
//Post: Devuelve la posicion de x en el vector, si se encuentra en el -1 si no
int busqueda_lin(const vector<int> &v, int x)
{
  int tam = v.size();
  int i =0;
  bool b= false;
  while (i<tam and not b) {
    if (v[i]==x){
      b=true;
      return i;
    }
    else ++i;
  }
  return -1;
}

int main ()
{
  vector<int> v;
  leerVector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x = readint();
  int b= busqueda_lin(v,x);
  if (b>=0)  cout << "El elemento " << x << " esta en la posicion "<< b << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribirVector_int(v);
}
