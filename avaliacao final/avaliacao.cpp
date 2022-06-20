/*
1) A partir de um arquivo txt, com n�meros inteiros, um abaixo do outro, fa�a um programa em C++ que abra este arquivo e o popule em uma �rvore bin�ria 
de pesquisa. Entretanto, o c�digo N�O deve perrmitir n�meros repetidos. Sugere-se que a �rvore esteja balanceada e que se use um arquivo .h 
para os m�todos de �rvore.

2) A partir do c�digo anterior, fa�a um m�todo em C++ (m�todos de �rvore .h) que recebe um ponteiro para uma �rvore bin�ria de pesquisa e um valor 
inteiro. Em seguida, o m�todo deve apagar todos os n�s folhas que s�o m�ltiplos do valor passado no par�metro.

3) Fa�a um m�todo que receba um ponteiro para uma �rvore bin�ria de pesquisa e um valor inteiro. O m�todo dever retornar o endere�o f�sico desse valor,
caso contr�rio, deve retornar NULL (indicando que o valor n�o foi localizado)
*/

#include <iostream>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>
#include <ctime> 

#include "arvore.h"

using namespace std;
//###PROT�TIPOS###

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
    cout << "Informe um n�mero para deletar as folhas cujo valor � m�ltiplo desse: ";
    cin >> valor;

    arvore_excluir_multiplos_folhas(valor, raiz);

    cout << endl;

    arvore_exibir(raiz);
*/
    cout << "Informe um n�mero para verificar o endere�o de mem�ria (caso o valor exista) do galho: ";
    cin >> valor;

    cout << "O endere�o de mem�ria do galho: " << arvore_localizar(valor, raiz);

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