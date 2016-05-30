#ifndef ESTUDIANT_HPP
#define ESTUDIANT_HPP

#include "utils.PRO2"

class Estudiant {

private:    
  int DNI;
  double nota;
  static const int MAX_NOTA = 10;

public:


  /* Constructores */
  Estudiant();
  Estudiant(int dni);
  Estudiant(const Estudiant& est);

  /* Destructora por defecte */
  ~Estudiant();

  /* Modificadores */
  void afegir_nota(double nota);
  void modificar_nota(double nota);

 /* Consultores */
  static bool comp(const Estudiant& est1, const Estudiant& est2);
  bool te_nota() const;
  double consultar_nota() const;
  int consultar_DNI() const;

  /* Entrada / Sortida */
  void llegir_estudiant();
  void escriure_estudiant() const;
};
#endif
