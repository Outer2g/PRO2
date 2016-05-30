/**
 * @mainpage Practica PRO2

 Programa modular que que ofrece un menú de experimentos de laboratorio sobre unos organismos. Se introducen
las clases <em> Organisme</em>, <em> Cjt_organismes</em> y <em> Ranking</em>
*/

/** @file Programa.cpp
    @brief Programa principal
*/


#include "utils.PRO2"
#include "Cjt_organismes.hpp"

/** @brief programa main
 */
int main(){
    int n=readint();
    int M=readint();
    Cjt_organismes orgs;
    orgs.leer_cjt(n,M);
    int x=readint();
    while (x != -6){
        bool finish;

        if (x == -1){
            /** @brief Si x=1, aplica una ronda de estiron a una secuencia de identificadores
             */
            orgs.estiron_id();
        }

        if (x == -2){
            /** @brief Si x=2, aplica una ronda de recorte a una secuencia de identificadores, si despues de la ronda mueren todos los organismos, el booleano finish pasa a ser true
             */
            if (orgs.recorte_id()){
                finish=true;
            }
        }

        if (x == -3){
            /** @brief Si x=3, aplica una ronda de reproducción a todos los organismos, si llega a la población máxima
             */
            if(orgs.round())finish=true;
        }
        if (x == -4){
            /** @brief Si x=4, escribe el ranking de reproducción de los organismos
             */
            orgs.consult_ranking_rep();
        }
        if (x == -5){
            /** @brief Si x=5, consulta el subconjunto de organismos con id= a la secuencia de entrada
             */
            orgs.consult_id();
        }
        if(finish) x=-6;
        else x=readint();
    }
    if (not finish) cout << "Se ha finalizado manualmente"<< endl;
}
