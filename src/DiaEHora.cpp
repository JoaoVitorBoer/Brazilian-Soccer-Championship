#include <iostream>
#include <sstream>
#include <iomanip>
#include "DiaEHora.hpp"

DiaEHora::DiaEHora(int d, int m, int a, int h, int mn){
  
  
  dia = d;
  mes = m;
  ano = a;
  horas = h;
  minutos = mn;
}

DiaEHora::DiaEHora(int d, int m, int a)
{
  dia = d;
  mes = m;
  ano = a;
}

DiaEHora::DiaEHora()
{
  
}

DiaEHora::~DiaEHora()
{
 
}

unsigned DiaEHora::obtemDia(){
  return dia;
}

unsigned DiaEHora::obtemMes() {
  return mes;
}

unsigned DiaEHora::obtemAno() {
  return ano;
}

unsigned DiaEHora::obtemHoras() {
  return horas;
}

unsigned DiaEHora::obtemMinutos() {
  return minutos;
}




void DiaEHora::defineDia(int d){
   dia = d;
}

void DiaEHora::defineMes(int m){
   mes = m;
}

void DiaEHora::defineAno(int a){
   ano = a;
}

void DiaEHora::defineData(int d, int m, int a){

   dia = d;
   mes = m;
   ano = a;
}

void DiaEHora::defineHoras(int h){
   horas = h;
}

void DiaEHora::defineMinutos(int mn){
   minutos = mn;
}

void DiaEHora::defineHorario(int h, int mn){
  horas = h;
  minutos = mn;
} 


bool DiaEHora::operator<=(const DiaEHora &dh){


  if(ano<dh.ano)  return true;
  else if(ano==dh.ano){
    if(mes>dh.mes)return true;
    else if(mes==dh.mes){
      if(dia>dh.dia) return true;
      else if(dia==dh.dia){
        if(horas>dh.horas) return true;
        else if(horas==dh.horas){
          if(minutos>dh.minutos) return true;
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



string DiaEHora::str()const {
  stringstream ss;

if (dia > 0 && dia <= 31)
  ss << setfill('0') << setw(2) << dia << '/' << setfill('0') << setw(2) << mes << '/' << ano << ' ' << horas << ':' << setfill('0') << setw(2) << minutos ;
if (dia <= 0)
  ss << "*  *";
if (dia > 31)
     ss << dia << "//" << mes << "//" << ano << "//" << horas << "//" << minutos ;
   
    return ss.str();
}


istream& operator>>(istream& in,DiaEHora &dh){
  return in;
 }

ostream& operator<<(ostream& out,const DiaEHora &dh)
{
  return out << dh.str();
}












  


