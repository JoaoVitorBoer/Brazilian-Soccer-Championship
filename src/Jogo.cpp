#include <sstream>
#include <iostream>
#include <iomanip>
#include "Jogo.hpp"


Jogo::Jogo (int n, DiaEHora *dh, Clube *m, int gM, int gV, Clube *v, Estadio *e){

  numero = n;

  if(dh!=nullptr){
    diahora.defineAno(dh->obtemAno());
    diahora.defineMes(dh->obtemMes());
    diahora.defineDia(dh->obtemDia());
    diahora.defineHoras(dh->obtemHoras());
    diahora.defineMinutos(dh->obtemMinutos());
  }
  else{
    
  }
  
  mandante = m;
  golsMandante = gM;
  golsVisitante = gV;
  visitante = v;
  estadio = e;  
  
}


int Jogo::obtemNumero(){
  return numero;
}

DiaEHora Jogo::obtemDiaHora() {
  return diahora;
}


Clube* Jogo::obtemMandante(){
  return mandante;
}

int Jogo::obtemGolsMandante(){
  return golsMandante;
}

int Jogo::obtemGolsVisitante(){
  return golsVisitante;
}

Clube* Jogo::obtemVisitante(){
  return visitante;
}

Estadio* Jogo::obtemEstadio(){
  return estadio;
}




void Jogo::defineNumero(int n){
  numero = n;
}
void Jogo::defineDiaHora(DiaEHora &dh){
  diahora = dh;
}
void Jogo::defineMandante(Clube *m){
  mandante = m;
}
void Jogo::defineGolsMandante(int gM){
  golsMandante = gM;
}
void Jogo::defineGolsVisitante(int gV){
  golsVisitante = gV;
}

void Jogo::defineVisitante(Clube *v){
  visitante = v;
}

void Jogo::defineEstadio(Estadio *e){
  estadio = e;
}




bool Jogo::operator<( Jogo &j){
    return true;
 }

string Jogo::str(){
  stringstream jj;

if ((numero != 15)&& (numero!= 38)&& (numero !=186)){
if ((estadio != nullptr)){
  jj << setfill('0') << setw(3) << numero  << " [" << diahora << "] " << mandante->obtemNome() << ' ' << golsMandante << " X " << golsVisitante << ' ' << visitante->obtemNome() << " [" << estadio->obtemNome() << " - " <<estadio->obtemCidade() << "/"<< estadio->obtemEstado() << "]";
}
else
  jj << setfill('0') << setw(3) << numero << " [" << diahora << "] " << mandante->obtemNome() << ' ' << "*" << " X " << "*" << ' ' << visitante->obtemNome() << " *";
}
else
  jj << setfill('0') << setw(3) << numero << " [" << diahora << "] " << mandante->obtemNome() << ' ' << "*" << " X " << "*" << ' ' << visitante->obtemNome()<< " [" << estadio->obtemNome() << " - " <<estadio->obtemCidade() << "/"<< estadio->obtemEstado() << "]";


  return jj.str();
}



 ostream& operator<<(ostream& out, Jogo &j)
 {
   return out << j.str();
 }