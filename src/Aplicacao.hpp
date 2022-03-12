// Aplicacao.hpp (Roland Teodorowitsch; 21 set. 2021)
#ifndef _APLICACAO_HPP
#define _APLICACAO_HPP

#include <string>
#include <iostream>

#include "Clube.hpp"
#include "Equipe.hpp"
#include "Estadio.hpp"
#include "Jogo.hpp"
#define MAX_CLUBES 20
#define MAX_ESTADIOS 30
#define MAX_JOGOS 380

using namespace std;

class Aplicacao {
  private:
    Clube *clubes[MAX_CLUBES];
    Equipe *equipes[MAX_CLUBES];
    int numClubes;
    Estadio *estadios[MAX_ESTADIOS];
    int numEstadios;
    Jogo *jogos[MAX_JOGOS];
    Jogo *jogos2[MAX_JOGOS];
    int numJogos;
    void ordenaJogos();
    Equipe *obtemEquipe(Clube *c);
    void calculaClassificacao();
    void ordenaEquipes();
    int indiceEstadio(Estadio *e);
  public:
    Aplicacao();
    ~Aplicacao();
    bool leClubes(string arquivo);
    int obtemNumClubes();
    Clube *obtemClube(string abrev);
    void mostraClubes();
    bool leEstadios(string arquivo);
    int obtemNumEstadios();
    Estadio *obtemEstadio(int cod);
    void mostraEstadios();
    bool leJogos(string arquivo);
    int obtemNumJogos();
    Jogo *obtemJogo(int cod);
    void mostraJogos();
    void mostraClassificacao();
    void mostraPartidasPorEstadio();
        


};
#endif