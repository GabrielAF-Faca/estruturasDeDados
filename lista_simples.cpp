#include <iostream>
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

    cout << "A lista contém " << contar(lista) << " elementos\n";

    return 1;
}

Celula *inserir(int valor, Celula *lista){
    //alocar memória

    //depositar valor

    //localizar posição de inserção

    //"engatar"

    //retornar o início da lista
}

void exibir_lista(Celula *lista){

}

int contar(Celula *lista){

}