#ifndef ARBRE_HPP
#define ARBRE_HPP

#include "utils.PRO2"

template <class T> class Arbre { 

private:     

  struct node_arbre {
    T info;
    node_arbre* segE;
    node_arbre* segD;
  };

  node_arbre* primer_node;

  // especificació operacions privades

  static node_arbre* copia_node_arbre(node_arbre* m) 
  /* Pre: cert */
  /* Post: el resultat és NULL si m és NULL; 
     en cas contrari, el resultat apunta al node arrel 
     d'una jerarquia de nodes que és una còpia de la 
     jerarquia de nodes que té el node apuntat per m com a arrel */
  {
    node_arbre* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = copia_node_arbre(m->segE);
      n->segD = copia_node_arbre(m->segD);
    }
    return n;
  }

  static void esborra_node_arbre(node_arbre* m) 
  /* Pre: cert */
  /* Post no fa res si m és NULL; en cas contrari, 
     allibera espai de tots els nodes de la 
     jerarquia que té el node apuntat per m com a arrel */
  {    
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }

public:

  // especificació operacions públiques

  Arbre() 
  /* Pre: cert */
  /* Post: el p.i. és un arbre buit */
  {
    primer_node= NULL;
  }

  Arbre(const Arbre& original)
  /* Pre: cert */
  /* Post: el p.i. és una còpia d'original */
  {
    if (this != &original)     
      primer_node = copia_node_arbre(original.primer_node);
  }

  ~Arbre() {
    esborra_node_arbre(primer_node);
  }

  Arbre& operator=(const Arbre& original) {
    if (this != &original) {
      esborra_node_arbre(primer_node);
      primer_node = copia_node_arbre(original.primer_node);
    }
    return *this;
  }

  void a_buit()
  /* Pre: cert */
  /* Post: el p.i. és un arbre buit */
  {
    esborra_node_arbre(primer_node);
    primer_node= NULL;
  }        

  void plantar(const T &x, Arbre &a1, Arbre &a2)
  /* Pre: el p.i. és buit, a1=A1, a2=A2 */
  /* Post: el p.i. té x com a arrel, 
     A1 com a fill esquerre i A2 com a fill dret; 
     a1 i a2 són buits */
  {
    if (this != &a1 and this != &a2) {
      if (primer_node==NULL) {
        node_arbre* aux;
        aux= new node_arbre;
        aux->info= x;
        aux->segE= a1.primer_node;
        if (a1.primer_node == a2.primer_node) aux->segD= copia_node_arbre(a1.primer_node);
        else  aux->segD= a2.primer_node;
        primer_node= aux;
        a1.primer_node= NULL;
        a2.primer_node= NULL;
      }
      else
        throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
    }
    else
      throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els paràmetres");    
  }


  void fills (Arbre &fe, Arbre &fd)
  /* Pre: el p.i. no és buit i li diem A, fe i fd són buits */
  /* Post: fe és el fill esquerre d'A, fd és el fill dret d'A,
     el p.i. és buit */
  {
    if (primer_node!=NULL and fe.primer_node==NULL
        and fd.primer_node==NULL) {
      if (&fe != &fd) {       
        node_arbre* aux;
        aux= primer_node;
        fe.primer_node= aux->segE;
        fd.primer_node= aux->segD;
        primer_node= NULL;
        delete aux;
      }
      else 
        throw PRO2Excepcio 
	  ("Els dos paràmetres de fills no poden coincidir");      
    }
    else if (primer_node==NULL)
      throw PRO2Excepcio ("Un arbre buit no té fills");
    else   
      throw PRO2Excepcio 
        ("Els dos paràmetres de fills han de ser buits a la crida");  
  }

  T arrel() const 
  /* Pre: el p.i. no és buit */
  /* Post: el resultat és l'arrel del p.i. */
  {
    if (primer_node!=NULL)
      return primer_node->info;    
    else
      throw PRO2Excepcio ("Un arbre buit no té arrel");
  }

  bool es_buit() const 
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. és un arbre buit */
  {
    return (primer_node==NULL);
  }

  // Extensión -----------------------------------------------------

  void inc (const T &k) 
  /* Pre: a=A; el tipus T té l'operació suma */ 
  /* Post: a és com A però havent sumat k a tots els seus elements */
  {
    inc_node(primer_node, k);
  }

  static void inc_node (node_arbre* n, T k)
  /* Pre: cert */ 
  /* Post: el node apuntat per n i tots els seus següents tenen al seu camp
     info la suma de k i el seu valor original */
  {
    if (n!=NULL) {
      n->info += k;
      inc_node(n->segE, k);
      inc_node(n->segD, k);
    }
  }

  void subst (T x, const Arbre &as) 
  /* Pre: a=A; el tipus T té l'operació == */
  /* Post: a és com A però havent substituit les fulles que contenien x 
     per l'arbre as */
  {
    subst_node(primer_node, x, as.primer_node);
  }

  static void subst_node (node_arbre* &n, T x, node_arbre* ns) 
  /* Pre: cert */ 
  /* Post: els nodes de la jerarquia de nodes que comença al node apuntat per n
     tals que el seu camp info valia x i no tenien següents han estat substituits 
     per una còpia de la jeraquia de nodes que comença al node apuntat per ns */
  {
    if (n!=NULL) {
      if (n->info == x and n->segE == NULL and n->segD == NULL) 
	n= copia_node_arbre(ns);
      else {
	subst_node(n->segE, x, ns);
	subst_node(n->segD, x, ns);
      }
    }
  }
 
  int tam ()
  /* Pre: cert */
  /* Post: el resultat es el nombre de nodes del p.i. */
  {
    return tam_node(primer_node);
  }

  static int tam_node (node_arbre* n)
  /* Pre: cert */
  /* Post: el resultat es el nombre de nodes descendents d'n, ell mateix inclos */
  {
    int t;
    if (n == NULL) t=0;
    else t=1+ tam_node(n->segE) +tam_node(n->segD);  
    return t;
  }

};

#endif
