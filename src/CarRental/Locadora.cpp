#include "Locadora.hpp"

#include "Veiculo.hpp"

#include <fstream>

#include <iostream>

#include <string>

#include <iterator>

using namespace std;

int Locadora::getVeiculosRegistrados() {
  return ListaDeVeiculos.size();
}

int Locadora::getQtdObjetos() {
  return qtdObjetos;
}

void Locadora::adicionaVeiculos(string e, double cap, double t, double q, double kmL, string placa, int atributo) {

  if (e == "P") {
    veiculo = new VeiculoDePasseio(e, cap, t, q, kmL, placa, atributo);
    ListaDeVeiculos.push_back(veiculo);
    qtdObjetos++;
  }
  if (e == "C") {
    double atributo_aux = (double) atributo;
    veiculo = new VeiculoDeTransporte(e, cap, t, q, kmL, placa, atributo_aux);
    ListaDeVeiculos.push_back(veiculo);
    qtdObjetos++;
  }
  if (e == "E") {
    veiculo = new VeiculoEsportivo(e, cap, t, q, kmL, placa, atributo);
    ListaDeVeiculos.push_back(veiculo);
    qtdObjetos++;
  }

  cout << "\n Veículo registrado com sucesso!!!" << endl;

}

void Locadora::removeVeiculos(string p) {
  for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {
    if (((Veiculo * ) * it) -> getPlaca() == p) {
      cout << "Veiculo de placa " << ((Veiculo * ) * it) -> getPlaca() << " deletado com sucesso." << endl;
      ListaDeVeiculos.erase(it);
      break;
    }
    else {
      cout << " ERRO: Remoção impossível!!! Veículo de placa " << p << " ainda não foi registrado no sistema." << endl;
      break;
    
    }
  }

}

void Locadora::manipular(string aux) {
  if (ListaDeVeiculos.size() == 0) {
    cout << "Ainda não há veículos registrados nessa categoria." << endl;
  }

  if (aux == "Passeio") {
    for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {
      
      if (((Veiculo * ) * it) -> getIdentificador() == "P") {
        cout << "\nPlaca: " << ((Veiculo * ) * it) -> getPlaca() << endl;
        cout << "Capacidade do tanque: " << ((Veiculo * ) * it) -> getCapacidadeTanque() << endl;
        cout << "Volume do tanque atual: " << ((Veiculo * ) * it) -> getTanque() << endl;
        cout << "Quilometragem atual: " << ((Veiculo * ) * it) -> getQuilometragem() << endl;
        cout << "Kilometros por litro: " << ((Veiculo * ) * it) -> getkmPorLitro() << endl;
        cout << "Quantidade de pessoas que cabem no veículo: \n" << ((Veiculo * ) * it) -> getAtributo() << endl;
      }
      }
    }
    

    else if (aux == "Esportivo") {
      for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {
        if (((Veiculo * ) * it) -> getIdentificador() == "E") {
           cout << "\nPlaca: " << ((Veiculo * ) * it) -> getPlaca() << endl;
          cout << "Capacidade do tanque: " << ((Veiculo * ) * it) -> getCapacidadeTanque() << endl;
          cout << "Volume do tanque atual: " << ((Veiculo * ) * it) -> getTanque() << endl;
          cout << "Quilometragem atual: " << ((Veiculo * ) * it) -> getQuilometragem() << endl;
          cout << "Kilometros por litro: " << ((Veiculo * ) * it) -> getkmPorLitro() << endl;
          cout << "Velocidade máxima que o veículo atinge: \n" << ((Veiculo * ) * it) -> getAtributo() << endl;
        }
      }
    }
    else if (aux == "Transporte") {
      for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {
        if (((Veiculo * ) * it) -> getIdentificador() == "C") {
           cout << "\nPlaca: " << ((Veiculo * ) * it) -> getPlaca() << endl;
          cout << "Capacidade do tanque: " << ((Veiculo * ) * it) -> getCapacidadeTanque() << endl;
          cout << "Volume do tanque atual: " << ((Veiculo * ) * it) -> getTanque() << endl;
          cout << "Quilometragem atual: " << ((Veiculo * ) * it) -> getQuilometragem() << endl;
          cout << "Kilometros por litro: " << ((Veiculo * ) * it) -> getkmPorLitro() << endl;
          cout << "Capacidade de carga em Toneladas: \n" << ((Veiculo * ) * it) -> getAtributo() << endl;
        }
      }
    }
    else{
      cout << "Por favor, verifique se digitou corretamente e se seguiu a formatação indicada." << endl;
      
    }
  }
  



