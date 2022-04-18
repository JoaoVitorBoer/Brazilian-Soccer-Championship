#include "Veiculo.hpp"

Veiculo::Veiculo(double ct, double t, double q, double kmL, string p){
  capacidadeTanque = ct;
  tanque = t;
  quilometragem = q;
  kmPorLitro = kmL;
  placa = p;
  
  
}

double Veiculo::getCapacidadeTanque(){
  return capacidadeTanque;
}

double Veiculo::getTanque(){
  return tanque;
}

double Veiculo::getQuilometragem(){
  return quilometragem;
}

double Veiculo::getkmPorLitro(){
  return kmPorLitro;
}

string Veiculo::getPlaca(){
  return placa;
}

void Veiculo::setCapacidadeTanque(double ct){
  capacidadeTanque = ct;
 }

void Veiculo::setTanque(double t){
  tanque = t;
 }

void Veiculo::setQuilometragem(double q){
  quilometragem = q;
 }

void Veiculo::setkmPorLitro(double kmL){
  kmPorLitro = kmL;
 }
 
void Veiculo::setPlaca(string p){
  placa = p;
 }

void Veiculo::abastece(float qntAbastece){
  if( tanque == capacidadeTanque){
      throw "Ops, seu tanque está cheio, pare de tentar abastecer, a gasolina está cara.";
  }

  tanque = tanque + qntAbastece;

   if(tanque <= capacidadeTanque){
      cout << "\n-> Veiculo abastecido com sucesso <-" << endl;
      
   }
   if(tanque > capacidadeTanque){
    tanque = capacidadeTanque;
    throw "Ops, você não precisa de tudo isso, seu tanque foi abastecido somente com o necessário para ficar cheio.";
  }
  

}
 
void Veiculo::desloca(float distancia){
    
    if(tanque > 0){
      float qlitros = distancia / kmPorLitro;
      if(qlitros <= tanque){
        quilometragem  =  quilometragem + distancia;
        tanque = tanque - qlitros;
        throw "\n ->Veiculo deslocado com sucesso <-";

    }
      else {
        float qdistancia = tanque * kmPorLitro;   
        quilometragem = quilometragem + qdistancia;
        tanque = 0;
        throw "Opa amigão, calma-lá, não tem como andar mais do que tem no tanque né? Seu veículo foi deslocado somente o que o tanque permitia.\n";
       
    }
  }
    

}

string Veiculo::getIdentificador(){
  return identificador;
}

int Veiculo::getAtributo(){
  return atributo;
}






