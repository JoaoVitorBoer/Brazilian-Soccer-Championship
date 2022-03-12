#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wctype.h>
#include "Aplicacao.hpp"
#include "DiaEHora.hpp"

Aplicacao::Aplicacao() {
  numClubes = 0;
  numEstadios = 0;
  numJogos = 0;
}

Aplicacao::~Aplicacao() {};

#pragma region // CLUBES

bool Aplicacao::leClubes(string arquivo) { 
  ifstream input;
  input.open(arquivo, ios:: in ); 

  if (!input.is_open()) {
    cout << "Erro na abertura do arquivo " << arquivo << endl;
    return false;
  }

  // leitura do arquivo
  do {

    string abreviatura, nome, nomeCompleto, cidade, estado;

    getline(input, abreviatura);    
    getline(input, nome);
    getline(input, nomeCompleto);
    getline(input, cidade);
    getline(input, estado);

    if (!input.fail()) {
      //Cria novo clube
      Clube * aux = new Clube(abreviatura, nome, nomeCompleto, cidade, estado); 
      clubes[numClubes] = aux;
      //Cria nova equipe
      Equipe * axu2 = new Equipe(aux);
      equipes[numClubes] = axu2;

      numClubes++;
    }

  } while (input.good());
  return true;
}

void Aplicacao::mostraClubes() {
  cout << "----- CLUBES -----" << endl;
  for (int i = 0; i < numClubes; i++)
    cout << *clubes[i] << endl;

}
int Aplicacao::obtemNumClubes() {
  return numClubes;
}

Clube * Aplicacao::obtemClube(string abrev) {
  return nullptr;
}
#pragma endregion

#pragma region //ESTADIOS

bool Aplicacao::leEstadios(string arquivo) {
  ifstream input;
  input.open(arquivo, ios:: in );

  if (!input.is_open()) {
    cout << "Erro na abertura do arquivo " << arquivo << endl;
    return false;
  }

  // leitura do arquivo
  do {

    int cod;
    string codigo, nome, cidade, estado;

    getline(input, codigo);
    getline(input, nome);
    getline(input, cidade);
    getline(input, estado);

    cod = stoi(codigo);

    if (!input.fail()) {
      //Cria novo estádio
      Estadio * aux = new Estadio(cod, nome, cidade, estado);
      estadios[numEstadios] = aux;
      numEstadios++;
    }

  } while (input.good());
  return true;
}

void Aplicacao::mostraEstadios() {
  cout << "----- ESTÁDIOS -----" << endl;
  for (int b = 0; b < numEstadios; b++)
    cout << * estadios[b] << endl;

}
int Aplicacao::obtemNumEstadios() {
  return numEstadios;
}

Estadio * Aplicacao::obtemEstadio(int cod) {
  return nullptr;
}
#pragma endregion

#pragma region // JOGOS

bool Aplicacao::leJogos(string arquivo) {
  ifstream input;
  input.open(arquivo, ios:: in );

  if (!input.is_open()) {
    cout << "Erro ao abrir o arquivo de entrada" << endl;
    return false;
  }

  string indice, data, hora, mandante, r1, r2, visitante, codi;
  string ordenaosjogos[numJogos];

  do {

    input >> indice >> data >> hora >> mandante >> r1 >> r2 >> visitante >> codi;

    int dia, mes, ano, horas, minutos;
    int numero, golsMandante, golsVisitante, numeroestadio;

    if (!input.fail()) {

      numero = stoi(indice);//converte para inteiro a string indice
  
      DiaEHora * auxdh = nullptr;

      if (data.length() > 3) {
        dia = stoi(data.substr(0, 2));
        mes = stoi(data.substr(3, 2));
        ano = stoi(data.substr(6, 4));  
        horas = stoi(hora.substr(0, 2));
        minutos = stoi(hora.substr(3, 2));
       

        auxdh = new DiaEHora(dia, mes, ano, horas, minutos);
      }
      else {
        auxdh = new DiaEHora(0,0,0,0,0);
      }
      

      Estadio * estadio = nullptr;
      
      if (codi != "*") {
        numeroestadio = stoi(codi);
        for (int c = 0; c < numEstadios; c++) {
          if (estadios[c] -> obtemCodigo() == numeroestadio) {
            estadios[c] -> defineSaldo(1);
            estadio = estadios[c];
          }
        }
      } 
      else {
            estadio = nullptr;
   }



      Equipe * equipeVisitante=nullptr;
      Equipe * equipeMandante=nullptr;

      for (int p = 0; p < numClubes; p++) {
        if (equipes[p]->obtemClube()->obtemAbreviatura() == mandante) 
          equipeMandante=equipes[p];
          
                    
        else if (equipes[p]->obtemClube()->obtemAbreviatura() == visitante) 
          equipeVisitante=equipes[p];

        if((equipeMandante!=nullptr)&&(equipeVisitante!=nullptr))
          break;
      }


       if((r1 != "*") && (r2 != "*")){

       golsMandante = stoi(r1);
       golsVisitante = stoi(r2);
      
       for(int p = 0; p < numClubes; p++){
        
         if (clubes[p]->obtemAbreviatura() == mandante){
             equipes[p]->registraPartida (golsMandante, golsVisitante);
           }
         else if(clubes[p]->obtemAbreviatura() == visitante){
            equipes[p]->registraPartida (golsVisitante, golsMandante);
           }
         }

} 
     

// CONSTRUTOR

      Jogo * aux = new Jogo(numero, auxdh, equipeMandante->obtemClube(), golsMandante, golsVisitante, equipeVisitante->obtemClube(), estadio);
      jogos[numJogos] = aux;
      jogos2[numJogos] = aux;
      numJogos++;

    }

  } while (input.good());

  return true;
}

