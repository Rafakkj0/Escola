// Implemente uma função que compare duas strings e retorne 0 se forem iguais, e 1 se forem
// diferentes.
// Obs.: não é permitido o uso de funções da biblioteca string.h

#include <stdio.h>
#include "mylib.h"
#define TAMANHO 10

int verificarIqualString(char str1[], char str2[]){
    int i;
    for(i=0;str1[i] != '\0' && str2[i] != '\0'; i++){
        if(str1[i] != str2[i]) return 1;
    }
    if(str1[i] != str2[i]) return 1;

    return 0;
}

int main(){
    char s1[TAMANHO], s2[TAMANHO];

    printf("\nEscreva sua senha: ");
    lerString(s1, TAMANHO);
    printf("Confirme a senha: ");
    lerString(s2, TAMANHO);

    if(verificarIqualString(s1, s2) == 0) printf("\nAs senhas são iguais!\n\n");
    else printf("\nAs senhas são diferentes.\n\n");

    return 0;
}