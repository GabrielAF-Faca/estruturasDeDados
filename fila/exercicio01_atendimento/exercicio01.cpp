#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>

#include "estrutura.h"

using namespace std;


/*
Sistema de atendimento baseado em fichas normais e de prioridades

Menu
1 - Retirar ficha normal
2 - Retirar ficha priorit�ria
3 - Atender
4 - Mostar filas
5 - Sair
Op��o: 

As fichas normais s�o n�meros de 100 a 500, com a letra n na frente, por exemplo, n100.

As fichas priorit�rias s�o n�meros de 1000 a 1500, com a letra p na frente, p1000.

S�o necess�rios 3 contadores:
 contaFichaNormal = 100;
 contaFichaPrioritaria = 1000;
 contaAtendimentos = 0;

Toda vez que uma ficha � retirada, informar o n�mero da ficha. Para cada 3 contaAtendimentos
normais, realizar um atendimento priorit�rio (contaAtendimentos).
*/

int main() {
   
    setlocale(LC_ALL, "Portuguese");

    bool rodando = true;
    Fila fila;

    fila_inicializar(&fila);

    int contaFichaNormal = 100;
    int contaFichaPrioritaria = 1000;
    int contaAtendimentos = 0;
    int contadorAtendimentos = 0;

    while(rodando){
        int opcao;
        cout << "Sistema de atendimento" << endl;
        cout << "1 - Retirar ficha normal" << endl;
        cout << "2 - Retirar ficha preferencial" << endl;
        cout << "3 - Atender cliente" << endl;
        cout << "4 - Mostrar fila" << endl;
        cout << "5 - Sair" << endl;

        cout << "Informe a opera��o: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                fila_inserir("n"+contaFichaNormal, &fila);
                break;
            
            case 2:
                break;

            case 3:
                break;

            case 4:
                fila_exibir(fila);
                break;

            case 5:
                rodando = false;
                break;

            default:
                cout << endl << "Opera��o inv�lida" << endl << endl;
        }
    }

    cout << endl << "Desligando...";

    return 1;
}