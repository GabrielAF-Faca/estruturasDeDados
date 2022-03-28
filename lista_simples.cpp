#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

int main(){
    
    Celula *lista = NULL;

    lista = inserir(2, lista);
    lista = inserir(1, lista);
    lista = inserir(10, lista);
    lista = inserir(4, lista);

    exibir_lista(lista);

    cout << "A lista cont�m " << contar(lista) << " elementos\n";

    return 1;
}

Celula *inserir(int valor, Celula *lista){
    Celula *novo, *p, *pR;
    
    //alocar mem�ria
    novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valor
    novo->dado = valor;
    novo->prox = NULL;

    //testar se � primeira vez
    if (!lista) return novo;

    //localizar posi��o de inser��o
    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado){
            break;
        }
    }

    //"engatar"

    if (p == lista){
        //testar se no in�cio
        novo->prox = lista;
        return novo;
    }else if (!p){
        //testar se no fim
        pR->prox = novo;
    }else{
       pR->prox = novo;
       novo->prox = p;  
    }

    //retornar o in�cio da lista
    return lista;
}

void exibir_lista(Celula *lista){

}

int contar(Celula *lista){

}