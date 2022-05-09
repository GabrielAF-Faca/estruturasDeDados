#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct no {
    string ficha;
    struct no *prox;
} Celula; 

typedef struct {
    Celula *inicio;
    Celula *fim;
} Fila;


void fila_inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}


void fila_inserir(string ficha, Fila *f) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->ficha = ficha;
    novo->prox = NULL;

    //engatar no fim
    if (!f->fim) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void fila_exibir(Fila fila, string frase = ""){
    Celula *p;

    if (frase != "")
        cout << endl << frase << endl;

    for(p = fila.inicio; p; p = p->prox){
        cout << "[" << p->ficha << "] ";
    }

    cout << endl;
}

string fila_remover(Fila *f){
    if(!f->inicio){
        return "-27";
    }

    string fichaAtendimento;
    Celula *lixo;

    fichaAtendimento = f->inicio->ficha;
    lixo = f->inicio;

    f->inicio = f->inicio->prox;
    free(lixo);

    return fichaAtendimento;
}