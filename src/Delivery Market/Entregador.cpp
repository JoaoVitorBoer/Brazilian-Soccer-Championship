#include "Entregador.hpp"
#include <iostream>

Entregador::Entregador(){
   qtdePedidosEntregues = 0;
   status = 0;
   numeroSorteado = 0;
   espera = 0;
}

int Entregador::getStatus() {
  return status;
}


int Entregador::getqtdePedidosEntregues() {
  return qtdePedidosEntregues;
}

void Entregador::atribuiEntrega(int RodadaAtual){
    status = 1;
    //Sorteia o número de ciclos(de 4 a 8) que o entregador vai demorar. 
    srand(time(NULL));
    numeroSorteado = rand() % 5;
    espera = ciclos[numeroSorteado] + RodadaAtual;
    
}
int Entregador::getEspera(){
  return espera;
  
}

void Entregador::fechaEntrega(){
  status = 0;
  qtdePedidosEntregues++;
  //cout <<" \nUHUL ENTREGA REALIZADA \n" << endl;
}