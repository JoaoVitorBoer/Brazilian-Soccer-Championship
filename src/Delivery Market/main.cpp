/*
 Atendente 1 = Programação    Motoboy 1 = Edson
 Atendente 2 = Orientada      Motoboy 2 = Ifarraguirre
 Atendente 3 = Objeto         Motoboy 3 = Moreno
*/
#include "Mercado.hpp"
#include "Pedido.hpp"
#include <iostream>
using namespace std;


int main() {
  
 

  int timeout = 50; // nro Rodadas
  
  int rodada=0;
  
  
  Mercado mercadinho;
  

  while(timeout>0){
    
    mercadinho.incrementaRodada(); 
    mercadinho.entraPedido();
    mercadinho.chamaAtendente(); 
    mercadinho.separaProdutos();
  //  mercadinho.debugMercado();
    mercadinho.insereNafilaDeEntrega();
    mercadinho.chamaEntregador();
    mercadinho.CancelaPedido();
    mercadinho.liberaEntregador();
    mercadinho.CalculaTempoMedio();
    timeout--;

  }

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<< endl;
  cout << "TOTAL DE PEDIDOS QUE DERAM ENTRADA: "<< mercadinho.getqntTotaldePedidos() << endl;
  cout << "PEDIDOS BEM SUCEDIDOS: "<< mercadinho.getpedidosBemSucedidos() << endl;
  cout << "PEDIDOS CANCELADOS: "<< mercadinho.getqntTotaldeCancelamentos() << endl;
  cout << "PEDIDOS QUASE CANCELADOS: "<< mercadinho.getqntTotalQuaseCancelamentos() << endl;
  cout << "ATENDENTE DO MÊS: " <<'"' << mercadinho.str()<<'"' << " COM " << mercadinho.getAtendendeDoMes() << " ATENDIMENTOS " <<endl;

  cout << "MOTOBOY DO IFOOD DO MÊS: " <<'"' << mercadinho.str2()<<'"' << " COM " << mercadinho.getEntregadorDoMes() << " ENTREGAS *VRUM* *VRUM* " <<endl;
  cout << "O TEMPO MÉDIO NA FILA DE ESPERA FOI DE: " << mercadinho.CalculaTempoMedio() << endl;
  cout << "O PEDIDO QUE MAIS DEMOROU NA FILA DE ESPERA LEVOU: " << mercadinho.calculaOMaisDemorado() <<" CICLOS"<< endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<< endl;
  
  }
 