void Aplicacao::mostraJogos() {




  cout << endl << "----- JOGOS -----" << endl;
  
  for (int i = 0; i < numJogos; i++)
  for (int j = i+1; j < numJogos; j++)
  if (jogos[i]->obtemDiaHora() <= jogos[j]->obtemDiaHora()){
          jogos2[0] = jogos[j];
          jogos[j] = jogos[i];
          jogos[i] = jogos2[0];
         
  }


for (int i = 0; i < numJogos; i++)
      cout << *jogos[i] << endl;
}


int Aplicacao::obtemNumJogos() {
  return numJogos;
}

Jogo * Aplicacao::obtemJogo(int cod) {
  return nullptr;
}

Equipe * obtemEquipe(Clube * c) {
  return nullptr;
}

void Aplicacao::ordenaEquipes() {

}

#pragma region

void Aplicacao::mostraPartidasPorEstadio() {

  cout << endl << "---- ESTÁDIOS / JOGOS REALIZADOS ----" << endl;
  for (int a = 0; a < numEstadios; a++)
    cout << estadios[a] -> obtemNome() << " (" << estadios[a] -> obtemCidade() << '/' << estadios[a] -> obtemEstado() << "): " << estadios[a] -> obtemSaldo() << endl;

}

void Aplicacao::mostraClassificacao() {
  cout << endl << "----- TABELA DO CAMPEONATO BRASILEIRO DE FUTEBOL 2021 -----" << endl << endl << "N.    Clube                Pt   Jg   Vi   Em   De   GP   GC   SG   Aprov" << endl;

  int manum[numClubes];
  string strmanum[numClubes];

  string maclube[numClubes];

  int mapontos[numClubes];
  string strmapontos[numClubes];

  int majogos[numClubes];
  string strmajogos[numClubes];

  int mavitorias[numClubes];
  string strmavitorias[numClubes];

  int maempates[numClubes];
  string strmaempates[numClubes];

  int maderrotas[numClubes];
  string strmaderrotas[numClubes];

  int magolspro[numClubes];
  string strmagolspro[numClubes];

  int magolscontra[numClubes];
  string strmagolscontra[numClubes];

  int masaldos[numClubes];
  string strmasaldos[numClubes];

  double maapro[numClubes];
  string strmaapro[numClubes];

  string classifica[numClubes];
  int pontosclassifica[numClubes];
  string aux2;
  int aux;

//for´s para organizar a tabela em forma de matriz, ou seja, as linhas e colunas estarão alinhadas.
  for (int a = 0; a < numClubes; a++) {
    for (int z = 0; z < numClubes; z++) {
      manum[z] = z + 1;
      strmanum[z] = to_string(manum[z]);
      strmanum[z] = strmanum[z] + '.';
      strmanum[z].resize(4, ' ');
    }

    for (int z = 0; z < numClubes; z++) {
      maclube[z] = clubes[z] -> obtemNome();
      maclube[z].resize(23, ' ');
    }

    for (int z = 0; z < numClubes; z++) {
      mapontos[z] = equipes[z] -> obtemPontos();
      strmapontos[z] = to_string(mapontos[z]);
      strmapontos[z].resize(5, ' ');
    }

    for (int z = 0; z < numClubes; z++) {
      majogos[z] = equipes[z] -> obtemJogos();
      strmajogos[z] = to_string(majogos[z]);
      strmajogos[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      mavitorias[z] = equipes[z] -> obtemVitorias();
      strmavitorias[z] = to_string(mavitorias[z]);
      strmavitorias[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      maempates[z] = equipes[z] -> obtemEmpates();
      strmaempates[z] = to_string(maempates[z]);
      strmaempates[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      maderrotas[z] = equipes[z] -> obtemDerrotas();
      strmaderrotas[z] = to_string(maderrotas[z]);
      strmaderrotas[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      magolspro[z] = equipes[z] -> obtemGolsPro();
      strmagolspro[z] = to_string(magolspro[z]);
      strmagolspro[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      magolscontra[z] = equipes[z] -> obtemGolsContra();
      strmagolscontra[z] = to_string(magolscontra[z]);
      strmagolscontra[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      masaldos[z] = equipes[z] -> obtemSaldoGols();
      strmasaldos[z] = to_string(masaldos[z]);
      strmasaldos[z].resize(5, ' ');
    }
    for (int z = 0; z < numClubes; z++) {
      maapro[z] = equipes[z] -> obtemAproveitamento();
      strmaapro[z] = to_string(maapro[z]);
      strmaapro[z].resize(5, ' ');
    }

    for (int z = 0; z < numClubes; z++)
      classifica[z] = maclube[z] + strmapontos[z] + strmajogos[z] + strmavitorias[z] + strmaempates[z] + strmaderrotas[z] + strmagolspro[z] + strmagolscontra[z] + strmasaldos[z] + strmaapro[z];

    for (int j = 0; j < numClubes; j++) {
      for (int w = j + 1; w < numClubes; w++) {
        if (classifica[j].substr(23, 34) < classifica[w].substr(23, 34)) {
          aux2 = classifica[j];
          classifica[j] = classifica[w];
          classifica[w] = aux2;
        }
      }
    }

    cout << strmanum[a] << classifica[a] << endl;
  }
}
#pragma endregion