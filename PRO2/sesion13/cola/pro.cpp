
#include "Cua.hpp"
#include "CuaIOint.hpp"




int main(){
    Cua<int> c;
    Cua<int> p;
    llegir_cua_int(c,-1);
    llegir_cua_int(p,-1);
    c.concat(p);
    escriure_cua_int(c);
    escriure_cua_int(p);
}
