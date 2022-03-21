#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
	int dado;
	struct no *prox;
} Celula;



Celula *inserir(int valor,Celula *topo);
Celula *remover(Celula *topo);


void exibirElementos(Celula *topo);
void showStackElements(Celula *topo);


int getStackSize(Celula *pilha);
int getStackElement(int valor, Celula *pilha);



int main(void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Celula *pilha1 = NULL;
	
	pilha1 = inserir(15, pilha1);
	pilha1 = inserir(10, pilha1);
	pilha1 = inserir(5, pilha1);
	pilha1 = inserir(25, pilha1);
	pilha1 = inserir(100, pilha1);
	
	showStackElements(pilha1);

	exibirElementos(pilha1);
	
	getStackElement(25, pilha1);
	
	
	return EXIT_SUCCESS;
}

int getStackElement(int valor, Celula *pilha){
	Celula *p;
	
	if (!pilha) return 0;
	
	for (p = pilha; p ; p = p->prox){
		if (valor == p->dado){
			printf("\nO número %d %s está na pilha!",valor, (getStackElement(valor, pilha)?"":"não"));
			return 1;
		}
	}
	
	return 0;
	
}

void showStackElements(Celula *topo){
	printf("Edereço do último elemento: %p\n", topo);
	printf("Valor do último elemento: %d\n", topo->dado);
	printf("Edereço do próximo elemento: %p\n", topo->prox);
	
	printf("\nTamanho da pilha: %d\n", getStackSize(topo));
}


void exibirElementos(Celula *topo){
	Celula *p;
	for(p = topo; p ;p = p->prox){
		printf("[%d] ", p->dado);
	}
	
	printf("\n");
}


int getStackSize(Celula *pilha){
	int size = 0;
	
	Celula *p;
	
	for (p = pilha; p ; p = p->prox){
		size++;
	}
	
	return size;
}


Celula *remover(Celula *topo){
	if (!topo){
		printf("\n\nPilha vazia!! Operação cancelada...\n\n");
		return topo;
	}
	
	Celula *lixo = topo;

	topo = topo->prox;

	free(lixo);

	return topo;
}


Celula *inserir(int valor,Celula *topo){
	Celula *novo = (Celula *)malloc(sizeof(Celula));
	
	novo->dado = valor;

	novo->prox = topo;
	
	return novo;
}
