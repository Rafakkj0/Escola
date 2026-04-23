/*Faça um programa que imprima todos os números inteiros de 200 a 100 (em ordem decrescente).*/

#include <stdio.h>
#include <locale.h>

#define NUMERO_OBJETIVO 100
#define NUMERO_INICIAL 200

int main(){
    setlocale(LC_ALL, "");
    int contagem = NUMERO_INICIAL;
    while (contagem>=NUMERO_OBJETIVO){
        printf("%d\n",contagem);
        contagem--;
    }
    return 0;
}