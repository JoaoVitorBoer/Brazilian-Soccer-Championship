#ifndef __VEICULO_HPP
#define __VEICULO_HPP

#include <string>

#include <iostream>

using namespace std;

class Veiculo {
  private:
    double capacidadeTanque;
  double tanque;
  double quilometragem;
  double kmPorLitro;
  string placa;
  string identificador;
  int atributo;

  public:

    Veiculo(double ct, double t, double q, double kmL, string p);

  virtual void abastece(float qntAbastece);
  virtual void desloca(float distancia);

  double getCapacidadeTanque();
  double getTanque();
  double getQuilometragem();
  double getkmPorLitro();
  string getPlaca();

  void setCapacidadeTanque(double ct);
  void setTanque(double t);
  void setQuilometragem(double q);
  void setkmPorLitro(double kmL);
  void setPlaca(string p);

  virtual string getIdentificador();
  virtual int getAtributo();

};

#endif