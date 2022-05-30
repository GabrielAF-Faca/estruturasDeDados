#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct noString{
    string dado;
    struct noString *esq;
    struct noString *dir;
    int fb;
}ArvoreString;

//   ### PROTÓTIPO DAS FUNÇÕES ###

//ARVORESTRING
ArvoreString *arvore_string_inserir(string valor, ArvoreString *r);
ArvoreString *arvore_string_menor_elemento(ArvoreString *r);
ArvoreString *arvore_string_maior_elemento(ArvoreString *r);

//INT
int arvore_string_altura(ArvoreString *r);

//VOID
void arvore_string_exibir(ArvoreString *raiz, int nivel = 0);

//   #############################


void arvore_string_exibir(ArvoreString *r, int nivel) {
    if (r) {
        //avançar ou empilhar para a direita.... imprimir os maiores valores
        arvore_string_exibir(r->dir, nivel + 1);

        //imprimir o elemento que estiver na raiz do momento
        int i;
        for (i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << r->dado << "->" << r->fb << endl;


        //avançar ou empilhar para a esquerda.... imprimir os menores valores
        arvore_string_exibir(r->esq, nivel + 1);
    }
}

ArvoreString *arvore_string_menor_elemento(ArvoreString *r){
    if (!r) return NULL;


    ArvoreString *p;

    for(p = r; p->esq ; p = p->esq);

    return p;

}

ArvoreString *arvore_string_maior_elemento(ArvoreString *r){
    if (!r) return NULL;

    ArvoreString *p;

    for(p = r; p->dir ; p = p->dir);

    return p;

}

ArvoreString *arvore_string_inserir(string valor, ArvoreString *r){

    if (r) {
        if(valor < r->dado){
            r->esq = arvore_string_inserir(valor, r->esq);
        } else {
            r->dir = arvore_string_inserir(valor, r->dir);
        }

        r->fb = arvore_string_altura(r->esq) - arvore_string_altura(r->dir);

        return r;

    } else {
        ArvoreString *novo = (ArvoreString *)malloc(sizeof(ArvoreString));

        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        
        return novo;
    }
}


int arvore_string_altura(ArvoreString *r){
    if(r){
        int altEsq = arvore_string_altura(r->esq);
        int altDir = arvore_string_altura(r->dir);

        if (altEsq > altDir) {
            return 1 + altEsq;
        } else {
            return 1 + altDir;
        }
    }
    return 0;
}
