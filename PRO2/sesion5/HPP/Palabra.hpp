/** @file Palabra.hpp
    @brief Especificación de la clase Palabra 
*/

#ifndef PALABRA_HPP
#define PALABRA_HPP

#include "utils.PRO2"
#include <vector>

/*
 * Clase Palabra
 */

/** @class  Palabra
    @brief Representa una lista indexada de caracteres alfanuméricos.

Los caracteres válidos son 'a'..'z', 'A'..'Z' y '0'..'9'. El resto son
considerados separadores de cara a la lectura  por el canal standard. 

Las operaciones de lectura requieren un parámetro que se usará para distinguir
un separador especial, que sirva por ejemplo para marcar el final de un
texto. Dicho separador especial puede ser cualquier caracter ASCII (0-127)
"visible" distinto de 'a'..'z', 'A'..'Z' y '0'..'9', como '$', '.' o '+' (pero
no el blanco, el salto de línea o el tabulador, por no ser visibles, o "ç",
"ñ", etc., por no ser ASCII (0-127).

La longitud máxima de una palabra está acotada por la implementación
*/
class Palabra
{
private:
  static const int MAXLONG = 20;
  vector<char> letras; 
  int longitud;

public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una palabra.
      \pre cierto
      \post El resultado es una palabra sin caracteres y longitud 0 
  */     
  Palabra ();

  /* Modificadoras de los campos */

  /** @brief Añade un carácter nuevo al final de una palabra

      \pre <em>c</em> es un carácter válido y la longitud del parámetro
      implícito es menor que la longitud máxima

      \post el parametro implícito queda como el original pero con <em>c</em>
      añadido al final
  */
  void anadir_letra (char c);



  /* Consultoras de los campos */

  /** @brief Consultora de la longitud máxima
      \pre cierto
      \post El resultado es la longitud máxima de una palabra permitida 
      por la implementación 
  */ 
  static int longitud_maxima ();

  /** @brief Consultora de la longitud
      \pre cierto
      \post El resultado es la longitud del parámetro implícito
  */
  int long_pal () const;

  /** @brief Consultora del carácter i-ésimo
      \pre 1<=<em>i</em><=longitud del parámetro implícito
      \post El resultado es el carácter <em>i</em>-ésimo del parámetro implícito
  */
  char consultar_letra (int i) const;

  /** @brief Igualdad de palabras. 
      \pre cierto
      \post El resultado indica si <em>p</em> es igual al parámetro implícito 
  */
  bool iguales (const Palabra & p) const;


  /* Entrada / Salida */
 
  /** @brief Operación de lectura

      \pre En el canal standard de entrada hay uno o más caracteres 'a'..'z',
      'A'..'Z', '0'..'9' o x

      \post El parámetro implícito contiene el primer grupo de caracteres
      válidos leídos del canal standard de entrada, hasta el primer separador
      posterior a éstos; si antes del primer carácter válido aparece "x", se
      obtiene una palabra de longitud cero.
  */
  void leer_palabra (char x);

  /** @brief Operación de escritura

      \pre cierto

      \post Se han escrito los caracteres del parámetro implícito en el canal
      standard de salida. Si está vacío no se escribe nada.
  */
  void escribir_palabra () const;
};

#endif
