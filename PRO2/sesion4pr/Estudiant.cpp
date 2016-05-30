#include "Estudiant.hpp"

/* Constantes */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  DNI=0;
  nota=-1;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  DNI = dni;
  nota=-1;
}

Estudiant::Estudiant(const Estudiant& est){
    DNI=est.consultar_DNI();
    nota= est.nota;
}

Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double nota)
{
    if (te_nota())
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota;
}
bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI()<e2.consultar_DNI());
}

void Estudiant::modificar_nota(double nota)
{
  if (this-> nota==-1)
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
    if (nota==-1) return false;
    else return true;
}

double Estudiant::consultar_nota() const
{
    if (nota ==-1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return DNI;
}

void Estudiant::llegir_estudiant()
{
  DNI= readint();
  if (DNI<0) throw PRO2Excepcio(ER4);
  double x = readdouble();
  if (x >= 0 and x <= MAX_NOTA)    nota = x;
  else nota=-1;
}

void Estudiant::escriure_estudiant() const
{
  if (nota!=-1)
    cout << DNI << " " << nota << endl;
  else
    cout << DNI <<" NP" << endl;
}
