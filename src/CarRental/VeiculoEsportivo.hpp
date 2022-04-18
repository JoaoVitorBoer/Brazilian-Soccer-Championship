#ifndef __VEICULOESPORTIVO_HPP
#define __VEICULOESPORTIVO_HPP


#include "Veiculo.hpp"
#include <string>
using namespace std;

class VeiculoEsportivo : public Veiculo{
  private:
    int VelMax;
    string identificador;
    
  public:
    VeiculoEsportivo( string id, double ct, double t, double q, double kmL,  string p, int VMax);

    void abastece(float qntAbastece);
    void desloca(float distancia);
    void setVelMax(int VMax);
    int getVelMax();

    virtual string getIdentificador();
    virtual int getAtributo();
};

#endif
