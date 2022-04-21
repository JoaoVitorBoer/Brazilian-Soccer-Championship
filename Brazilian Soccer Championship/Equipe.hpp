// Equipe.hpp (Roland Teodorowitsch; 21 set. 2021)

#ifndef _EQUIPE_HPP
#define _EQUIPE_HPP

#include <string>

#include "Clube.hpp"

using namespace std;

class Equipe {
 private:

 Clube *clube;
 int pontos;
 int jogos, vitorias, empates, derrotas;
 int golsPro, golsContra, saldoGols;
 double aproveitamento; 

 public:
 
 Equipe(Clube *c=nullptr);
 ~Equipe();

 Clube *obtemClube();

 int obtemPontos();
 int obtemJogos();
 int obtemVitorias();
 int obtemEmpates();
 int obtemDerrotas();
 int obtemGolsPro();
 int obtemGolsContra();
 int obtemSaldoGols();
 double obtemAproveitamento();

 
 void limpa();
 void defineClube(Clube *c);
 void registraPartida(int gP, int gC);
 string str() const;
 bool operator<(const Equipe &c) const;
 friend ostream& operator<<(ostream& out,const Equipe &e);
 };
#endif