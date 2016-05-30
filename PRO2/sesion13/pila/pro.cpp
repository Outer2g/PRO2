#include "Pila.hpp"
#include "PilaIOint.hpp"

int main(){
    Pila<int> s;
    llegir_pila_int(s,-1);
    escriure_pila_int(s);
    Pila<int> s2(s);
    escriure_pila_int(s2);


}
