#include "VeiculoDePasseio.hpp"

VeiculoDePasseio::VeiculoDePasseio(string id, double ct, double t, double q, double kmL, string p, int qtdPessoas): Veiculo(ct, t, q, kmL, p) {
  qtdPassageiros = qtdPessoas;
  identificador = id;

}

void VeiculoDePasseio::abastece(float qntAbastece) {
  float aux = qntAbastece;
  Veiculo::abastece(aux);
}

void VeiculoDePasseio::desloca(float distancia) {
  float aux2 = distancia;
  Veiculo::desloca(aux2);
}

void VeiculoDePasseio::setQtdPassageiros(int a) {
  qtdPassageiros = a;
}

int VeiculoDePasseio::getQtdPassageiros() {
  return qtdPassageiros;
}

string VeiculoDePasseio::getIdentificador() {
  return identificador;
}

int VeiculoDePasseio::getAtributo() {
  return qtdPassageiros;
}