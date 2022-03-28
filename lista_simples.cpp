#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

Celula *inserir(int valor, Celula *lista);
void exibir_lista(Celula *lista);
int contar(Celula *lista);


int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;

    lista = inserir(2, lista);
    lista = inserir(1, lista);
    lista = inserir(10, lista);
    lista = inserir(4, lista);

    exibir_lista(lista);

    cout << "\n\nA lista cont�m " << contar(lista) << " elementos" << endl;

    return 1;
}

Celula *inserir(int valor, Celula *lista){
    Celula *novo, *p, *pR;
    
    //alocar mem�ria
    novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valor
    novo->dado = valor;
    novo->prox = NULL;

    //testar se � primeira vez
    if (!lista) return novo;

    //localizar posi��o de inser��o
    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado){
            break;
        }
    }

    //"engatar"

    if (p == lista){
        //testar se no in�cio
        novo->prox = lista;
        return novo;
    }else if (!p){
        //testar se no fim
        pR->prox = novo;
    }else{
       pR->prox = novo;
       novo->prox = p;  
    }

    //retornar o in�cio da lista
    return lista;
}

void exibir_lista(Celula *lista){
    if (!lista){ 
        cout << "Lista vazia\n";
        return;
    }

    Celula *p;

    for (p = lista; p ; p = p->prox){
        cout << "[" << p->dado << "] ";
    }

}


int contar(Celula *lista){
    if (!lista){ 
        cout << "Lista vazia\n";
        return 0;
    }

    Celula *p;
    int contador = 0;

    for (p = lista; p ; p = p->prox){
        contador++;
    }

    return contador;
}
