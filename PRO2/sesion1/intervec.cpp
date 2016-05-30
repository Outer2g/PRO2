#include "utils.PRO2"
#include <vector>

void intercanvi(int& a, int& b){
  int aux= a;
  a=b;
  b=aux;
}

void intercambiar_vect (vector<int>&v, int i,int j){
  intercanvi(v[i],v[j]);
}
int main(){
  int n= readint();
  vector <int> M(n);
  for (int i=0; i<n;++i) M[i]=readint();
  int i=readint();
  int j=readint();
  intercambiar_vect(M,i,j);
  for (int i=0; i<n;++i) cout << M[i]<< " " << endl;
}