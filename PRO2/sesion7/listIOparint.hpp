#include "Utils.PRO2"
#include <list>

typedef pair<int,int> par;

void llegir_list(list <par>& l, int marca){
    list<par>::iterator it=l.begin();
    par p;
    p.first=readint();
    while (p.first != marca){
        p.second=readint();
        l.insert(it,p);
        p.first=readint();
    }
}


void escriure_llista(list<par>& l){
    if (not l.empty()){
        list<par>::iterator it=l.begin();
        while (it != l.end()){
            cout << (*it).first << " "<<(*it).second<< endl;
            it++;
        }
    }
}
