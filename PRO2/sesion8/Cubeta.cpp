 
#include "Cubeta.hpp"




Cubeta::Cubeta(){}

Cubeta::Cubeta(const Cubeta& c){
    ropacolor=c.ropacolor;
    ropablanca=c.ropablanca;
}

void Cubeta::anadir_prenda(const Prenda &p){
    if (p.consul_color()){
        ropacolor.push(p);
    }
    else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora &l){
    if (l.consultar_color_lavadora()){
        completar_lavadora_pila_rec(ropacolor,l);
    }
    else completar_lavadora_pila_rec(ropablanca,l);
}

void Cubeta::escribir_cubeta() const{
    cout << "ropa color: ";
    escribir_pila_prenda(ropacolor);
    cout << endl << "ropa blanca: ";
    escribir_pila_prenda(ropablanca);
    cout << endl;
}

void Cubeta::completar_lavadora_pila_rec(stack<Prenda> &p ,Lavadora &l){
    if (not p.empty()){
        Prenda pr = p.top();
        if (pr.consul_peso() + l.consultar_peso_lavadora() <= l.consultar_peso_maximo()){
            l.anadir_prenda(pr);
            p.pop();
            completar_lavadora_pila_rec(p,l);
        }
    }
}
void Cubeta::escribir_pila_prenda(const stack<Prenda>& p){
    stack<Prenda> p1(p);
    if (not p1.empty()){
        Prenda x;
        x=p1.top();
        cout << x.consul_peso() << "," << x.consul_color() << endl;
        p1.pop();
        escribir_pila_prenda(p1);
    }

}
