// Clube.hpp (Roland Teodorowitsch; 9 set. 2021)
#ifndef _ESTADIO_HPP
#define _ESTADIO_HPP


#include <string>

using namespace std;

class Estadio {
 private:
 int codigo;
 int saldo = 0;
 string nome;
 string cidade;
 string estado;
 public:
 
 Estadio(int cod=0,string n="",string c="", string e="");
 ~Estadio();
 int obtemCodigo() const;
 string obtemNome() const;
 string obtemCidade() const;
 string obtemEstado() const;
 int obtemSaldo() const;
 void defineCodigo(int cod);
 void defineNome(string n);
 void defineCidade(string c);
 void defineEstado(string e);
 void defineSaldo(int nu);
 string str() const;
 bool operator<(const Estadio &e) const;
 friend istream& operator>>(istream& in,Estadio &e);
 friend ostream& operator<<(ostream& out,const Estadio &e);
 };
#endif
