#ifndef __ATENDENTE_HPP
#define __ATENDENTE_HPP

#include "Pedido.hpp"

class Atendente{
  private:
    int qtdePedidos;
    Pedido *pedidoAtual;
    // 0 - disponivel
    // 1 - seperando produtos
    int status;
    int itensSeparados;
    int totalPedidos;
    
    

  public:
    Atendente();
    int getStatus();
    void setStatus(int a);
    void atendePedido();
    void atribuiPedido(Pedido *p);
    Pedido* getPedido();
    int obtemNroItensSeparados();
    bool finalizouColeta();
    void fechaPedido();
    void AtendentePedidosCancelados();
    int getqtdePedidos();
   
};


#endif
