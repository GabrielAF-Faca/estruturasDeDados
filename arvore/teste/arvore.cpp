#include <iostream>
#include <ctime>
#include <locale>
#include "../arvore.h"


using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Arvore *raiz = NULL;


    raiz = arvore_inserir(40, raiz);
    raiz = arvore_inserir(20, raiz);
    raiz = arvore_inserir(70, raiz);
    raiz = arvore_inserir(25, raiz);
    raiz = arvore_inserir(50, raiz);
    raiz = arvore_inserir(100, raiz);
    raiz = arvore_inserir(24, raiz);

    cout << endl << endl;

    arvore_exibir(raiz);
    
    cout << endl << endl;

    cout << "A arvore possui altura: " << arvore_altura(raiz) << endl;
    cout << "A arvore possui " << arvore_contar_galhos(raiz) << " galhos" << endl;
    cout << "A arvore possui " << arvore_contar_folhas(raiz) << " folhas" << endl;

    int teste = 20;

    cout << "O numero " << teste << " esta no nivel " << arvore_localizar_nivel(teste, raiz) << endl;

    cout << "O menor numero da arvore e: " << arvore_menor_elemento(raiz)->dado << endl;
    cout << "O maior numero da arvore e: " << arvore_maior_elemento(raiz)->dado << endl;


    return 1;
}
