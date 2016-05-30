/** @file Cubeta.hpp
    @brief Especificación de la clase Cubeta
*/

#ifndef _CUBETA_HPP_
#define _CUBETA_HPP_

#include "Prenda.hpp" // redundante, pero necesario para el diagrama modular
#include "Lavadora.hpp"
#include <stack>


/** @class Cubeta
    @brief Representa una cubeta de ropa. 

    Puede contener prendas blancas y de color. Puede usarse para intentar llenar una lavadora; en ese caso, las prendas se sacan de la cubeta en orden inverso al de entrada
    */
class Cubeta
{
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una cubeta.
      \pre cierto
      \post El resultado es una cubeta sin prendas de ningún tipo
  */  
  Cubeta();
 
  /** @brief Creadora copiadora. 

      Permite declarar una cubeta nueva como copia de otra ya existente.
      \pre cierto
      \post El resultado es una cubeta igual que c
  */  
  Cubeta(const Cubeta& c);


  //Modificadoras

  /** @brief Añade una prenda a la cubeta
      \pre cierto
      \post El parámetro implícito pasa a contener sus prendas originales más p 
  */
  void anadir_prenda(const Prenda &p);

  /** @brief Completa una lavadora con las prendas de la cubeta
      \pre l está inicializada
      \post Se han eliminado del parámetro implícito y se han añadido a l las prendas del parámetro implícito del color adecuado que más se acercan entre todas al peso máximo de l sin pasarse, elegiéndose primero las que se introdujeron en último lugar
  */
  void completar_lavadora(Lavadora &l);

  // Escritura de una cubeta

  /** @brief Operación de escritura

      \pre cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida 
  */
  void escribir_cubeta() const;

  // de momento no documentamos los elementos privados 
  // lo haremos a partir de la sesion 10 (habrá que cambiar tambien el Doxyfile)
private:
  stack<Prenda> ropacolor;
  stack<Prenda> ropablanca;
  static void completar_lavadora_pila_rec(stack<Prenda> &p ,Lavadora &l);
  static void completar_lavadora_pila_it(stack<Prenda> &p,Lavadora &l);
  static void escribir_pila_prenda(const stack<Prenda>& p);
};
#endif
