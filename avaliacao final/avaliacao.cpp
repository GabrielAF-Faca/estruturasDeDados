/*
1) A partir de um arquivo txt, com números inteiros, um abaixo do outro, faça um programa em C++ que abra este arquivo e o popule em uma árvore binária 
de pesquisa. Entretanto, o código NÃO deve perrmitir números repetidos. Sugere-se que a árvore esteja balanceada e que se use um arquivo .h 
para os métodos de árvore.

2) A partir do código anterior, faça um método em C++ (métodos de árvore .h) que recebe um ponteiro para uma árvore binária de pesquisa e um valor 
inteiro. Em seguida, o método deve apagar todos os nós folhas que são múltiplos do valor passado no parâmetro.

3) Faça um método que receba um ponteiro para uma árvore binária de pesquisa e um valor inteiro. O método dever retornar o endereço físico desse valor,
caso contrário, deve retornar NULL (indicando que o valor não foi localizado)
*/

#include <iostream>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>
#include <ctime> 

#include "arvore.h"

using namespace std;
//###PROTÓTIPOS###

//ARVORE
Arvore *arvore_popular(Arvore *r);

//VOID
void gerar_numeros(int intervalo, int quantidade);


//################

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    gerar_numeros(10, 5);

    Arvore *raiz = NULL;
    
    raiz = arvore_popular(raiz);


    // raiz = arvore_inserir_sem_repetir(9, raiz);
    // raiz = arvore_inserir_sem_repetir(10, raiz);
    // raiz = arvore_inserir_sem_repetir(4, raiz);
    // raiz = arvore_inserir_sem_repetir(5, raiz);
    // raiz = arvore_inserir_sem_repetir(20, raiz);

    cout << endl;


    arvore_exibir(raiz);

    cout << endl;

    int valor;

/*
    cout << "Informe um número para deletar as folhas cujo valor é múltiplo desse: ";
    cin >> valor;

    arvore_excluir_multiplos_folhas(valor, raiz);

    cout << endl;

    arvore_exibir(raiz);
*/
    cout << "Informe um número para verificar o endereço de memória (caso o valor exista) do galho: ";
    cin >> valor;

    cout << "O endereço de memória do galho: " << arvore_localizar(valor, raiz);

    return 1;
}

Arvore *arvore_popular(Arvore *r) {
    FILE *procurador;
    int valor;

    procurador = fopen("./numeros.txt", "r");

    do {		
		fscanf(procurador,"%d",&valor);

        cout << "Valor lido: " << valor << endl;

        r = arvore_inserir_sem_repetir(valor, r);
		
	} while (!feof(procurador));

    fclose(procurador);

    return r;
}

void gerar_numeros(int intervalo, int quantidade) {

    ofstream file("./numeros.txt");

    srand((unsigned)time(0));

    for(int i = 0; i < quantidade; i++){
        file << (rand()%intervalo)+1;

        if(i+1 != quantidade)
            file << endl;
    }

    file.close();

}