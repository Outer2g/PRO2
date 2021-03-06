/** @file Lavadora.hpp
    @brief Especificación de la clase Lavadora 
*/

#ifndef _LAVADORA_HPP_
#define _LAVADORA_HPP_

#include "Prenda.hpp"
#include <list>

/** @class Lavadora
    @brief Representa una lavadora. 

    Dispone de dos estados (inicializada / no inicializada); si está inicializada tiene un peso máximo y un color y admite depositar prendas de dicho color hasta alcanzar dicho peso máximo; si no está inicializada solo se puede inicializar
*/
class Lavadora
{
public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lavadora.
      \pre cierto
      \post El resultado es una lavadora no inicializada
  */  
  Lavadora();
 
  //Modificadoras

  /** @brief Inicializa la lavadora
      \pre El parámetro implícito no está inicializado, pmax>0
      \post El parámetro implícito pasa a estar inicializado con peso máximo "pmax" y color "col" 
  */
  void inicializar_lavadora(int pmax, bool col);

  /** @brief Añade una prenda a la lavadora
      \pre El parámetro implícito (L) está inicializado, color de p = color de L, peso de L + peso de p <= peso máximo de L;
      \post El parámetro implícito contiene su carga original más p 
  */
  void anadir_prenda (const Prenda &p);

  /** @brief Realiza un lavado

      Representa que se realiza el lavado, se retiran la prendas que contiene la lavadora y ésta queda en estado de volver a usarse
      \pre El parámetro implícito está inicializado,
      \post El parámetro implícito no está inicializado 
  */
  void lavado ();

  // Consultoras

  /** @brief Consultora del estado de la lavadora

      \pre cierto
      \post El resultado indica si el parámetro implícito está inicializado 
  */
  bool esta_inicializada() const;

  /** @brief Consultora del color de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es el color del parámetro implícito 
  */
  bool consultar_color_lavadora() const;

  /** @brief Consultora del peso actual de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es la suma de los pesos de las prendas del parámetro implícito 
  */
  int consultar_peso_lavadora() const;

  /** @brief Consultora del peso máximo de la lavadora

      \pre El parámetro implícito está inicializado
      \post El resultado es el peso máximo del parámetro implícito 
  */
  int consultar_peso_maximo() const;

  // Escritura de la lavadora

  /** @brief Operación de escritura

      \pre El parámetro implícito está inicializado
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida 
  */
  void escribir_lavadora() const;

private:
  list<Prenda> prendas;
  bool col;
  int pes;
  bool ini;
  int pesmax;
};
#endif
