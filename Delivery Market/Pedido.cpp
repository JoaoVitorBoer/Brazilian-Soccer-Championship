#include "Pedido.hpp"

Pedido::Pedido(int cod, int inicio, int nProdutos){
  codigo=cod;
  rodadaInicial=inicio;
  numeroDeProdutos=nProdutos;
}

int Pedido::obtemCodigo(){
  return codigo;  
}
int Pedido::obtemNProdutos(){
  return numeroDeProdutos;  
}
int Pedido::obtemRodadaInicio(){
  return rodadaInicial;  
}
int Pedido::obtemRodadaFinal(){
  return rodadaFinal;  
}

void Pedido::defineRodadaFinal(int fim){
  rodadaFinal=fim;  
}



string Pedido::toString(){
  stringstream ss;
  ss << "Pedido " << codigo << endl;
  ss << "  Inicio em: " << rodadaInicial << endl;
  ss << "  #Produtos: " << numeroDeProdutos << endl;
  return ss.str();    
}
