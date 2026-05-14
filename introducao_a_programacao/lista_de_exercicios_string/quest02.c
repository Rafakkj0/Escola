// Implemente uma função que transforme todos os caracteres de uma string para minúsculos

#include <stdio.h>
#include <ctype.h>
#include "mylib.h"

#define TAMANHO 31

void formMaiusculo(char str[]){
    for(int i=0; str[i] != '\0' ;i++){
        str[i] = tolower(str[i]);
    }
}

int main(){
    char str[TAMANHO];

    printf("\nEscreva um texto para deixar todas as letras minúsculas ( MAX de %d caracteres ):\n", TAMANHO - 1);
    lerString(str, TAMANHO);

    formMaiusculo(str);

    printf("\n%s\n\n", str);
    
    return 0;
}