/*Fa√ßa um programa que imprima os 100 primeiros inteiros positvos pares.*/
#include <stdio.h>
#include <locale.h>

#define NUMERO_OBJETIVO 100

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int contagem=0;
    while(contagem<NUMERO_OBJETIVO){
        contagem++;
        if(!(contagem%2)){
            printf("%d È um n˙mero par.\n", contagem);
        }
    }
    return 0;
}