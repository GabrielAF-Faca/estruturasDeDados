#include <iostream>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>
#include <ctime> 

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    ofstream file("./numeros.txt");

    srand((unsigned)time(0));

    while(true){
        file << (rand()%100)+1;
        file << endl;
    }

    file.close();

    return 1;
}