void Locadora::buscarPasseio() {
  for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {

    if (((Veiculo * ) * it) -> getIdentificador() == "P") {
      cout << " * Veiculo antes de abastecer: *" << endl;
      cout << "\nCapacidade total do tanque: " << ((Veiculo * ) * it) -> getCapacidadeTanque() << endl;
      cout << "Volume atual do tanque: " << ((Veiculo * ) * it) -> getTanque() << endl;;

      try {
        ((Veiculo * ) * it) -> abastece(100000000); // Edson, coloquei esse valor absurdo justamente para gerar a exceção.
      } catch (const char * msg) {
        cout << "\nERRO: " << msg << endl;
      }

      cout << "\n* Veiculo após de abastecer: *" << endl;
      cout << "\nCapacidade total do tanque: " << ((Veiculo * ) * it) -> getCapacidadeTanque() << endl;
      cout << "Volume atual do tanque: " << ((Veiculo * ) * it) -> getTanque() << endl;
      break;

    }
  }
}

void Locadora::deslocarTransporte() {
  for (list < Veiculo * > ::iterator it = ListaDeVeiculos.begin(); it != ListaDeVeiculos.end(); it++) {

    if (((Veiculo * ) * it) -> getIdentificador() == "C") {
      if(((Veiculo * ) * it) -> getTanque() == 0){ cout << "Abasteça primeiro, veículo sem gaoslina. "; break;}
      else {
      cout << " * Veiculo antes de deslocar: *" << endl;
      cout << "\nQuilometragem atual: " << ((Veiculo * ) * it) -> getQuilometragem() << endl;
      cout << "Tanque atual: " << ((Veiculo * ) * it) -> getTanque() << endl;

      try {
        ((Veiculo * ) * it) -> desloca(100000); // Edson, coloquei esse valor absurdo justamente para gerar a exceção.
      } catch (const char * msg) {
        cout << "\nERRO: " << msg << endl;
      }

      cout << "\n* Veiculo após deslocar: *" << endl;
      cout << "\nQuilometragem atual: " << ((Veiculo * ) * it) -> getQuilometragem() << endl;
      cout << "Tanque atual: " << ((Veiculo * ) * it) -> getTanque() << endl;
      break;
      }
    }
  }
}

bool Locadora::leArquivo(string arquivo) {

  ifstream input;
  input.open(arquivo, ios:: in );

  if (!input.is_open()) {
    cout << "Erro na abertura do arquivo " << arquivo << endl;
    return false;
  }
  do {
    string tipo, capacidade_aux, tanque_aux, quilometragem_aux, kmL_aux, placa, atributo_aux;
    getline(input, tipo, ';');
    getline(input, capacidade_aux, ';');
    getline(input, tanque_aux, ';');
    getline(input, quilometragem_aux, ';');
    getline(input, kmL_aux, ';');
    getline(input, placa, ';');
    getline(input, atributo_aux);

    double capacidade = stod(capacidade_aux);
    double tanque = stod(tanque_aux);
    double quilometragem = stod(quilometragem_aux);
    double kmL = stod(kmL_aux);

    if (!input.fail()) {
      if (tipo == "C") {
        double atributo = stod(atributo_aux);
        veiculo = new VeiculoDeTransporte(tipo, capacidade, tanque, quilometragem, kmL, placa, atributo);
        ListaDeVeiculos.push_back(veiculo);
        qtdObjetos++;
      }
      if (tipo == "P") {
        int atributo = stoi(atributo_aux);
        veiculo = new VeiculoDePasseio(tipo, capacidade, tanque, quilometragem, kmL, placa, atributo);
        ListaDeVeiculos.push_back(veiculo);
        qtdObjetos++;

      }
      if (tipo == "E") {
        int atributo = stoi(atributo_aux);
        veiculo = new VeiculoEsportivo(tipo, capacidade, tanque, quilometragem, kmL, placa, atributo);
        ListaDeVeiculos.push_back(veiculo);
        qtdObjetos++;

      }

    }

  } while (input.good());
  return true;

}