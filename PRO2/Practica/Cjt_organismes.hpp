/** @file Cjt_organismes.hpp
    @brief Especificación de la clase Cjt_organismes.hpp
*/


#include "Organisme.hpp"
#include "utils.PRO2"
#include "Ranking.hpp"

/** @class Cjt_organismes
    @brief conté un conjunt d'organismes

    */

class Cjt_organismes{
private:
    vector<Organisme> orgs;
    typedef vector<vector <bool> > boole;
    int norg;
    int morts;
    Ranking r;
    list <Organisme> nacidos;
    boole parelles;
public:
    //Constructoras
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar una lavadora.
        \pre cierto
        \post El resultado es un vector con M posiciones, con M organismos vacíos
    */
    Cjt_organismes(int M);
    //Destructoras
    ~Cjt_organismes();
    //Modificadoras

    /** @brief realiza el estiron a partir de una secuencia de entrada
        \pre cert
        \post se ha realizado el estiron a los id de la secuencia de entrada (si ha sido posible)
    */
    void estiron_id();
    /** @brief realiza un recorte a partir de una secuencia de entrada
        \pre cert
        \post se ha realizado el recorte a los id de la secuencia de entrada (si ha sido posible) si al acabar han muerto todos los organismos, escribira: "Han muerto todos los organismo. Fin del experimento" y devolverá true, si no devolvera false
    */
    bool recorte_id();
    /** @brief realiza una ronda de reproducción a todos los organismos
        \pre cert
        \post se ha realizado una ronda de reproducción a todos los organismos, actualizado el ranking, y escribre el numero de hijos nacidos
        por el canal de salida estandar. Si numero de organismos llega a M, escribe "Población historica máxima alcanzada. Fin del experimento" en el canal de salida estandar y devuelve true. Si no devuelve false
    */
    bool ronda();
    //Consultoras
    /** @brief Consultora estados de los subconjuntos segun una secuencia de entrada
        \pre cert
        \post escribe la estructura celular de los subconjuntos pedidos en el canal de salida estandar
    */
    void consult_id();
    /** @brief Consultora del estado de los organismos nacidos en la ultima ronda
        \pre cierto
        \post escribe el estado de los organismos nacidos en la ultima ronda
    */
    void consult_round();
    /** @brief Consultora de ranking de reproducción
        \pre cierto
        \post se ha hecho la escritura del ranking mediante la funcion de la clase ranking: escribir_rank_rep()
    */
    void consult_ranking_rep();
    //lectura y escriptura
    /** @brief Operación de lectura

        \pre n<=M
        \post se han almacenado los organismos(tanto en ranking, como en el vector Cjt) leidos por el canal de entrada estandar
    */
    void leer_cjt(int n, int M);

}
