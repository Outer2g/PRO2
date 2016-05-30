/** @file ListaPalabras.hpp
    @brief Especificación de la clase ListaPalabras
*/

#ifndef LISTAPALABRAS_HPP
#define LISTAPALABRAS_HPP

#include "utils.PRO2"
#include "Palabra.hpp"
#include <vector>

/*
* Clase ListaPalabras
*/

/** @class  ListaPalabras

    @brief Representa una colección de palabras distintas, cada una con un
    natural asociado.

    El natural representa el número de veces que la palabra se ha añadido a la
    lista, lo consideramos la <em>frecuencia</em> de dicha palabra
*/
class ListaPalabras
{

private:
    struct palfrec{
        Palabra par;
        int freq;
    };
    static const int MAXNUMPAL=20;
    vector<palfrec> paraules;
    int nparaules;

public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista.

      \pre cierto
      \post El resultado es una lista vacía
  */ 
  ListaPalabras ();

  /* Modificadoras */

  /** @brief Añade una palabra a la lista

      \pre La longitud del parámetro implícito es menor que la longitud
      máxima o <em>p</em> ya está en él

      \post Si <em>p</em> está en el parámetro implícito, su frecuencia queda
      incrementada en una unidad, si no, aparece en él con frecuencia 1
  */
  void anadir_palabra (const Palabra & p);


  /* Consultoras */
  /** @brief Consultora de la longitud máxima

      \pre cierto
      \post El resultado es la longitud máxima de una lista permitida por la
      implementación
  */ 
  static int longitud_maxima ();

  /** @brief Consultora de la longitud
      \pre cierto
      \post El resultado es la longitud del parámetro implícito
  */
  int longitud () const;


  /** @brief Consultora de la frecuencia de la palabra más frecuente
      \pre cierto
      \post El resultado es la frecuencia de la palabra más frecuente del 
      parámetro implícito
  */
  int max_frec () const;

  /* Lectura y escritura */
  /** @brief Operación de escritura
      \pre cierto
      \post El parámetro implícito se ha escrito en el canal estandar de salida
  */
  void escribir_lista () const;

};

#endif
