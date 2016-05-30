#include "Organisme.hpp"


Organisme::Organisme(int x){
    Arbre<celula> org;
    prop.ID=x;
    prop.idmax=0;
    prop.tam=0;
}


void Organisme::estiron(){
    estiron_r(org);
}
void Organisme::estiron_r(Arbre<celula>& a){
    Arbre<celula> a1;
    Arbre<celula> a2;
    celula c=a.arrel();
    a.fills(a1,a2);
    if (not a1.es_buit()) estiron_r(a1);
    if (not a2.es_buit()) estiron_r(a2);
    if (a1.es_buit() and a2.es_buit()){
        celula p=c;
        ++p.id;
        a1.plantar(p,a,a);
        ++prop.tam;
        ++p.id;
        a2.plantar(p,a,a);
        ++prop.tam;
        prop.idmax+=2;
    }
    a.plantar(c,a1,a2);
}
void Organisme::leer_organismo(){
    llegir(org,0);
}
void Organisme::llegir(Arbre<celula>& a,int marca){
    Arbre<celula> a1;
    Arbre<celula> a2;
    celula x;
    x.id=readint();
    if (x.id != marca) {
        x.act=readbool();
        if (x.id>prop.idmax)prop.idmax=x.id;
        ++prop.tam;
        llegir(a1, marca);
        llegir(a2, marca);
        a.plantar(x,a1,a2);
    }
}
void Organisme::escriure_organismo(){
    cout <<prop.ID<< ": ";
    escriure(org);
    cout << endl;
}
void Organisme::escriure(Arbre<celula>& a){
    if (not a.es_buit()) {
      Arbre<celula> a1;
      Arbre<celula> a2;
      celula x = a.arrel();
      a.fills(a1,a2);
      escriure(a1);
      cout << " " << x.id;
      escriure(a2);
      a.plantar(x,a1,a2);
    }
  }
bool Organisme::recorte(){
    bool b=false;
    recorta(org,b);
    recortado=true;
    if (org.es_buit()) return true;
    else{
        prop.idmax=0;
        find_max(org);
        return false;
    }
}
void Organisme::find_max(Arbre<celula>& a){
    Arbre<celula> a1,a2;
    celula c=a.arrel();
    a.fills(a1,a2);
    if (a1.es_buit() and not a2.es_buit()){
        find_max(a2);
    }
    else if (a2.es_buit() and not a1.es_buit()){
        find_max(a1);
    }
    if (c.id>prop.idmax) prop.idmax=c.id;
    a.plantar(c,a1,a2);
}
void Organisme::recorta(Arbre<celula>& a,bool& b){
    Arbre<celula> a1;
    Arbre<celula>a2;
    celula c=a.arrel();
    a.fills(a1,a2);
    bool p=false;
    if (not a1.es_buit()){
        p=true;
        recorta(a1,b);
    }
    if (not a2.es_buit()){
        p=true;
        recorta(a2,b);
    }
    if (p){
        a.plantar(c,a1,a2);
    }
    else{
        --prop.tam;
        if(c.id==prop.idmax) b=true;
    }
}

bool Organisme::muerto(){
    return (org.es_buit());
}
bool Organisme::estirable(){
    return not recortado;
}
Organisme Organisme::reproduccion_org(Organisme &o,int x,bool& b){
    Organisme ret(x);
    if (o.prop.tam>=prop.tam) b=posi(o.prop.tam,prop.tam);
    else b=posi(prop.tam,o.prop.tam);
    if (b){
    int inter=1;
    ret.org=repro_i(org,o.org,ret.prop,inter);
    cout << prop.tam << " " << o.prop.tam << " "<< (prop.tam+o.prop.tam)/4 << " " << inter << endl;
    if (((prop.tam+o.prop.tam)/4)<=inter)b=true;
    else b=false;
    }
    return ret;

}
bool Organisme::posi(int i,int j){
    if (i<3*j) return true;
    else return false;
}
Arbre<Organisme::celula> Organisme::repro_i(Arbre<celula>& a1,Arbre<celula>&a2,caract& cara,int& inter){
    //Bases
    Arbre<celula> ret,p,p2,a11,a12,a21,a22;
    celula c1,c2;
    c1=a1.arrel();
    c2=a2.arrel();
    a1.fills(a11,a12);
    a2.fills(a21,a22);
    if (not a11.es_buit() and not a21.es_buit()){
        ++inter;
        p=repro_i(a11,a21,cara,inter);
    }
    if (not a12.es_buit() and not a22.es_buit()){
        ++inter;
        p2=repro_i(a12,a22,cara,inter);
    }
    if (a21.es_buit() and not a11.es_buit())p=repro(a11,cara,true,prop.idmax);
    if (a22.es_buit() and not a12.es_buit())p2=repro(a12,cara,true,prop.idmax);
    if (a11.es_buit() and not a21.es_buit())p=repro(a21,cara,false,prop.idmax);
    if (a12.es_buit() and not a22.es_buit())p2=repro(a22,cara,false,prop.idmax);
    if (c1.act or c2.act){
        celula c=c1;
        c.act=true;
        ret.plantar(c,p,p2);
    }
    else ret.plantar(c1,p,p2);
    a1.plantar(c1,a11,a12);
    a2.plantar(c2,a21,a22);
    ++cara.tam;
    return ret;
}
Arbre<Organisme::celula> Organisme::repro(Arbre<celula>&a,caract&cara,bool b,int idm){
    Arbre<celula> ret;
    if (not a.es_buit()){
        Arbre<celula> a1,a2,p,p2;
        celula c;
        c=a.arrel();
        a.fills(a1,a2);
        if (c.act){
            p=repro(a1,cara,b,idm);
            p2=repro(a2,cara,b,idm);
            ++cara.tam;
            if(not b){
                ++idm;
                c.id= idm;
                cara.idmax=idm;
            }
            ret.plantar(c,p,p2);
        }
        else{
            if (not b){
                ++idm;
                c.id=idm;
            }
            p=repro(a1,cara,b,idm);
            p2=repro(a2,cara,b,idm);
            if (not p.es_buit() or not p2.es_buit()){
                ret.plantar(c,p,p2);
            }
        }
        a.plantar(c,a1,a2);
}
    if (not ret.es_buit()) ++cara.tam;
    return ret;
}
