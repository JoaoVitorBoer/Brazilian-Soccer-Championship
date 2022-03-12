#include <sstream>
#include <iostream>
#include "Equipe.hpp"


Equipe::Equipe(Clube *c){
   clube=c;
   int pontos = 0;
   int jogos = 0;
   int vitorias = 0;
   int empates = 0;
   int derrotas = 0;
   int golsPro= 0;
   int golsContra= 0;
   int saldoGols = 0;
   double aproveitamento = 00.00;
}



Clube * Equipe::obtemClube(){
  return clube;
}

int Equipe::obtemPontos(){
  return pontos;
}
int Equipe::obtemJogos() {
  return jogos;
}
int Equipe::obtemVitorias(){
  return vitorias;
}
int Equipe::obtemEmpates() {
  return empates;
}
int Equipe::obtemDerrotas() {
  return derrotas;
}
int Equipe::obtemGolsPro() {
  return golsPro;
}
int Equipe::obtemGolsContra(){
  return golsContra;
}
int Equipe::obtemSaldoGols() {
  return saldoGols;
}
double Equipe::obtemAproveitamento() {
  return aproveitamento;
}


void Equipe::limpa(){
  
}


void Equipe::defineClube(Clube *c){
  Clube *clube;
}

void Equipe::registraPartida(int gP, int gC){
  //(gols feitos e gols sofridos), atualizando pontos, jogos, vitórias, empates, derrotas, gols pró, gols contra, saldo de gols e aproveitamento
  golsPro = golsPro + gP;
  golsContra = golsContra + gC;
  saldoGols = saldoGols + (gP-gC);
  if(gP > gC){pontos = pontos + 3; vitorias++;}
  if(gP < gC){pontos = pontos + 0; derrotas++;}  
  if(gP == gC){pontos = pontos + 1; empates++;}
  jogos = jogos + 1;
  aproveitamento = pontos;
  aproveitamento = (aproveitamento/(jogos*3)*100);
}




bool Equipe::operator<(const Equipe &c) const{
    
  if( pontos < c.pontos) return true;
  else if(pontos == c.pontos){
    if(jogos<c.jogos)return true;
    else if(jogos==c.jogos){
      if(vitorias<c.vitorias) return true;
      else if(vitorias==c.vitorias){
        if(empates<c.empates) return true;
        else if(empates==c.empates){
          if(derrotas<c.derrotas) return true;
          return false;
        }
        else return false;
      }
      else return false;
    }
    else return false;
  }
  else return false;



 }

string Equipe::str() const{
  stringstream ss;

  ss <<  clube->obtemNome() << "    " << pontos << "  " << jogos << " " << vitorias << "  " << empates << "  "<< derrotas << "  " << golsPro 
  << "  " << golsContra << "  " << saldoGols << "  " <<  aproveitamento;

  return ss.str();

}

 ostream& operator<<(ostream& out,const Equipe &e)
 {
   return out << e.str();
 }