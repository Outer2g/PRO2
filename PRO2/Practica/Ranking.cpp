#include "Ranking.hpp"



Ranking::Ranking(int M){
    emparejamientos= vector<list <need> > (M);
    ordenados=vector<need> (M);
    n=0;
}

void Ranking::nuevo_hijo(int x, int y, int z){
    int i=0;
    bool found=false;
    bool found1=false;
    bool found2=false;
    int p,j;
    while (not found and i<n){
        if(ordenados[i].p == x){
            ++ordenados[i].s;
            found1=true;
            p=i;
        }
        if(ordenados[i].p == y){
            ++ordenados[i].s;
            found2=true;
            j=i;
        }
        found=(found1 and found2);
        ++i;
    }
    actualitzar(p);
    actualitzar(j);
    need d;
    d.p=y;
    d.s=z;
    emparejamientos[x-1].insert(emparejamientos[x-1].end(),d);
    d.p=x;
    emparejamientos[y-1].insert(emparejamientos[y-1].end(),d);
}
void Ranking::actualitzar(int x){
        for (int i=0;i<x;++i){
        if (ordenados[x].s>ordenados[x-1].s){
            need aux=ordenados[x-1];
            ordenados[x-1]=ordenados[x];
            ordenados[x]=aux;
        }
        if (ordenados[x].s==ordenados[x-1].s and ordenados[x].p<ordenados[x-1].p){
            need aux=ordenados[x-1];
            ordenados[x-1]=ordenados[x];
            ordenados[x]=aux;
        }
    }
}

void Ranking::nuevo_organismo(int x){
    n+=1;
    need d;
    d.p=x;
    d.s=0;
    ordenados[n-1]=d;
    actualitzar(n-1);
}

void Ranking::escribir_rank(){
    for (int i=0;i<n;++i){
        cout << ordenados[i].p<< ": ";
        list<need>::iterator it,it2;
        it=emparejamientos[ordenados[i].p-1].begin();
        it2=emparejamientos[ordenados[i].p-1].end();
        while (it != it2){
            cout<< (*it).p << " " << (*it).s << " ";
            ++it;
        }
        cout << endl;
    }
}

























