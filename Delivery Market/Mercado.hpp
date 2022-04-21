#ifndef __MERCADO_HPP
#define __MERCADO_HPP

#include "Atendente.hpp"
#include "Entregador.hpp"
#include "Pedido.hpp"
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Mercado{
  private:
    Atendente atendente[3];
    Entregador entregador[3];

    
    int rodadaAtual;
    int idCodigo;
    
    list<Pedido *> listaDePedidos;
    list<Pedido *> listaDeEntrega;
    list<Pedido *> qntTotaldePedidos;
    vector<int> listaDeDemora;
    list<int> itensDemorados;
    
    int PedidosCancelados;
    int pedidosBemSucedidos;
    int PedidosQuaseCancelados;
    int AtendentedoMes;
    int rodadaFinal;
    int pedidoAtrasado;

    float tempoMedio;
  
    
  public:
    Mercado();
    void debugMercado();
    void incrementaRodada();
    void entraPedido();
    void chamaAtendente();
    void separaProdutos();
    void insereNafilaDeEntrega();
    void chamaEntregador();
    void liberaEntregador();
    void CancelaPedido();
    float CalculaTempoMedio();

    int getqntTotaldePedidos();
    int getqntTotaldeCancelamentos();
    int getpedidosBemSucedidos();
    int getqntTotalQuaseCancelamentos();
    int getEntregadorDoMes();
    int calculaOMaisDemorado();
    int getAtendendeDoMes();

    string str();
    string str2();

  



};

#endif
