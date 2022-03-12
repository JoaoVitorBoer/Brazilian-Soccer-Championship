// Jogo.hpp (Roland Teodorowitsch; 21 set. 2021)
#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <string>
#include "Clube.hpp"
#include "DiaEHora.hpp"
#include "Estadio.hpp"

using namespace std;

class Jogo {
 private:
 int numero;
 DiaEHora diahora;
 Clube *mandante;
 int golsMandante;
 int golsVisitante;
 Clube *visitante;
 Estadio *estadio;
 
 public:
 
 Jogo(int n, DiaEHora *dh, Clube *m, int gM, int gV, Clube *v, Estadio *e);
 ~Jogo();


 int obtemNumero();
 DiaEHora obtemDiaHora();
 Clube *obtemMandante();
 int obtemGolsMandante();
 int obtemGolsVisitante();
 Clube *obtemVisitante();
 Estadio *obtemEstadio();
 void defineNumero(int n);
 void defineDiaHora(DiaEHora &dh);
 void defineMandante(Clube *m);
 void defineGolsMandante(int gM);
 void defineGolsVisitante(int gV);
 void defineVisitante(Clube *v);
 void defineEstadio(Estadio *e);
 string str();
 bool operator<(Jogo &j);

 friend ostream& operator<<(ostream& out, Jogo &j);
 };
#endif
