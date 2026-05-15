// Crie uma função que recebe uma string e um caractere, e retorne o número de vezes que esse
// caractere aparece na string.

#include <stdio.h>
#include "mylib.h"

#define TAMANHO 101

int contCaractere(char str[], char c){
    int i, cont = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == c) cont++;
    }
    return cont;
}

int main(){
    char texto[TAMANHO], c;

    printf("\n- Forneça um texto de no máximo %d caracteres:\n", TAMANHO -1);
    lerString(texto, TAMANHO);

    printf("\n- Forneça o caractere que deseja contar quantas vezes aparece no texto: ");
    scanf("%c", &c);

    printf("\nO caractere '%c' aparece %d vezes.\n\n", c, contCaractere(texto, c));

    return 0;
}