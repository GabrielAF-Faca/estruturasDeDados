#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
}Celula;


//PROTOTIPOS DAS FUNCOES
Celula *lista_inserir(int valor, Celula *lista); //OBJETIVO 1
Celula *lista_excluir(int valor, Celula *lista);
Celula *lista_excluir_ocorrencias(int valor, Celula *lista); //OBJETIVO 2
Celula *lista_popular(int num, int max_valor, Celula *lista);
Celula *lista_unir(Celula *lista1, Celula *lista2, Celula *lista); //OBJETIVO 4
Celula *lista_maior(Celula *lista1, Celula *lista2);
Celula *lista_menor(Celula *lista1, Celula *lista2);
Celula *lista_remover_par(Celula *lista);
Celula *lista_inserir_sem_repeticoes(int valor, Celula *lista); // <-- eu fiz esse método para o objetivo 1, depois vi que tinha que alterar o inserir, mas acabei deixando ele

void lista_interseccao_numeros(Celula *lista1, Celula *lista2); //OBJETIVO 3
void lista_interseccao_numeros(Celula *lista1, Celula *lista2);
void lista_exibir(Celula *lista, int break_line = 0);

bool lista_encontrar(int valor, Celula *lista);
bool eh_par(int valor);

int lista_contar(Celula *lista);

float lista_media_primeiro_ultimo(Celula *lista);

//FUNCOES

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

Celula *lista_excluir_ocorrencias(int valor, Celula *lista){
    if(!lista){
        cout << "Lista vazia. Operação cancelada!" << endl;
        return lista;
    }

    int c = 0;

    while(lista_encontrar(valor, lista)){
        c++;
        lista = lista_excluir(valor, lista);

    }

    //OBJETIVO 2
    cout << endl << "Foram excluídos " << c << " elementos da lista!" << endl;

    return lista;

}

void lista_exibir(Celula *lista, int break_line){
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

Celula *lista_popular(int num, int max_valor, Celula *lista){
    srand(time(NULL));

    for (int i = 0; i < num; i++){
        lista = lista_inserir(rand() % max_valor, lista);
    }

    return lista;
}

Celula *lista_inserir_sem_repeticoes(int valor, Celula *lista){
    if (!lista) return lista_inserir(valor, lista);
        if (lista_encontrar(valor, lista)) {
            cout << endl << "Número já contido na lista" << endl;
            return lista;
        }
    return lista_inserir(valor, lista);
}

Celula *lista_unir(Celula *lista1, Celula *lista2, Celula *lista){

    //OBJETIVO 4

    if (!lista1){ 
        cout << "Lista 1 vazia\n";
        return 0;
    }

    if (!lista2){ 
        cout << "Lista 2 vazia\n";
        return 0;
    }

    Celula *p;

    lista = lista1;

    bool parar = false;

    for(p = lista; p ; p = p->prox){
        if(p->prox == NULL && !parar){
            parar = true;
            p->prox = lista2;
        }
    }

    return lista;
}

Celula *lista_maior(Celula *lista1, Celula *lista2){
    if(lista_contar(lista1) > lista_contar(lista2)) return lista1;
    return lista2;
}

Celula *lista_menor(Celula *lista1, Celula *lista2){
    if(lista_contar(lista1) < lista_contar(lista2)) return lista1;
    return lista2;
}

void lista_interseccao_numeros(Celula *lista1, Celula *lista2){

    //OBJETIVO 3

    if (!lista1){ 
        cout << "Lista 1 vazia\n";
        return;
    }

    if (!lista2){ 
        cout << "Lista 2 vazia\n";
        return;
    }

    Celula *p, *p2;

    p = lista_maior(lista1, lista2);
    p2 = lista_menor(lista1, lista2);

    cout << "Números que aparecem em ambas as listas:" << endl;

    while(p){
        int valor = p->dado;
        if (lista_encontrar(valor, p2)){
            cout << "[" << valor << "] ";
        }

        p = p->prox;
    }

}

Celula *lista_remover_par(Celula *lista){
  if (!lista) return 0;

  Celula *p = lista;

  while(p){
      if(eh_par(p->dado)){
          lista = lista_excluir(p->dado, lista);
          p = lista;
      }else{
          p=p->prox;
      }
  }

  cout << endl << endl;
  return lista;
}


bool eh_par(int valor){
  if (valor %2 == 0 || valor == 0){
    return true;
  }
  return false;
}

float lista_media_primeiro_ultimo(Celula *lista){
  if(!lista) return 0;

  Celula *p;
  int num1 = lista->dado;
  int num2;

  for(p = lista; p ; p = p->prox){
    if (p->prox == NULL){
      num2 = p->dado;
      break;
    }
  }

  cout << num1 << endl;
  cout << num2 << endl;
  cout << (num1+num2) << endl;
  cout << (num1+num2)/2 << endl;

  float media = (num1+num2)/2;

  return (float)media;

}