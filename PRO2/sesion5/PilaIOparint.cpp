#include "PilaIOparint.hpp"


PilaIOparint::PilaIOparint(){
    first=0;
    second=0;
}

void PilaIOparint::modificar_dos(parint& p){
    first=p.first();
    second=p.second();
}
void PilaIOparint::modificar_first(int fir){
    first=fir;
}
void PilaIOparint::modificar_second(int sec){
    second=sec;
}
parint PilaIOparint::both(){
    parint p;
    p.modificar_dos(this);
}
int PilaIOparint::first(){
    return first;
}
int PilaIOparint::second(){
    return second;
}
void PilaIOparint::leer_par(parint& p){

}
void PilaIOparint::escribir_par(parint& p){

}
