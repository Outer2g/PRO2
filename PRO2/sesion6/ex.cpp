#include "PilaIOparint.hpp"


void funcion(stack <parint> & s,int y){
    if (not s.empty()){
        parint x;
        x=s.top();
        s.pop();
        funcion(s,y);
        x.second = x.second + y;
        s.push(x);
    }
}
int main(){
    stack <parint> s;
    int x=readint();
    leelo(s);
    funcion(s,x);
    escribir(s);
}
