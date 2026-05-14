// Crie uma função que calcule o comprimento de uma string.

#include <stdio.h>
#include <string.h>
#include "mylib.h"
#define TAMANHO 101

int verificarTamanho(char str[]){
    int tamanho=0, i=0;
    while(str[i]!='\0'){
        tamanho++;
        i++;
    }
    return tamanho;
}

int main(){
    char str[TAMANHO];
    int tamanho;

    printf("Escreva um texto para saber quantos caracteres ele tem. (MAX de %d caracteres)\n> ", TAMANHO - 1);
    lerString(str, TAMANHO);

    tamanho = verificarTamanho(str);

    printf("\nO texto possuí %d caracteres.\n\n", tamanho);
}