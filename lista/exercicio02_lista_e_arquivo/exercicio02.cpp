#include <iostream>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>

using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
}Celula;


Celula *lista_inserir(int valor, Celula *lista);
Celula *pilha_inserir(int valor, Celula *pilha);


void exibir(Celula *lista);
void popular_do_arquivo(Celula **lista, Celula **pilha);


int contarElementos(Celula *estrutura);
int menorValorLista(Celula *lista);
int maiorValorLista(Celula *lista);
int calcular_moda(Celula *estrutura, int ignore = 0);


float calcular_mediana(Celula *estrutura);
float calcularMedia(Celula *estrutura);


int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Celula *lista = NULL;
    Celula *pilha = NULL;

    popular_do_arquivo(&lista, &pilha);

    exibir(lista);
    printf("\n");
    exibir(pilha);

    cout << "Número de elementos na lista: " << contarElementos(lista) << endl;
    cout << "Número de elementos na pilha: " << contarElementos(pilha) << endl;

    cout << endl << "Média dos elementos da lista: " << calcularMedia(lista) << endl;
    cout << "Média dos elementos da pilha: " << calcularMedia(pilha) << endl;

    cout << "Mediana dos elementos da lista: " << calcular_mediana(lista) << endl;
    cout << endl << "Maior valor da lista: " << maiorValorLista(lista) << endl;

    int moda = calcular_moda(lista);

    cout << endl << "Números que mais repetem na lista: " << moda << " e " << calcular_moda(lista, moda) << endl;



    return 1;
}

Celula *lista_inserir(int valor, Celula *lista){
    Celula *novo, *p, *pR;
    
    //alocar memóia
    novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valor
    novo->dado = valor;
    novo->prox = NULL;

    //testar se é a primeira vez
    if (!lista) return novo;

    //localizar posição de inserção
    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado){
            break;
        }
    }

    //"engatar"

    if (p == lista){
        //testar se no início
        novo->prox = lista;
        return novo;
    }else if (!p){
        //testar se no fim
        pR->prox = novo;
    }else{
       pR->prox = novo;
       novo->prox = p;  
    }

    //retornar o início da lista
    return lista;
}


void exibir_lista(Celula *lista){
    if (!lista){ 
        cout << "Lista vazia\n";
        return;
    }

    Celula *p;

    for (p = lista; p ; p = p->prox){
        cout << "[" << p->dado << "]\n";
    }

}

Celula *pilha_inserir(int valor, Celula *pilha){
    Celula *novo = (Celula *)malloc(sizeof(Celula));
	
	novo->dado = valor;

	novo->prox = pilha;
	
	return novo;
}


void exibir(Celula *lista){
    if (!lista){ 
        cout << "Lista vazia\n";
        return;
    }

    Celula *p;

    for (p = lista; p ; p = p->prox){
        cout << "[" << p->dado << "]\n";
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


void popular_do_arquivo(Celula **lista, Celula **pilha){
    ifstream procurador;
    char nome_arquivo[200];

    cout << "Informe o local do arquivo: ";
    cin >> nome_arquivo;

    procurador.open(nome_arquivo);

    if (!procurador){
        cout << "Arquivo não encontrado";
        exit(0);
    }

    string linha; 
    int posicao_espaco = 0;

    while(getline(procurador, linha)){
        posicao_espaco = linha.find(" ");
        string glicemia = linha.substr(0, posicao_espaco);

        *lista = lista_inserir(stoi(glicemia), *lista);
        *pilha = pilha_inserir(stoi(glicemia), *pilha);
    }

    procurador.close();
}

int contarElementos(Celula *estrutura){
    if (!estrutura) return 0;

    Celula *p;
    int contador = 0;

    for(p = estrutura; p ; p = p->prox){
        contador++;
    }

    return contador;
}

float calcularMedia(Celula *estrutura){
    if (!estrutura) return 0;

    Celula *p;
    float media = 0;

    for(p = estrutura; p ; p = p->prox){
        media+=p->dado;
    }

    return media/contarElementos(estrutura);
}

float calcular_mediana(Celula *estrutura){
    if(!estrutura) return 0;

    int qtd_elementos = contarElementos(estrutura);

    Celula *p = estrutura;
    int metade;

    bool ehPar = qtd_elementos % 2 == 0;

    if (ehPar) {
        metade = (qtd_elementos/2) - 1;
    } else {
        metade = (int)qtd_elementos/2;
    }

    cout << ehPar << endl;
    cout << metade << endl;

    for(int i = 0; i < metade; i++){
        p = p->prox;
    }

    cout << p->dado << endl;
    cout << p->prox->dado << endl;

    return (ehPar)?((p->dado + p->prox->dado)/2):(p->dado);

}

int menorValorLista(Celula *lista){
    if (!lista) return 0;

    return lista->dado;

}

int maiorValorLista(Celula *lista){
    if (!lista) return 0;

    Celula *p;
    
    int valor;

    for (p = lista; p ; p = p->prox){
        valor = p->dado;
    }

    return valor;

}

int calcular_moda(Celula *estrutura, int ignore){
    if (!estrutura) return 0;

    Celula *p;

    int moda;
    int count = 1;
    int countMode = 1;
    int number = estrutura->dado;

    moda = number;
    
    for(p = estrutura->prox; p ; p = p->prox){
        if (p->dado == number && number!=ignore){
            ++count;
        }else{
            if (count > countMode){
                countMode = count;
                moda = number;
            }

            count = 1;
            number = p->dado;
        }
    }

    return moda;
}