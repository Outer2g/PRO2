#include "arbreIOparint.hpp"




void busqueda(Arbre <par>& a,int x, bool& found){
    Arbre <par> a1;
    Arbre <par> a2;
    par p;
    if (not found and not a.es_buit()){
        p=a.arrel();
        if (p.first==x){
            cout<< p.first << ","<< p.second<< endl;
            found=true;
        }
        else{
           a.fills(a1,a2);
           busqueda(a1,x,found);
           busqueda(a2,x,found);
           a.plantar(p,a1,a2);
    }
    }
    }







int main(){
    Arbre<par> a;
    llegir_arbre(a,-1);
    int x=readint();
    bool f=false;
    busqueda (a,x,f);
    if (not found) cout << "not found"<<endl;
    escriure_arbre(a);
}
