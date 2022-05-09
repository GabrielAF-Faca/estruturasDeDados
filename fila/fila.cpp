// Fila é uma ED Abstrata como lista e pilha 
//     - Possui somente duas operações como pilha:
//         Inserir na fim ou na cauda (tail)
//         Remover da início ou da cabeça (head)

//     - Mecanismos de prioridade FIFO (First In, Firt Out)
//     - Para isso são utilizados dois ponteiros (DEQUE)
//         - ponteiro para inicio -> onde ocorrem as remoções
//         - ponteiro para fim -> onde ocorrem as inserções

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct no {
    string ficha;
    struct no *prox;
} Celula; //struct clássico de pilha e lista simples

typedef struct {
    Celula *inicio;
    Celula *fim;
} Fila;

Fila inicializar(Fila f) {
    f.inicio = NULL;
    f.fim = NULL;
    return f;
}

void inicializar2(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

Fila inserir(string ficha, Fila f) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->ficha = ficha;
    novo->prox = NULL;

    //engatar no fim
    if (!f.fim) {
        f.inicio = novo;
        f.fim = novo;
    } else {
        f.fim->prox = novo;
        f.fim = novo;
    }
    return f;
}

void inserir2(string ficha, Fila *f) {
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

int main() {
   
    Fila fila1;
    Fila fila2;

    fila1 = inicializar(fila1);
    inicializar2(&fila2);

    fila1 = inserir("p10", fila1);
    fila1 = inserir("p11", fila1);
    fila1 = inserir("p12", fila1);

    fila_exibir(fila1, "Fila 1:");

    inserir2("p100", &fila2);
    inserir2("p110", &fila2);
    inserir2("p120", &fila2);

    fila_exibir(fila2, "Fila 2:");

    cout << endl << "Chamando ficha: [" << fila_remover(&fila1) << "]" << endl;
    fila_exibir(fila1, "Fila 1:");

    return 1;
}