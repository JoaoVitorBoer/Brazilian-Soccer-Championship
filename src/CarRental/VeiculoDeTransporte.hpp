#ifndef __VEICULODETRANSPORTE_HPP
#define __VEICULODETRANSPORTE_HPP

#include "Veiculo.hpp"
#include <string>
using namespace std;

class VeiculoDeTransporte : public Veiculo{
  private:
    double capacidade;
    string identificador;
  public:
    VeiculoDeTransporte(string id, double ct, double t, double q, double kmL,  string p, double cap);

    void abastece(float qntAbastece);
    void desloca(float distancia);
    void setCapacidade(double capacidade);
    int getCapacidade();
    
    virtual string getIdentificador();
    virtual int getAtributo();
};  


#endif


