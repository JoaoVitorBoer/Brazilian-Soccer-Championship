#include <sstream>
#include <iostream>
#include "Clube.hpp"


Clube::Clube(string a,string n, string nC, string c, string e){
  abreviatura=a;
  nome=n;
  nomeCompleto=nC;
  cidade=c;
  estado=e;  
}


string Clube::obtemNome() const{
  return nome;
}

string Clube::obtemAbreviatura() const{
  return abreviatura;
}
string Clube::obtemCidade() const{
  return cidade;
}
string Clube::obtemNomeCompleto() const{
  return nomeCompleto;
}
string Clube::obtemEstado() const{
  return estado;
}


void Clube::defineAbreviatura(string a){
  abreviatura = a;
}
void Clube::defineNome(string n){
  nome = n;
}
void Clube::defineNomeCompleto(string nC){
  nomeCompleto = nC;
}
void Clube::defineCidade(string c){
  cidade = c;
}
void Clube::defineEstado(string e){
  estado = e;
}

bool Clube::operator<(const Clube &c) const{
    return true;
 }

string Clube::str() const{
  stringstream ss;

  ss << "[" << abreviatura << "] " << nome << " / " << nomeCompleto << " (" << cidade << " - " << estado << ") ";

  return ss.str();

}

 istream& operator>>(istream& in,Clube &c){
  return in;
 }

 ostream& operator<<(ostream& out,const Clube &c)
 {
   return out << c.str();
 }