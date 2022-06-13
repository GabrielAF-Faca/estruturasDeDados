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
Arvore *arvore_rodar_esquerda(Arvore *r);
Arvore *arvore_rodar_direita(Arvore *r);
Arvore *arvore_balancear(Arvore *r);
Arvore *arvore_excluir(int valor, Arvore *raiz);

//INT
int arvore_altura(Arvore *r);
int arvore_contar_folhas(Arvore *r);
int arvore_contar_galhos(Arvore *r);
int arvore_localizar_nivel(int valor, Arvore *r);
int arvore_contar_vezes(int valor, Arvore *r);

//VOID
void arvore_exibir(Arvore *raiz, int nivel = 0);
void arvore_atualizar_fb(Arvore *raiz);
//   #############################



void arvore_atualizar_fb(Arvore *raiz) {

    if (raiz) {

        arvore_atualizar_fb(raiz->esq);
        arvore_atualizar_fb(raiz->dir);

        raiz->fb = arvore_altura(raiz->esq) - arvore_altura(raiz->dir);

    }

}


Arvore *arvore_rodar_esquerda(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->dir;
    tmp = filho->esq;
    r = filho;
    filho->esq = pai;
    pai->dir = tmp;
    return r;
}

Arvore *arvore_rodar_direita(Arvore *r) {
    Arvore *filho, *pai, *tmp;
    pai = r;
    filho = pai->esq;
    tmp = filho->dir;
    r = filho;
    filho->dir = pai;
    pai->esq = tmp;
    return r;
}

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

Arvore *arvore_balancear(Arvore *r){

    if (r) {

        if (r->fb == -2) {

            if (r->fb < 0 && r->dir->fb < 0) {

                r = arvore_rodar_esquerda(r);
            
            } else {

                r->dir = arvore_rodar_direita(r->dir);

                r = arvore_rodar_esquerda(r);

            }

            arvore_atualizar_fb(r);

        } else if (r->fb == 2) {

            if (r->fb < 0 && r->esq->fb > 0) {

                r = arvore_rodar_direita(r);
            
            } else {

                r->esq = arvore_rodar_esquerda(r->esq);

                r = arvore_rodar_direita(r);

            }

            arvore_atualizar_fb(r);

        }
        
        
    }
    
    return(r);
}


Arvore *arvore_excluir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->dado) { //valor localizado e pronto pra exclus�o
            //eh folha
            if (!raiz->esq && !raiz->dir) {
                free(raiz);
                return NULL;
            } else {
                Arvore *novoPai;
                Arvore *p;

                if (raiz->esq) novoPai = raiz->esq;
                else novoPai = raiz->dir;
                
                for (p = novoPai; p->dir; p = p->dir);

                p->dir = raiz->dir;

                novoPai->dir = p->dir;

                free(raiz);

                return novoPai;
            }
        } else {
            if (valor < raiz->dado) { //avancar para esquerda
                raiz->esq = arvore_excluir(valor, raiz->esq);
            } else { //avancar para direita
                raiz->dir = arvore_excluir(valor, raiz->dir);
            }
        }

        arvore_atualizar_fb(raiz);
        raiz = arvore_balancear(raiz);

        return raiz;
    }
    return NULL;
}

Arvore *arvore_inserir(int valor, Arvore *r){

    if (r) {
        if(valor < r->dado){
            r->esq = arvore_inserir(valor, r->esq);
        } else {
            r->dir = arvore_inserir(valor, r->dir);
        }

        arvore_atualizar_fb(r);

        r = arvore_balancear(r);

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