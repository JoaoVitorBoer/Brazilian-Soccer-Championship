#include "Mercado.hpp"
#include <sstream>
#include <string>

Mercado::Mercado(){
  rodadaAtual=0;  
  idCodigo=1;
  pedidosBemSucedidos = 0;
  PedidosCancelados = 0;
  PedidosQuaseCancelados = 0;
  rodadaFinal = 0;
  tempoMedio = 0;
 
}
void Mercado::incrementaRodada(){
  rodadaAtual++;
} 
void Mercado::entraPedido(){
  int probabilidade = rand()%100;

  //probabilidade de 20%
  if(probabilidade<80){
    //gera um pedido
    Pedido * p = new Pedido(idCodigo++, rodadaAtual, 3+(rand()%8));
    listaDePedidos.push_back(p);
    qntTotaldePedidos.push_back(p);
    
 

    
  }
  
}

int Mercado::getqntTotaldePedidos(){
  return qntTotaldePedidos.size();
}


#pragma region // DEBUG PARA TESTES

void Mercado::debugMercado(){
  
  cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "* Rodada " << rodadaAtual << " *" <<  endl;
  cout << " [Pedidos na fila: " << listaDePedidos.size() << "]"<< endl;
  cout << "\n* Atendentes * " << endl;
  for( int i=0; i<3; i++){

    if (i == 0 ){
    cout << "  \nAtendente: " << "Programação" << endl;
    cout << "    Status: " << (atendente[i].getStatus()==0?"Livre":"Ocupado") << endl;
    if(atendente[i].getPedido()!=nullptr){
      Pedido * aux = atendente[i].getPedido();
      cout << "    Pedido: " << aux->obtemCodigo() << endl;
      cout << "    nroDeProdutos: " << aux->obtemNProdutos() << endl;
      cout << "    separados: " << atendente[i].obtemNroItensSeparados() << endl;
    }
    }
    if (i == 1 ){
    cout << "  \nAtendente: " << "Orientada" << endl;
    cout << "    Status: " << (atendente[i].getStatus()==0?"Livre":"Ocupado") << endl;
    if(atendente[i].getPedido()!=nullptr){
      Pedido * aux = atendente[i].getPedido();
      cout << "    Pedido: " << aux->obtemCodigo() << endl;
      cout << "    nroDeProdutos: " << aux->obtemNProdutos() << endl;
      cout << "    separados: " << atendente[i].obtemNroItensSeparados() << endl;
    }
    }
    if (i == 2 ){
    cout << "  \nAtendente: " << "Objetos" << endl;
    cout << "    Status: " << (atendente[i].getStatus()==0?"Livre":"Ocupado") << endl;
    if(atendente[i].getPedido()!=nullptr){
      Pedido * aux = atendente[i].getPedido();
      cout << "    Pedido: " << aux->obtemCodigo() << endl;
      cout << "    nroDeProdutos: " << aux->obtemNProdutos() << endl;
      cout << "    separados: " << atendente[i].obtemNroItensSeparados() << endl;
    }
    }
    
  }
  
  cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;    
  cout << "  \nPedidos para entrega: " << listaDeEntrega.size() << endl;
    for(list<Pedido *>::iterator it=listaDeEntrega.begin(); it!=listaDeEntrega.end(); it++)
      cout << "    Pedido: " << ((Pedido*) *it)->obtemCodigo() << endl;

  
      cout<< "\n";
      cout << "MotoBoys" << endl;
      for( int i=0; i<3; i++){
        if (i == 0){
        cout << "  Motoboy: " << "Edson"  << endl;
        cout << "    Status: " << (entregador[i].getStatus()==0?"Livre":"Ocupado") << endl;
        }
        if (i == 1){
        cout << "  Motoboy: " << "Ifarraguirre"  << endl;
        cout << "    Status: " << (entregador[i].getStatus()==0?"Livre":"Ocupado") << endl;
        }
        if (i == 2){
        cout << "  Motoboy: " << "Moreno"  << endl;
        cout << "    Status: " << (entregador[i].getStatus()==0?"Livre":"Ocupado") << endl;

}
}


}
#pragma endregion
      

void Mercado::chamaAtendente(){

  for(int i=0; i<3 && listaDePedidos.size()>0; i++)
    // atendente livre para receber pedido e pedido não cancelado
    if(atendente[i].getStatus()==0 ){ 
//passar para o pedido a variavel int rodadaFinal
      Pedido *aux = listaDePedidos.front();
      atendente[i].atribuiPedido(aux);
      listaDePedidos.pop_front();
      
      rodadaFinal = rodadaAtual - aux->obtemRodadaInicio();
      pedidoAtrasado = aux->obtemCodigo();

      listaDeDemora.push_back(rodadaFinal);
      itensDemorados.push_back(pedidoAtrasado);




   
    
    }
}
  


void Mercado::separaProdutos(){


  //probabilidade de 15% de cancelar
  

  for(int i=0; i<3; i++){
    atendente[i].atendePedido();
}

}


