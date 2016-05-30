/**
 * @mainpage Ejemplo de diseño modular:  Factor Psi.
 
En este ejemplo se construye un programa modular que, dado un texto marcado,
obtiene la frecuencia de la palabra más frecuente del mismo. Se introducen 
las clases <em> Palabra</em> y <em> ListaPalabras</em>.
*/

/** @file pro2_s52.cpp
    @brief Programa principal para el ejercicio <em>Factor Psi</em>.
*/

#include "Palabra.hpp" // para que el diagrama modular quede bien
#include "ListaPalabras.hpp"


/** @brief Programa principal para el ejercicio <em>Factor Psi</em>.
*/
int main ()
{
    ListaPalabras LP;
    Palabra word;
    word.leer_palabra('.');
    while(word.long_pal() != 0){
        LP.anadir_palabra(word);
        word.leer_palabra('.');
    }
    int freq= LP.max_frec();
    cout << freq << endl;
}
