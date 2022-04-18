#ifndef __LOCADORA_HPP
#define __LOCADORA_HPP

#include <string>

#include <list>

#include "Veiculo.hpp"

#include "VeiculoDeTransporte.hpp"

#include "VeiculoDePasseio.hpp"

#include "VeiculoEsportivo.hpp"

using namespace std;

class Locadora {
  private:
    Veiculo * veiculo;
  int VeiculosRegistrados();
  int qtdObjetos = 0;
  list < Veiculo * > ListaDeVeiculos;

  public:
    int getVeiculosRegistrados();
  int getQtdObjetos();

  void adicionaVeiculos(string e, double cap, double t, double q, double kmL, string placa, int atributo);
  void removeVeiculos(string p);
  void manipular(string aux);
  void buscarPasseio();
  void deslocarTransporte();

  bool leArquivo(string arquivo);

};

#endif