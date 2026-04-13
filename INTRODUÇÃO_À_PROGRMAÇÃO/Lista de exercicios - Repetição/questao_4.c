/*Faça um programa que imprima todos os números múltiplos de 5, no intervalo fechado de 1 a 500.*/

#include <stdio.h>
#include <locale.h>

#define NUMERO_MAX 500

int main(){
    setlocale(LC_ALL, "");
    printf("-> Números de 1 a 500 múltiplos de 5:\n");

    int contagem = 0;
    while(contagem<NUMERO_MAX){
        contagem++;
        if(!(contagem % 5)){
            printf("-> %d\n", contagem);
        }
    }
    return 0;
}