void Mercado::insereNafilaDeEntrega(){


  //probabilidade de 10% de cancelar
  
  for(int i=0; i<3; i++)
    if(atendente[i].getStatus()==1 && atendente[i].finalizouColeta() ){
      Pedido * aux = atendente[i].getPedido();
      // insere na lista de entrega
      listaDeEntrega.push_back(aux);
      atendente[i].fechaPedido();
    }
    
    
}


void Mercado::chamaEntregador(){
    int prob = rand()%100;

 for(int i=0; i<3 && listaDeEntrega.size()>0 && prob < 85; i++)
    // entregador livre para receber pedido
    if(entregador[i].getStatus()==0 ){
      listaDeEntrega.pop_front();
      entregador[i].atribuiEntrega(rodadaAtual);
    }
    if( prob > 85 )
      PedidosQuaseCancelados++;

}

void Mercado::CancelaPedido(){
  int prob = rand()%100;

  if(prob>80 && (listaDeEntrega.size()>0 || listaDePedidos.size()>0)){
    if(prob > 80 && prob <90  && listaDePedidos.size()>0){    //Cancela ou na fila de espera ou na separação.
        if(prob > 80 && prob < 85  && listaDePedidos.size()>0){ //Cancela na fila de espera.
          listaDePedidos.pop_front(); 
          PedidosCancelados++;
          }   
        else if(prob > 85 && prob < 90 && listaDePedidos.size()>0){
          atendente[rand()%3].setStatus(0);
          PedidosCancelados++;
          
        }   //Cancela na separação.
    }
    if(prob > 90 && prob < 100 && listaDeEntrega.size()>0){  //Cancela na fila de entrega.
      listaDeEntrega.pop_front();
      PedidosCancelados++;
      
  }
}
}


void Mercado::liberaEntregador(){

  for(int i=0; i<3 && listaDeEntrega.size()>0; i++){
      if(entregador[i].getEspera() == rodadaAtual){
        entregador[i].fechaEntrega();
        pedidosBemSucedidos++;
      }
    
  } 
}
int Mercado::getpedidosBemSucedidos(){
  return pedidosBemSucedidos;
}

int Mercado::getqntTotaldeCancelamentos(){
  return PedidosCancelados;
}

int Mercado::getqntTotalQuaseCancelamentos(){
  return PedidosQuaseCancelados;
}


int Mercado::getAtendendeDoMes(){

  
int i, melhorAtendente;
for (i = 0; i < 3; i++) {
    if (i == 0) {
          melhorAtendente = atendente[i].getqtdePedidos();
    }
    if (atendente[i].getqtdePedidos() > melhorAtendente) {
        melhorAtendente = atendente[i].getqtdePedidos();
             
    }
  
}
 
  return melhorAtendente; 
}


string Mercado::str(){
  
int i, melhorAtendente;
string nomeDoMelhor;

for (i = 0; i < 3; i++) {
    if (i == 0) {
          melhorAtendente = atendente[i].getqtdePedidos();
          nomeDoMelhor ="Programação";
    }
    if (atendente[i].getqtdePedidos() > melhorAtendente) {
        melhorAtendente = atendente[i].getqtdePedidos();
        if (i == 1)
           nomeDoMelhor = "Orientada";
        if (i == 2)
           nomeDoMelhor = "Objetos";  
    }
 
 
}

  return nomeDoMelhor;
}






int Mercado::getEntregadorDoMes(){

  
int i, melhorEntregador;
for (i = 0; i < 3; i++) {
    if (i == 0) {
          melhorEntregador = entregador[i].getqtdePedidosEntregues();
    }
    if (entregador[i].getqtdePedidosEntregues() > melhorEntregador) {
        melhorEntregador = entregador[i].getqtdePedidosEntregues();
             
    }
  
}
 
  return melhorEntregador; 
}


string Mercado::str2(){
  
int i, melhorEntregador;
string nomeDoMelhorEntregador;

for (i = 0; i < 3; i++) {
    if (i == 0) {
          melhorEntregador = entregador[i].getqtdePedidosEntregues();
          nomeDoMelhorEntregador ="Edson";
    }
    if (entregador[i].getqtdePedidosEntregues() > melhorEntregador) {
        melhorEntregador = entregador[i].getqtdePedidosEntregues();
        if (i == 1)
           nomeDoMelhorEntregador = "Ifarraguirre";
        if (i == 2)
           nomeDoMelhorEntregador = "Moreno";  
    }
 
 
}

  return nomeDoMelhorEntregador; 
}


float Mercado::CalculaTempoMedio(){

  float somaTotal = 0;

    for(vector<int>::iterator it=listaDeDemora.begin(); it!=listaDeDemora.end(); it++){
       somaTotal = somaTotal + *it;
      }
 
    float tempomedio = somaTotal / listaDeDemora.size();  
    return tempomedio;

}

int Mercado::calculaOMaisDemorado(){

int a[listaDeDemora.size()];
int i, maior;

    for(vector<int>::iterator it=listaDeDemora.begin(); it!=listaDeDemora.end(); it++){
      
      for (i = 0; i < listaDeDemora.size(); i++){
      a[i] = *it;
      }
      
    for (i = 0; i < listaDeDemora.size(); i++) {
    if (i == 0) {
        a[i] = maior;
    }
    if (a[i] > maior) {
        maior = a[i];
    }
}

    
}
    return maior;  
}
 
 
   


