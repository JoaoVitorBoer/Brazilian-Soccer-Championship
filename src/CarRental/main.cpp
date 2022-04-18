#include <iostream>

#include <string>

#include <unistd.h>

#include "Locadora.hpp"

using namespace std;

int main() {

  int num;
  Locadora l;

  if (!l.leArquivo("Veiculos.txt")) {
    return 1;
  }

  while (1) {

    cout << "\n=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-= \n " << endl;
    cout << " 1 -> Registrar manualmente um veículo." << endl;
    cout << " 2 -> Remover um veículo." << endl;
    cout << " 3 -> Verificar a quantidade de veículos registrados." << endl;
    cout << " 4 -> Verificar a quantidade de objetos criados." << endl;
    cout << " 5 -> Ver veículos por categoria." << endl;
    cout << " 6 -> Buscando pelo tipo passeio e abastecendo." << endl;
    cout << " 7 -> Buscando pelo tipo transporte e deslocando." << endl;
    cout << "\n=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-= " << endl;
    cin >> num;

    if (num == 1) {

      string tipo, placa;
      double cap, t, q, kmL;
      int atributo;

      cout << "Para regisrar um veículo é necessário inserir os dados de acordo com a ordem abaixo: " << endl;

      cout << "-> Digite o tipo(E, C, P): ";
      cin >> tipo;

      cout << "-> Digite a capacidade do tanque: ";
      cin >> cap;

      cout << "-> Digite o volume do tanque atual: ";
      cin >> t;

      cout << "-> Digite a quilometragem atual do veículo: ";
      cin >> q;

      cout << "-> Digite quantos Km/L o carro faz: ";
      cin >> kmL;

      cout << "-> Digite a placa do veículo: " << endl;
      cin >> placa;

      cout << "-> Digite o atributo do veículo: ";
      cin >> atributo;

      l.adicionaVeiculos(tipo, cap, t, q, kmL, placa, atributo);
    }

    if (num == 2) {
      string placa;

      cout << "Digite a placa do Veículo para removê-lo: " << endl;
      cin >> placa;
      l.removeVeiculos(placa);
    }

    if (num == 3) {
      cout << "Atualmente estão registrados um total de " << l.getVeiculosRegistrados() << " veículo/os." << endl;
    }
    if (num == 4) {
      cout << "Atualmente temos um total de " << l.getQtdObjetos() << " objeto/os já criado/os." << endl;
    }

    if (num == 5) {
      string escolha;
      cout << "Escolha uma categoria para ver os veículos Passeio/Transporte/Esportivo: " << endl;
      cin >> escolha;
      l.manipular(escolha);
    }

    if (num == 6) {
      // A busca aqui é feita para o primeiro veiculo da categoria que encontrar.
      l.buscarPasseio();
    }

    if (num == 7) {
      // A busca aqui é feita para o primeiro veiculo da categoria que encontrar.
      l.deslocarTransporte();
    }

    sleep(1);
  }
}