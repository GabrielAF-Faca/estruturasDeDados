#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*OBJETIVO: fazer um programa em C ou C++ que leia um arquivo com 
  N números inteiros, um abaixo do outro, e os popule em uma pilha encadeada
  dinamicamente. Ao final, exiba quantos elementos há na pilha e seu topo.
*/

typedef struct no {
	int dado;
	struct no *prox;
}Celula;

Celula *inserir(int valor, Celula *pilha);

void generateFile(char nomeArquivo[200]);
void exibirElementos(Celula *pilha);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Celula *pilha = NULL;
	
	char nomeArquivo[200];
	FILE *procurador;
	
	int valor;
	
	printf("Insira o nome do arquivo a ser analizado: ");
	scanf("%s", &nomeArquivo);
	
	procurador = fopen(nomeArquivo, "r");
	
	if(!procurador){
		printf("\nArquivo não encontrado. Criando arquivo...\n\n");
		
		generateFile(nomeArquivo);
		procurador = fopen(nomeArquivo, "r");
	}
	
	do {		
		fscanf(procurador,"%d",&valor);
		pilha = inserir(valor,pilha);
		
	} while (!feof(procurador));
	
	printf("O elemento do topo da pilha é: %d\n", pilha->dado);
	printf("A pilha possui %d elementos (contando linhas vazias)\n",getStackSize(pilha));
	exibirElementos(pilha);
	
	fclose(procurador);
	
	return EXIT_SUCCESS;
}

Celula *inserir(int valor, Celula *pilha){
	Celula *novo = (Celula *)malloc(sizeof(Celula));
	
	novo->dado = valor;
	novo->prox = pilha;
	
	return novo;
	
}

int getStackSize(Celula *pilha){
	Celula *p;
	
	int tamanho = 0;
	
	for (p = pilha; p ; p = p->prox){
		tamanho++;
	}
	
	return tamanho;
}

void exibirElementos(Celula *pilha){
	printf("Elementos da pilha:\n");
	
	Celula *p;
	for(p = pilha; p ; p = p->prox){
		printf("[%d]", p->dado);
	}
	
	printf("\n");
}

void generateFile(char nomeArquivo[200]){
	int numInteiros;
	
	printf("Informe o número de números inteiros que deseja: ");
	scanf("%d", &numInteiros);
	
	FILE *arquivo = fopen(nomeArquivo, "w");
	
	int i = 0;
	
	srand(time(NULL));
	
	for(i = 0; i < numInteiros; i++){
		fprintf(arquivo, "%d", 100-rand()%200);
		if(i < numInteiros-1)
			fprintf(arquivo, "%s", "\n");
		fflush(arquivo);
	}
	
	fclose(arquivo);	
}
