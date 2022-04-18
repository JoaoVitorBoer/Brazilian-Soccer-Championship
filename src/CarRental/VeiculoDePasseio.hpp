#ifndef __VEICULODEPASSEIO_HPP
#define __VEICULODEPASSEIO_HPP

#include "Veiculo.hpp"
#include <string>
#include <iostream>
using namespace std;

class VeiculoDePasseio : public Veiculo{
  private:
    int qtdPassageiros;
    string identificador;
    
  public:
    VeiculoDePasseio( string id, double ct, double t, double q, double kmL,  string p, int qtdPessoas);

    void abastece(float qntAbastece);
    void desloca(float distancia);
    void setQtdPassageiros(int qtdPessoas);
    int getQtdPassageiros();
    
    virtual string getIdentificador();
    virtual int getAtributo();
};


#endif