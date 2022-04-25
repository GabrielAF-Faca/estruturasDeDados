#include <iostream>
#include <ctime>
#include <locale>
#include "lista.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;

    lista = lista_popular(20, 100, lista);
    lista_exibir(lista);
    
    cout << endl << endl;

    //float media = lista_media_primeiro_ultimo(lista);

    //cout << "Media entre o primeiro e o último elemento da lista: " << media;


    return 1;
}
