#include "listIOparint.hpp"

typedef pair<int,int> par;

void busqueda(list<par>& l,int x){
    list<par>::iterator it;
    for (it = l.begin();it != l.end();it++){
        (*it).second +=x;
    }

}


int main(){
    list <par> l;
    llegir_list(l,-1);
    int x=readint();
    busqueda(l,x);
    escriure_llista(l);
}
