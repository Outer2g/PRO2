#include "Organisme.hpp"
#include "Ranking.hpp"


int main(){
    Organisme o(1);
    Organisme o2(2);
    Organisme o3(3);
    Ranking r(5);
    o.leer_organismo();
    o2.leer_organismo();
    r.nuevo_organismo(1);
    r.nuevo_organismo(2);
    r.nuevo_organismo(3);
    bool b;
    o3 = o.reproduccion_org(o2,3,b);
    if (b){
    o3.escriure_organismo();
    r.nuevo_hijo(1,2,3);
    }
    else cout << "No compatible"<< endl;
    r.escribir_rank();

    cout << endl;
}
