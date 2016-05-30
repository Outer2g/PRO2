#include "listIOparint.hpp"

typedef pair<int,int> par;

void busqueda(list<par>& l,int x){
    list<par>::iterator it;
    bool r=false;
    int i=0;
    int suma;
    for (it=l.begin();it != l.end();it++){
        if (not r and x==(*it).first){
            r=true;
            suma=(*it).second;
            i++;
        }
        else if(r and x==(*it).first){
            suma +=(*it).second;
            i++;
        }
    }
    if (i>1){
        cout <<"element" << x << "repetit: "<< i << "vegades" << ", "<< suma << endl;
    }
    else cout << x << ", "<< suma << endl;


}


int main(){
    list <par> l;
    llegir_list(l,-1);
    int x=readint();
    busqueda(l,x);
    escriure_llista(l);
}
