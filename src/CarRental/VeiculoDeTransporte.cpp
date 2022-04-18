#include "VeiculoDeTransporte.hpp"
#include <fstream>
#include <iostream>
#include <string>

VeiculoDeTransporte::VeiculoDeTransporte(string id, double ct, double t, double q, double kmL,  string p, double cap):Veiculo(ct, t, q, kmL, p){
  capacidade = cap;
  identificador = id;

}

void VeiculoDeTransporte::abastece(float qntAbastece){
    float aux = qntAbastece;
     Veiculo::abastece(aux);
}
 
void VeiculoDeTransporte::desloca(float distancia){
    float aux2 = distancia;
    Veiculo::desloca(aux2);
}


void VeiculoDeTransporte::setCapacidade(double cap){
   capacidade = cap;
}

int VeiculoDeTransporte::getCapacidade(){
  return capacidade;
}

 string VeiculoDeTransporte::getIdentificador(){
    return identificador;
 }

 int VeiculoDeTransporte::getAtributo(){
 
    int capacidade_aux = (int)capacidade;
    return capacidade_aux;
 }

