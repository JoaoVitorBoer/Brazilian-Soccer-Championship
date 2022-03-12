#ifndef __PEDIDO_HPP
#define __PEDIDO_HPP

#include <string>
#include <sstream>
using namespace std;

class Pedido{
  private:
    int codigo;
    int rodadaInicial;
    int rodadaFinal;
    int numeroDeProdutos;
  //  static int codigoReferencia;
  
  public:
    Pedido(int cod, int inicio, int nProdutos);
    int obtemCodigo();
    int obtemNProdutos();
    int obtemRodadaInicio();
    int obtemRodadaFinal();
    void defineRodadaFinal(int fim);    
    string toString();

  //  static void defineCodigoReferencia(int cod){
  //    codigoReferencia=cod;
  //  };

};

#endif 