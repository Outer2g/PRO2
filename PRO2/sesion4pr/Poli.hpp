#ifndef POLI_HPP
#define POLI_HPP
#include "utils.PRO2"
#include <vector>

class Poli {

private:

  vector<int> coefs;
  int grau; // no se puede llamar igual que la consultora
  static const int MAX_GRADO = 10;
  /* Se podria incluir como campo normal, para poder manejar distintos
     maximos segun la situacion */

public:

  /* Constructoras */
  Poli();
  Poli(int marca);
  Poli(int c, int i);

  /* Destructora por defecto */
  ~Poli();

  /* Modificadoras de los campos */
  void modif_coef(int c, int i);
  void suma_poli(Poli & p);

  /* Consultoras de los campos */
  int grado_maximo();
  int grado() const;
  int coef(int i) const;

  /* Entrada / Salida */
  void leer_poli(int marca);
  void escribir_poli() const;
};
#endif
