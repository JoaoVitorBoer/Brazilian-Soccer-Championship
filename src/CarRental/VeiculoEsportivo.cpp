#include "VeiculoEsportivo.hpp"

VeiculoEsportivo::VeiculoEsportivo( string id, double ct, double t, double q, double kmL, string p, int VMax):Veiculo( ct, t, q, kmL, p){
  VelMax = VMax; 
  identificador = id;
}


void VeiculoEsportivo::abastece(float qntAbastece){
    float aux = qntAbastece;
    Veiculo::abastece(aux);
}
 
void VeiculoEsportivo::desloca(float distancia){
    float aux2 = distancia;
    Veiculo::desloca(aux2);
}


void VeiculoEsportivo::setVelMax(int VMax){
  VelMax = VMax;
}

int VeiculoEsportivo::getVelMax(){
  return VelMax;
}
 
 
string VeiculoEsportivo::getIdentificador(){
   return identificador;
}

int VeiculoEsportivo::getAtributo(){
  return VelMax;
}


