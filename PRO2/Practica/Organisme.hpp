/** @file Organisme.hpp
    @brief Especificación de la clase Organisme
*/

#include "utils.PRO2"
#include "Arbre.hpp"


/** @class Organisme
    @brief Contiene celulas ordenadas


    */

class Organisme{
private:
    struct celula{
        int id;
        bool act;
    };
    struct caract{
        int ID;
        int idmax;
        int tam;
    };
    caract prop;
    Arbre <celula> org;
    bool recortado;
    bool compatible(Organisme& o);
    void estiron_r(Arbre<celula>& a);
    void llegir(Arbre<celula>& a,int marca);
    void escriure(Arbre<celula>& a);
    void find_max(Arbre<celula>& a);
    void recorta(Arbre<celula>& a,bool& b);
    Arbre<celula> repro_i(Arbre<celula>& a1,Arbre<celula>& a2,caract& cara,int& inter);
    Arbre<celula> repro(Arbre<celula>&a,caract&cara,bool b,int idm);
public:
    //Constructoras
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un organismo.
        \pre cierto
        \post El resultado es un organismo con ID=x muerto
    */
    Organisme(int x);
    //Destructoras
    //Modificadoras


    /** @brief realiza la reproduccion entre el parámetro implícito y otro organismo
        \pre el organismo del parámetro implícito y o són compatibles, Cjt_organismes.size()<M
        \post Crea un organismo con id=x formado por la intersección de ambos más las celulas activas, actualiza numero organismos
        si b=true, el hijo es valido, si no no lo és
    */
    Organisme reproduccion_org(Organisme&o,int x,bool& b);

    /** @brief realiza un estiron en el parámetro implícito
        \pre el parámetro implícito es estirable
        \post El parámetro implícito pasa a ser el mismo, más la fisión de sus celulas sin hijos.
    */
    void estiron();
    /** @brief realiza un recorte
        \pre El parámetro implícito no está muerto
        \post El parámetro implícito pasa a ser el mismo, menos las celulas sin hijos, devuelve true si el organismo ha muerto, false si sigue vivo
    */
    bool recorte();
    //Consultoras
    /** @brief Consultora de estado
        \pre cierto
        \post El resultado es cierto si el organismo ha perdido la celula madre, falso si no la ha perdido
    */
    bool muerto();
    /** @brief Consultora de flexibilidad
        \pre el parámetro implícito no está muerto
        \post El resultado es cierto si hay celulas fisionables, falso si no
    */
    bool estirable();
    //Lectura y escritura
    /** @brief Operación de lectura

        \pre el organismo tiene almenos una celula
        \post el parámetro implícito pasa a tener el organismo descrito en el canal de entrada
    */
    void leer_organismo();
    /** @brief Operación de escritura

        \pre cierto
        \post Escribe el contenido del parámetro implícito por el canal estándar de salida
    */
    void escriure_organismo();
};
