#include "Utils.PRO2"
#include "parint.hpp"
#include <stack>

void leelo(stack<parint>& s){
    int prim,seg;
    prim=readint();
    seg=readint();
    parint p;
    while (prim != -1){
        p.first=prim;
        p.second=seg;
        s.push(p);
        prim=readint();
        seg=readint();
    }
}

void escribir(stack<parint>& s){
    if (not s.empty()) {
        parint x;
        x=s.top();
        s.pop();
        cout << x.first << ","<< x.second << endl;
        escribir(s);
        s.push(x);
    }
}
