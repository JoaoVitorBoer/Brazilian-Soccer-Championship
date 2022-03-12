#include <iostream>
#include <sstream>
#include "Estadio.hpp"

Estadio::Estadio(int cod, string n, string c, string e){
  codigo = cod;
  nome = n;
  cidade = c;
  estado = e;  
}

string Estadio::obtemNome() const{
  return nome;
}

int Estadio::obtemCodigo() const{
  return codigo;
}

string Estadio::obtemCidade() const{
  return cidade;
}

 string Estadio::obtemEstado() const{
   return estado;
 }

int Estadio::obtemSaldo() const{
    return saldo;
}

 void Estadio::defineCodigo(int cod){
   int codigo = cod;
 }

 void Estadio::defineNome(string n){
   string nome = n;
 }

 void Estadio::defineCidade(string c){
   string cidade = c;
 }

 void Estadio::defineEstado(string e){
   string estado = e;
 }

 void Estadio::defineSaldo(int nu){
   saldo = saldo + nu;
 }

 bool Estadio::operator<(const Estadio &e) const{
    return true;
 }


 string Estadio::str() const{
   stringstream ss;
   
   if (codigo < 10)
   ss << "[" << codigo << "]  " << nome << " (" << cidade << " - " << estado << ')';
   else ss << "[" << codigo << "] " << nome << " (" << cidade << " - " << estado << ')';
   return ss.str();
 }

 istream& operator>>(istream& in,Estadio &e){
  return in;
 }

 ostream& operator<<(ostream& out,const Estadio &e)
 {
   return out << e.str();
 }

 

