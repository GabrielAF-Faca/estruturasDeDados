#include <iostream>
#include <ctime>
#include <locale>
#include "lista.h"

using namespace std;

Celula *lista_popular(int num, Celula *lista){
    srand(time(NULL));

    for (int i = 0; i < num; i++){
        lista = lista_inserir(rand() % 100, lista);
    }

    return lista;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;

    lista = lista_popular(20, lista);

    cout << endl;
    lista_exibir(lista);
    cout << endl << "A lista possui " << lista_contar(lista) << " elementos.";

    cout << endl << endl << "Informe o número a ser tirado da lista: ";

    int valor;
    cin >> valor;

    lista = lista_excluir_todos(valor, lista);

    cout << endl;
    lista_exibir(lista);
    cout << endl << "A lista agora possui " << lista_contar(lista) << " elementos.";
    
    return 1;
}
