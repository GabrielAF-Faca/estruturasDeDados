#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

Celula *lista_inserir(int valor, Celula *lista){
    Celula *novo, *p, *pR;
    
    //alocar memória
    novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valor
    novo->dado = valor;
    novo->prox = NULL;

    //testar se é primeira vez
    if (!lista) return novo;

    //localizar posição de inserção
    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado){
            break;
        }
    }

    //"engatar"

    if (p == lista){
        //testar se no início
        novo->prox = lista;
        return novo;
    }else if (!p){
        //testar se no fim
        pR->prox = novo;
    }else{
       pR->prox = novo;
       novo->prox = p;  
    }

    //retornar o início da lista
    return lista;
}

bool lista_encontrar(int valor, Celula *lista){
  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return false;
  }

  Celula *p;

  for (p = lista; p; p = p->prox) {
    if (valor == p->dado) {
      return true;
    }
  }

  return false;
  
}

Celula *lista_excluir(int valor, Celula *lista) {
  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  Celula *p, *pR;

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->dado) {
      //eh o primeiro
      if (p == lista) {
        lista = lista->prox;
      } else if (!p->prox) { //eh o ultimo
        pR->prox = NULL;
      } else { //esta entre celulas
        pR->prox = p->prox;
      }
      free(p);
      return lista;
    }
  }
  cout << "Valor não localizado para exclusão!" << endl;
  return lista;
}

Celula *lista_excluir_todos(int valor, Celula *lista){
  if(!lista){
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  while(lista_encontrar(valor, lista)){
    
    lista = lista_excluir(valor, lista);

  }

  return lista;

}

void lista_exibir(Celula *lista, int break_line = 0){
  if (!lista){ 
      cout << "Lista vazia\n";
      return;
  }

  Celula *p;

  for (p = lista; p ; p = p->prox){
      cout << "[" << p->dado << "] " << ((break_line != 0) ? "\n" : "");
  }

}

int lista_contar(Celula *lista){
  if (!lista){ 
      cout << "Lista vazia\n";
      return 0;
  }

  Celula *p;
  int contador = 0;

  for (p = lista; p ; p = p->prox){
      contador++;
  }

  return contador;
}

Celula *lista_podar(Celula *lista){
  if (!lista){
    cout << "Lista vazia\n";
    return 0;
  }
}