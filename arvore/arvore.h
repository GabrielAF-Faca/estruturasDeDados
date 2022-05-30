#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct no{
    int dado;
    struct no *esq;
    struct no *dir;
    int fb;
}Arvore;

//   ### PROTÓTIPO DAS FUNÇÕES ###

//ARVORE
Arvore *arvore_inserir(int valor, Arvore *r);
Arvore *arvore_localizar(int valor, Arvore *r);
Arvore *arvore_menor_elemento(Arvore *r);
Arvore *arvore_maior_elemento(Arvore *r);

//INT
int arvore_altura(Arvore *r);
int arvore_contar_folhas(Arvore *r);
int arvore_contar_galhos(Arvore *r);
int arvore_localizar_nivel(int valor, Arvore *r);
int arvore_contar_vezes(int valor, Arvore *r);

//VOID
void arvore_exibir(Arvore *raiz, int nivel = 0);

//   #############################


void arvore_exibir(Arvore *r, int nivel) {
    if (r) {
        //avançar ou empilhar para a direita.... imprimir os maiores valores
        arvore_exibir(r->dir, nivel + 1);

        //imprimir o elemento que estiver na raiz do momento
        int i;
        for (i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << r->dado << "->" << r->fb << endl;


        //avançar ou empilhar para a esquerda.... imprimir os menores valores
        arvore_exibir(r->esq, nivel + 1);
    }
}

Arvore *arvore_menor_elemento(Arvore *r){
    if (!r) return NULL;


    Arvore *p;

    for(p = r; p->esq ; p = p->esq);

    return p;

}

Arvore *arvore_maior_elemento(Arvore *r){
    if (!r) return NULL;

    Arvore *p;

    for(p = r; p->dir ; p = p->dir);

    return p;

}

Arvore *arvore_inserir(int valor, Arvore *r){

    if (r) {
        if(valor < r->dado){
            r->esq = arvore_inserir(valor, r->esq);
        } else {
            r->dir = arvore_inserir(valor, r->dir);
        }

        r->fb = arvore_altura(r->esq) - arvore_altura(r->dir);

        return r;

    } else {
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));

        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        
        return novo;
    }
}

ArvoreString *arvore_inserir_string(string valor, ArvoreString *r){

    if (r) {
        if(valor < r->dado){
            r->esq = arvore_inserir_string(valor, r->esq);
        } else {
            r->dir = arvore_inserir_string(valor, r->dir);
        }

        r->fb = arvoreString_altura(r->esq) - arvoreString_altura(r->dir);

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

int arvore_altura(Arvore *r){
    if(r){
        int altEsq = arvore_altura(r->esq);
        int altDir = arvore_altura(r->dir);

        if (altEsq > altDir) {
            return 1 + altEsq;
        } else {
            return 1 + altDir;
        }
    }
    return 0;
}

int arvoreString_altura(ArvoreString *r){
    if(r){
        int altEsq = arvoreString_altura(r->esq);
        int altDir = arvoreString_altura(r->dir);

        if (altEsq > altDir) {
            return 1 + altEsq;
        } else {
            return 1 + altDir;
        }
    }
    return 0;
}

Arvore *arvore_localizar(int valor, Arvore *r){
    if(r){
        if (r->dado == valor){
            return r;
        }

        if (r->dado < valor){
            return arvore_localizar(valor, r->esq);
        } else {
            return arvore_localizar(valor, r->dir);
        }

    }
    return NULL;
}

int arvore_contar_folhas(Arvore *r){
    if(r){

        if (!r->esq && !r->dir) return 1;
        
        return 0 + arvore_contar_folhas(r->esq) + arvore_contar_folhas(r->dir);

    }
    return 0;
}

int arvore_contar_galhos(Arvore *r){
    if(r){

        if (r->esq || r->dir) 
            return 1 + arvore_contar_galhos(r->esq) + arvore_contar_galhos(r->dir);
        
    }
    return 0;
}

int arvore_localizar_nivel(int valor, Arvore *r){
    if(r){

        if (r->dado == valor) return 0;
        
        if (valor < r->dado) {

            int resultado = arvore_localizar_nivel(valor, r->esq);

            if (resultado == -1) return -1;
            
            return 1 + resultado;

        } else {

            int resultado = arvore_localizar_nivel(valor, r->dir);

            if (resultado == -1) return -1;
            
            return 1 + resultado;

        }

    }
    return -1;
}