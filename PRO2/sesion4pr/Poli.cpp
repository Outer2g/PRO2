#include "Poli.hpp"

/* Constantes */

const char *ER1 = "Polinomio demasiado grande";
const char *ER2 = "Exponente negativo";
const char *ER3 = "Exponente demasiado grande";

/* Hemos dejado algunos this no necesarios como recordatorio */ 
/* Tambien se lanzan algunas excepciones a modo de ejemplo */


/* Constructoras */

Poli::Poli()
{
  coefs = vector <int>(MAX_GRADO + 1);
  int j = 0;
  while (j <= MAX_GRADO) {
    coefs[j] = 0;
    ++j;
  }
  grau = 0;
}

// leer como constructora
Poli::Poli(int marca)

  /* Lee los coeficientes de un polinomio de menor a mayor indice,
     hasta llegar a la marca.
     Si se leen demasiados coeficientes se lanza una excepcion */
{
  coefs = vector <int>(MAX_GRADO + 1);
  grau=0;
  int x = readint();
  int i = 0;
  while (x != marca) {
    if (i > MAX_GRADO)
      throw PRO2Excepcio(ER1);
    modif_coef(x, i);
    x = readint();
    ++i;
  }
  while (i <= MAX_GRADO) {
    coefs[i] = 0;
    ++i;
  }
}

Poli::Poli(int c, int i)
{
  // ejemplos de definicion de excepciones: control del parametro i
  if (i < 0)
    throw PRO2Excepcio( ER2);
  if (i > MAX_GRADO)
    throw PRO2Excepcio( ER3);

    // si esta todo correcto, se inicializan los coeficientes;
    // todos a 0, excepto el i-esimo

  coefs = vector <int>(MAX_GRADO + 1);
  int j = 0;
  while (j <= MAX_GRADO) {
    coefs[j] = 0;
    ++j;
  }
  coefs[i] = c;
  if (c!=0) grau = i;
  else grau = 0;
}

/* Destructora por defecto */

Poli::~Poli()
{
}

void Poli::modif_coef(int c, int i)
{
  // control del parametro i

  if (i < 0)
    throw PRO2Excepcio(ER2);
  if (i > MAX_GRADO)
    throw PRO2Excepcio(ER3);

    // si esta todo correcto, se modifica el coeficiente i-esimo;

  coefs[i] = c;

  // hay que controlar si el grado sube

  if (grau < i && c != 0)
    grau = i;

    // o baja

  if (grau == i && c == 0)
    while (grau > 0 && coefs[grau] == 0)
      grau--;
}

void Poli::suma_poli(Poli & p)
{
  // si el grado de p es mayor que el del parametro implicito,
  // hay que cambiar este

  if (p.grau > this->grau) {
    this->grau = p.grau;
  }
  // sumas de coeficientes; notad que loe coeficientes 
  // superiores al grado no cambian

  int i = 0;
  while (i <= this->grau) {
    this->coefs[i] += p.coefs[i];
    i++;
  }

  // si se han anulado algunos de los coefs de mayor grado
  // el grado decrece

  while (this->grau > 0 && this->coefs[this->grau] == 0)
    this->grau--;
}

static int Poli::grado_maximo()
{
  return MAX_GRADO;
}

int Poli::grado() const
{
  return grau;
}

int Poli::coef(int i) const
{
  if (i < 0)
    throw PRO2Excepcio(ER2);
  if (i > grau)
    throw PRO2Excepcio(ER3);
  return coefs[i];
}


// leer como modificadora

void Poli::leer_poli(int marca)
  /* Lee los coeficientes de un polinomio de menor a mayor indice,
     hasta llegar a la marca.
     Si se leen demasiados coeficientes se lanza una excepcion */
{
  int x = readint();
  int i = 0;
  while (x != marca) {
    if (i > grado_maximo())
      throw PRO2Excepcio(ER1);
    modif_coef(x, i);
    x = readint();
    i++;
  }
  while (i <= MAX_GRADO) {
    coefs[i] = 0;
    ++i;
  }
}

// escritura

void Poli::escribir_poli() const
  /* Escribe los coeficientes de un polinomio de menor a mayor indice */
{
  int i = 0;
  while (i <= grado()) {
    cout << coef(i) << " ";
    i++;
  }
  cout << endl;
}
