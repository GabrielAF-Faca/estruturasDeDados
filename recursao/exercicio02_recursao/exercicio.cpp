#include <iostream>
#include <ctime>
#include <locale>
#include "lista.h"

using namespace std;

int lista_contar_nos_recursivo(Celula *lista){
    if (lista){
        return 1 + lista_contar_nos_recursivo(lista->prox);
    }
    return 0;
}

int lista_somar_nos_recursivo(Celula *lista){
    if (lista){
        return lista->dado + lista_somar_nos_recursivo(lista->prox);
    }
    return 0;
}

int lista_contar_pares_recursivo(Celula *lista){
    if (lista){
        if (lista->dado %2 == 0 || lista->dado == 0){
            return 1 + lista_contar_pares_recursivo(lista->prox);
        }else{
            return 0+ lista_contar_pares_recursivo(lista->prox);
        }
    }
    return 0;
}

int lista_somar_pares_recursivo(Celula *lista){
    if (lista){
        if (lista->dado %2 == 0 || lista->dado == 0){
            return lista->dado + lista_somar_pares_recursivo(lista->prox);
        }else{
            return 0 + lista_somar_pares_recursivo(lista->prox);
        }
    }
    return 0;
}

void lista_exibir_pares_recursivo(Celula *lista){
    if (lista){
        if (lista->dado %2 == 0 || lista->dado == 0){
            cout << "[" << lista->dado << "] ";
            lista_exibir_pares_recursivo(lista->prox);
        }else{
            lista_exibir_pares_recursivo(lista->prox);
        }
    }
    return;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;

    lista = lista_popular(20, 100, lista);
    lista_exibir(lista);

    cout << endl << endl << lista_contar_pares_recursivo(lista) << endl;

    cout << endl << lista_somar_pares_recursivo(lista) << endl << endl;

    lista_exibir_pares_recursivo(lista);
    

    return 1;
}
