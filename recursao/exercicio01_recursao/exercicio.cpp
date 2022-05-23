#include <iostream>
#include <ctime>
#include <locale>
#include "lista.h"

using namespace std;


Celula *lista_excluir_recursivo(int valor, Celula *lista) {
    if (lista) {
        if (lista->dado == valor){
            Celula *oRetorno = lista->prox;
            free(lista);
            return oRetorno;
        } else {
            lista->prox = lista_excluir_recursivo(valor, lista->prox);
        }
    } 
    return lista;        
}


Celula *inserirListaR(int valor, Celula *lista) {
    if (lista && valor > lista->dado) {
        lista->prox = inserirListaR(valor, lista->prox);
        return lista;
    } else {
        //alocar memoria
        Celula *novo = (Celula*)malloc(sizeof(Celula));

        //depositar valores
        novo->dado = valor;
        novo->prox = NULL;
        return novo;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;

    lista = lista_popular(20, 100, lista);
    lista_exibir(lista);
    
    cout << endl << endl;

    int val = 0;

    cin >> val;

    lista = lista_excluir_recursivo(val, lista);

    cout << endl << endl;

    lista_exibir(lista);

    return 1;
}
