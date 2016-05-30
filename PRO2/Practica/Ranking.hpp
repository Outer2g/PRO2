/** @file Ranking.hpp
    @brief Especificación de la clase Ranking
*/

#include "utils.PRO2"
#include <list>
#include<vector>

/** @class Ranking
    @brief contiene el ranking del conjunto de organismos

    */
class Ranking{
private:
    struct need{
        int p;
        int s;
    };
    int n;
    vector<need> ordenados;
    vector<list<need> > emparejamientos;
    /** @brief realiza la actualización del ranking
        \pre el ranking no está vacío
        \post el parámetro implícito está ordenado decrecientemente por numero de hijos producidos, en caso de empate por orden decreciente de identificadores de organismo

    */
    void actualitzar(int x);
public:
    //Constructoras
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar una lavadora.
        \pre cierto
        \post El resultado es un vector con M posiciones vacío
    */
    Ranking(int M);
    //Modificadoras
    /** @brief añade un nuevo hijo a un organismo, también se especifica quien ha sido la pareja y quien ha sido el hijo
        \pre el organismo existe.
        \post se ha añadido al organismo el hijo y la pareja. También se ha incrementado el número de hijos de dicho organismo
    */
    void nuevo_hijo(int x,int y,int z);

    /** @brief añade un nuevo organismo al ranking
        \pre cert
        \post se ha añadido un nuevo organismo en la posición n+1, i se ha actualizado n
    */
    void nuevo_organismo(int x);

    //Consultoras
    //Escritura
    /** @brief Operación de escritura

        \pre cierto
        \post Se ha escrito el ranking actual en el canal de salida estandar
    */
    void escribir_rank();
};
