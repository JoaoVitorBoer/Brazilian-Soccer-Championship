#include "Atendente.hpp"

Atendente::Atendente(){
  qtdePedidos=0;
  pedidoAtual=nullptr;
  status=0;
  itensSeparados=0;
  totalPedidos = 0;

}
int Atendente::getStatus(){
  return status;  
}
void Atendente::atendePedido(){
  if((pedidoAtual!=nullptr)&&(itensSeparados<pedidoAtual->obtemNProdutos()))
    itensSeparados++;  
}
void Atendente::atribuiPedido(Pedido *p){
  pedidoAtual=p;
  itensSeparados=0;
  status=1;  
}
Pedido* Atendente::getPedido(){
  return pedidoAtual;
}

int Atendente::obtemNroItensSeparados(){
  return itensSeparados;
}

bool Atendente::finalizouColeta(){
  if(pedidoAtual!=nullptr && pedidoAtual->obtemNProdutos()==itensSeparados)
    return true;
  return  false;
}

void Atendente::fechaPedido(){
  status=0;
  // anota pedido finalizado
  qtdePedidos++;
  pedidoAtual=nullptr;
  itensSeparados=0;
}
void Atendente::AtendentePedidosCancelados(){}

void Atendente::setStatus(int a){
  status = a;
  itensSeparados=0;
  pedidoAtual=nullptr;
}

int Atendente::getqtdePedidos(){
  return qtdePedidos;
}



