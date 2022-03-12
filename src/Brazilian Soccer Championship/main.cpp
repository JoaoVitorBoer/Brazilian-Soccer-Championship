//////////////////////////////////////////////////
//                                             //
// TRABALHO POO 1 - JOAO VITOR BOER ABITANTE  //
//                                           //
//////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream> 
#include "Aplicacao.hpp"
using namespace std;  

int main() {

Aplicacao app;


if (!app.leClubes("2021-clubes.txt"))
 return 1;
app.mostraClubes();
cout << endl;

if (!app.leEstadios("2021-estadios.txt"))
 return 1;
app.mostraEstadios();
cout << endl;


if (!app.leJogos("2021-jogos.txt"))
 return 1;


app.mostraJogos();
cout << endl;


app.mostraClassificacao();
cout << endl;


app.mostraPartidasPorEstadio();
cout << endl;
return 0;
}

