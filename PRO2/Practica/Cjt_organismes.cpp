#include "Cjt_organismes.hpp"


Cjt_organismes::Cjt_organismes(int M){
    orgs=vector<organisme> (M);
    parelles= boole (M,vector<bool> (M));
    Ranking r;
    norg=0;
    morts=0;
}


void Cjt_organismes::estiron_id(){
    int i=readint();
    int x=readint();
    for(int j=0; j<i;++j){
        if(orgs[x-1].estirable())
        orgs[x-1].estiron();
    }
}
void Cjt_organismes::leer_cjt(int n){
    for (int i=0; i<n;i++){
        v[i].leer_organismo();
        ++norg;
    }
}

void Cjt_organismes::recorte_id(){
    int i=readint();
    int x=readint();
    for (int j=0;j<i;++j){
        if (not orgs[x-1].muerto()){
            if(orgs[x-1.recorte()]) ++morts;
        }
    }
}

void Cjt_organismes::consult_id(){
    int i=readint();
    int x=readint();
    for (int j=0;j<i;++j){
        orgs[x-1].escriure_organismo();
    }
}
void Cjt_organismes::consult_round(){
    list<Organisme>::iterator it;
    it=nacidos.begin();
    (*it).escriure_organismo();
}
void Cjt_organismes::ronda(){
    int n=norg;
    list <int> nacidos;
    list<int>::iterator it=nacidos.end();
    bool p=false;
    int i=1;
    while(not p and i<norg){
        bool exit=false;
        int j=i+1;
        while (not exit and j<norg){
            bool posible=false;
            if (not parelles[i][i] and not parelles[i][j]){
                orgs[n-1]=orgs[i-1].reproduccion_org(orgs[j-1],x,b);
                if (b){
                    nacidos.insert(it,n)
                    r.nuevo_organismo(n);
                    r.nuevo_hijo(i,j,n);
                }
                ++n;
                parelles[i][j]=true;
                parelles[i][i]=true;
                exit=true;
                ++j;
            }

            }
        if (n==n.size())p=true;
        }
    if(p) fiexp(nacidos);
    else{
    for(int j=0;j<norg;++j){
        parelles[j][j]=false;
    }
    }
    org=n;
}
void Cjt_organismes::fiexp(list<int>& l){
    list <int>::iterator it=nacidos.begin();
    while (it<nacidos.end()){
        orgs[(*it)-1].escriure_organismo();
    }
}
