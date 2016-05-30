#include "utils.PRO2"
#include <vector>

typedef vector<vector <int> > Matrix;

Matrix producto(Matrix& a, Matrix& b){
  int n= a.size();
  int m= b[0].size();
  Matrix prod(n,vector<int> (m));
  for (int i=0; i<n;++i){
    for (int j=0; j<m; ++j){
      int p= a[0].size();
      for (int x=0; x<p;++x){
	prod[i][j]+= a[i][x]*b[x][j];
      }
    }
  }
  return prod;
}
int main(){
  int n= readint();
  int m= readint();
  Matrix a (n,vector<int>(m));
  for (int i=0; i<n; ++i) for (int j=0;j<m;++j) a[i][j]=readint();
  n= readint();
  m= readint();
  Matrix b(n,vector<int>(m));
  for (int i=0; i<n; ++i) for (int j=0;j<m;++j) b[i][j]=readint();
  Matrix c= producto(a,b);
  n= c.size();
  m=c[0].size();
  for (int i=0; i<n; ++i){
    for (int j=0;j<m;++j){
    cout << c[i][j];
  }
  cout << endl;
}
  
}

