#ifndef __ENTREGADOR_HPP
#define __ENTREGADOR_HPP

#include "Pedido.hpp"


class Entregador{
  private:
    int qtdePedidosEntregues;
    int numeroSorteado;
    int ciclos[5] = {4,5,6,7,8}; 
    // 0 - disponivel
    // 1 - seperando produtos
    int status;
    int espera;
   
  public:
    Entregador();
    int getStatus();
    int getEspera();
    int getqtdePedidosEntregues();
    void fechaEntrega();
    void atribuiEntrega(int RodadaAtual);
};


#endif
