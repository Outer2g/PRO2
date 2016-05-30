/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.
*/

/** @file main.cpp
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hpp de la documentación de las clases ocurre lo mismo.
#include "Prenda.hpp"
#include "Lavadora.hpp"
#include "Cubeta.hpp"


/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    Lavadora Lav;
    Cubeta Cubet;
    int x=readint();
    while (x != -8){
        if (x == -1){
            int peso=readint();
            char color=readchar();
            cout << endl;
            bool p=true;
            if (color=='B') p=false;
            Lav.inicializar_lavadora(peso,p);
        }
        if (x == -2){
            int peso=readint();
            char color=readchar();
            cout << endl;
            bool p=true;
            if (color=='B') p=false;
            Prenda Prend(peso,p);
            Lav.anadir_prenda(Prend);
        }
        if (x == -3){
            int peso=readint();
            char color=readchar();
            cout << endl;
            bool p=true;
            if (color=='B') p=false;
            Prenda Prend(peso,p);
            Cubet.anadir_prenda(Prend);
        }
        if (x == -4){
            Cubet.completar_lavadora(Lav);
        }
        if (x == -5){
            Lav.lavado();
        }
        if (x == -6){
            Cubet.escribir_cubeta();
        }
        if (x==-7){
            Lav.escribir_lavadora();
        }
        x=readint();
    }
    cout << "fin" << endl;

}
